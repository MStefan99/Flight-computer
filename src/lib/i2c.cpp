#include "i2c.h"


enum I2CTransferType {
	Read,
	Write,
	WriteRead
};


typedef struct __attribute__((packed)) {
	uint8_t devAddr;
	uint8_t regAddr;
	uint8_t* buf;
	uint8_t len;
	I2CTransferType type;
}
I2CTransfer;


static list<I2CTransfer> pendingTransfers;


static void streamOut(uint8_t devAddr, uint8_t* buf, uint8_t len);
static void streamIn(uint8_t devAddr, uint8_t* buf, uint8_t len);
static void endTransfer();


extern "C" {


	void I2C_Handler() {
		I2CTransfer transfer{pendingTransfers.front()};

		if (SERCOM0_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_ERROR_Msk ||
						(SERCOM0_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_RXNACK_Msk)) {
			DMAC_REGS->DMAC_CHID = transfer.type == I2CTransferType::Read ? DMA_CH_I2C_RX : DMA_CH_I2C_TX;
			SERCOM0_REGS->I2CM.SERCOM_CTRLB = SERCOM_I2CM_CTRLB_CMD(3);
			DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(0);
			endTransfer();
		} else {
			static bool regAddrWritten{false};

			if (!regAddrWritten) {
				SERCOM0_REGS->I2CM.SERCOM_DATA = transfer.regAddr;
				regAddrWritten = true;
			} else {
				streamIn(transfer.devAddr, transfer.buf, transfer.len);
				SERCOM0_REGS->I2CM.SERCOM_INTENCLR = SERCOM_I2CM_INTENSET_MB(1);
				regAddrWritten = false;
			}
		}

		SERCOM0_REGS->I2CM.SERCOM_INTFLAG = SERCOM_I2CM_INTFLAG_Msk;
	}
}


void dma::I2C_TCMPL_Handler() {
	endTransfer();
}


static void endTransfer() {
	I2CTransfer transfer{pendingTransfers.front()};
	if (transfer.type != I2CTransferType::Read) {
		delete[](transfer.buf);
	}
	pendingTransfers.pop_front();
}


void i2c::init() { // GCLK config
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
	SERCOM0_REGS->I2CM.SERCOM_BAUD = 33;
	SERCOM0_REGS->I2CM.SERCOM_CTRLA |= SERCOM_I2CM_CTRLA_ENABLE(1);
	SERCOM0_REGS->I2CM.SERCOM_INTENSET = SERCOM_I2CM_INTENSET_ERROR(1);
	NVIC_EnableIRQ(SERCOM0_0_IRQn);
	NVIC_EnableIRQ(SERCOM0_OTHER_IRQn);

	SERCOM0_REGS->I2CM.SERCOM_STATUS |= SERCOM_I2CM_STATUS_BUSSTATE(1);
	while (!(SERCOM0_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk));
}


void i2c::write(uint8_t devAddr, uint8_t* buf, uint8_t size) {
	uint8_t* txBuf = new uint8_t[size];
	memcpy(txBuf, buf, size);

	pendingTransfers.push_back(I2CTransfer{
		.devAddr = devAddr,
		.buf = txBuf,
		.len = size,
		.type = I2CTransferType::Write
	});
}


void i2c::read(uint8_t devAddr, uint8_t* buf, uint8_t size) {
	pendingTransfers.push_back(I2CTransfer{
		.devAddr = devAddr,
		.buf = buf,
		.len = size,
		.type = I2CTransferType::Read
	});
}


void i2c::writeRegister(uint8_t devAddr, uint8_t regAddr, uint8_t* buf, uint8_t size) {
	uint8_t* txBuf = new uint8_t[size + 1];
	txBuf[0] = regAddr;
	memcpy(txBuf + 1, buf, size);

	pendingTransfers.push_back(I2CTransfer{
		.devAddr = devAddr,
		.regAddr = regAddr,
		.buf = txBuf,
		.len = (uint8_t)(size + 1),
		.type = I2CTransferType::Write
	});
}


void i2c::readRegister(uint8_t devAddr, uint8_t regAddr, uint8_t* buf, uint8_t size) {
	pendingTransfers.push_back(I2CTransfer{
		.devAddr = devAddr,
		.regAddr = regAddr,
		.buf = buf,
		.len = size,
		.type = I2CTransferType::WriteRead
	});
}


static void streamOut(uint8_t devAddr, uint8_t* buf, uint8_t len) {
	DMAC_REGS->DMAC_CHID = DMA_CH_I2C_TX;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_TX].DMAC_BTCNT = len;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_TX].DMAC_SRCADDR = (uint32_t)(buf + len);
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_TX].DMAC_DSTADDR = (uint32_t) & SERCOM0_REGS->I2CM.SERCOM_DATA;
	DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(1);

	SERCOM0_REGS->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(devAddr << 1u)
					| SERCOM_I2CM_ADDR_LEN(len)
					| SERCOM_I2CM_ADDR_LENEN(1);
}


static void streamIn(uint8_t devAddr, uint8_t* buf, uint8_t len) {
	DMAC_REGS->DMAC_CHID = DMA_CH_I2C_RX;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_RX].DMAC_BTCNT = len;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_RX].DMAC_SRCADDR = (uint32_t) & SERCOM0_REGS->I2CM.SERCOM_DATA;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_RX].DMAC_DSTADDR = (uint32_t)(buf + len);
	DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(1);

	SERCOM0_REGS->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(devAddr << 1u | 0x1)
					| SERCOM_I2CM_ADDR_LEN(len)
					| SERCOM_I2CM_ADDR_LENEN(1);
}


void i2c::startTransfer() {
	if ((SERCOM0_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk) != SERCOM_I2CM_STATUS_BUSSTATE(1)
					|| DMAC_REGS->DMAC_ACTIVE & DMAC_ACTIVE_ABUSY_Msk) {
		return; // SERCOM/DMA busy, cannot start another transfer
	} else if (pendingTransfers.empty()) {
		return; // No pending transfer
	}

	I2CTransfer transfer{pendingTransfers.front()};

	switch (transfer.type) {
		case I2CTransferType::Read:
			streamIn(transfer.devAddr, transfer.buf, transfer.len);
			break;
		case I2CTransferType::Write:
			streamOut(transfer.devAddr, transfer.buf, transfer.len);
			break;
		case I2CTransferType::WriteRead:
			SERCOM0_REGS->I2CM.SERCOM_INTENSET = SERCOM_I2CM_INTENSET_MB(1);
			SERCOM0_REGS->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(transfer.devAddr << 1u);
			break;
	}
}
