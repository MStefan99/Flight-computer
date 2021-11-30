#include "i2c.h"


typedef struct __attribute__((packed)) {
	uint8_t devAddr;
	uint8_t regAddr;
	uint8_t* buf;
	uint8_t len;
	bool read;
	bool stream;
}
I2CTransfer;


static std::list<I2CTransfer> pendingTransfers;  // TODO: replace


static void startTransfer();
static void startStreamingIn(uint8_t devAddr, uint8_t* buf, uint8_t size);


extern "C" {


	void I2C_MB_Handler() {
		static bool regAddrWritten{false};
		I2CTransfer transfer{pendingTransfers.front()};

		if (!regAddrWritten) {
			SERCOM0_REGS->I2CM.SERCOM_DATA = transfer.regAddr;
			regAddrWritten = true;
		} else {
			startStreamingIn(transfer.devAddr, transfer.buf, transfer.len);
			SERCOM0_REGS->I2CM.SERCOM_INTENCLR = SERCOM_I2CM_INTENCLR_MB(1);
			regAddrWritten = false;
		}
		SERCOM0_REGS->I2CM.SERCOM_INTFLAG = SERCOM_I2CM_INTFLAG_MB(1);
	}


	void I2C_TCMPL_Handler() {
		pendingTransfers.pop_front();
		while ((SERCOM0_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk) != SERCOM_I2CM_STATUS_BUSSTATE(1));
		startTransfer();
		DMAC_REGS->DMAC_CHINTFLAG = 0xff;
	}
}


void i2c::init() {
	// GCLK config
	GCLK_REGS->GCLK_PCHCTRL[11] = GCLK_PCHCTRL_CHEN(1) // Enable SERCOM0 clock
					| GCLK_PCHCTRL_GEN_GCLK0; //Set GCLK0 as a clock source

	// PORT config
	PORT_REGS->GROUP[0].PORT_PINCFG[16] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin 16
	PORT_REGS->GROUP[0].PORT_PINCFG[17] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin 17
	PORT_REGS->GROUP[0].PORT_PMUX[8] = PORT_PMUX_PMUXE_D // Mux pin 16 to SERCOM0
					| PORT_PMUX_PMUXO_D; // Mux pin 17 to SERCOM0

	// DMA config
	dma::initI2C();
	SERCOM0_REGS->I2CM.SERCOM_CTRLB = SERCOM_I2CM_CTRLB_SMEN(1);

	// SERCOM config
	SERCOM0_REGS->I2CM.SERCOM_CTRLA = SERCOM_I2CM_CTRLA_LOWTOUTEN(1)
					| SERCOM_I2CM_CTRLA_SPEED_STANDARD_AND_FAST_MODE
					| SERCOM_I2CM_CTRLA_PINOUT(0)
					| SERCOM_I2CM_CTRLA_MODE_I2C_MASTER;
	SERCOM0_REGS->I2CM.SERCOM_BAUD = 39;
	SERCOM0_REGS->I2CM.SERCOM_CTRLA |= SERCOM_I2CM_CTRLA_ENABLE(1);
	NVIC_EnableIRQ(SERCOM0_0_IRQn);

	SERCOM0_REGS->I2CM.SERCOM_STATUS |= SERCOM_I2CM_STATUS_BUSSTATE(1);
	while (!(SERCOM0_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk));
}


void i2c::streamOut(uint8_t devAddr, uint8_t* buf, uint8_t size) {
	pendingTransfers.push_back(I2CTransfer{
		.devAddr = devAddr,
		.buf = buf,
		.len = size,
		.read = false,
		.stream = true
	});
	startTransfer();
}


void i2c::streamIn(uint8_t devAddr, uint8_t* buf, uint8_t size) {
	pendingTransfers.push_back(I2CTransfer{
		.devAddr = devAddr,
		.buf = buf,
		.len = size,
		.read = true,
		.stream = true
	});
	startTransfer();
}


void i2c::writeRegister(uint8_t devAddr, uint8_t regAddr, uint8_t* buf, uint8_t size) {
	for (uint8_t i{size}; i > 0; --i) {
	buf[size] = buf[size - 1];
}
	buf[0] = regAddr;

	pendingTransfers.push_back(I2CTransfer{
		.devAddr = devAddr,
		.regAddr = regAddr,
		.buf = buf,
		.len = (uint8_t)(size + 1),
		.read = false,
		.stream = true
	});
	startTransfer();
}


void i2c::readRegister(uint8_t devAddr, uint8_t regAddr, uint8_t* buf, uint8_t size) {
	pendingTransfers.push_back(I2CTransfer{
		.devAddr = devAddr,
		.regAddr = regAddr,
		.buf = buf,
		.len = size,
		.read = true,
		.stream = false
	});
	startTransfer();
}


static void startStreamingIn(uint8_t devAddr, uint8_t* buf, uint8_t size) {
	DMAC_REGS->DMAC_CHID = DMA_CH_I2C_RX;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_RX].DMAC_BTCNT = size;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_RX].DMAC_SRCADDR = (uint32_t) & SERCOM0_REGS->I2CM.SERCOM_DATA;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_RX].DMAC_DSTADDR = (uint32_t)(buf + size);
	DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(1);

	SERCOM0_REGS->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(devAddr << 1u | 0x1)
					| SERCOM_I2CM_ADDR_LEN(size)
					| SERCOM_I2CM_ADDR_LENEN(1);
}


static void startTransfer() {
	if ((SERCOM0_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk) != SERCOM_I2CM_STATUS_BUSSTATE(1)) {
		return; // SERCOM not idle, cannot start transaction
	} else if (pendingTransfers.empty()) {
		return; // No pending transactions
	}

	I2CTransfer transfer{pendingTransfers.front()};
	if (transfer.stream) {
		if (transfer.read) {
			startStreamingIn(transfer.devAddr, transfer.buf, transfer.len);
		} else {
			DMAC_REGS->DMAC_CHID = DMA_CH_I2C_TX;
			dma::DESCRIPTOR_TABLE[DMA_CH_I2C_TX].DMAC_BTCNT = transfer.len;
			dma::DESCRIPTOR_TABLE[DMA_CH_I2C_TX].DMAC_SRCADDR = (uint32_t)(transfer.buf + transfer.len);
			dma::DESCRIPTOR_TABLE[DMA_CH_I2C_TX].DMAC_DSTADDR = (uint32_t) & SERCOM0_REGS->I2CM.SERCOM_DATA;
			DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(1);

			SERCOM0_REGS->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(transfer.devAddr << 1u)
							| SERCOM_I2CM_ADDR_LEN(transfer.len)
							| SERCOM_I2CM_ADDR_LENEN(1);
		}
	} else {
		if (transfer.read) {
			SERCOM0_REGS->I2CM.SERCOM_INTENSET = SERCOM_I2CM_INTENSET_MB(1);
			SERCOM0_REGS->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(transfer.devAddr << 1u);
		} else {
			SERCOM0_REGS->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(transfer.devAddr << 1u);
		}
	}
}
