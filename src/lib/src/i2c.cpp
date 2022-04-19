#include "lib/inc/i2c.h"

#define SERCOM_REGS SERCOM0_REGS


static tl::allocator<uint8_t> byteAllocator {};


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
	SERCOM_REGS->I2CM.SERCOM_CTRLB = SERCOM_I2CM_CTRLB_SMEN(1);

	// SERCOM config
	SERCOM_REGS->I2CM.SERCOM_BAUD = 9; // 400KHz
	SERCOM_REGS->I2CM.SERCOM_CTRLA = SERCOM_I2CM_CTRLA_LOWTOUTEN(1)
					| SERCOM_I2CM_CTRLA_SPEED_STANDARD_AND_FAST_MODE
					| SERCOM_I2CM_CTRLA_PINOUT(0)
					| SERCOM_I2CM_CTRLA_MODE_I2C_MASTER
					| SERCOM_I2CM_CTRLA_ENABLE(1);
	SERCOM_REGS->I2CM.SERCOM_INTENSET = SERCOM_I2CM_INTENSET_ERROR(1);
	NVIC_EnableIRQ(SERCOM0_0_IRQn);
	NVIC_EnableIRQ(SERCOM0_OTHER_IRQn);

	SERCOM_REGS->I2CM.SERCOM_STATUS |= SERCOM_I2CM_STATUS_BUSSTATE(1);
	while (!(SERCOM_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk));
}


void i2c::write(uint8_t devAddr, uint8_t* buf, uint8_t size) {
	uint8_t* txBuf = byteAllocator.allocate(size);
	memcpy(txBuf, buf, size);

	dma::startTransfer(dma::I2CTransfer{
		.devAddr = devAddr,
		.buf = txBuf,
		.len = size,
		.type = dma::I2CTransferType::Write,
		.sercom = SERCOM_REGS
	});
}


void i2c::read(uint8_t devAddr, uint8_t* buf, uint8_t size) {
	dma::startTransfer(dma::I2CTransfer{
		.devAddr = devAddr,
		.buf = buf,
		.len = size,
		.type = dma::I2CTransferType::Read,
		.sercom = SERCOM_REGS
	});
}


void i2c::writeRegister(uint8_t devAddr, uint8_t regAddr, uint8_t* buf, uint8_t size) {
	uint8_t* txBuf = byteAllocator.allocate(size + 1);
	txBuf[0] = regAddr;
	memcpy(txBuf + 1, buf, size);

	dma::startTransfer(dma::I2CTransfer{
		.devAddr = devAddr,
		.regAddr = regAddr,
		.buf = txBuf,
		.len = (uint8_t) (size + 1),
		.type = dma::I2CTransferType::Write,
		.sercom = SERCOM_REGS
	});
}


void i2c::readRegister(uint8_t devAddr, uint8_t regAddr, uint8_t* buf, uint8_t size) {
	dma::startTransfer(dma::I2CTransfer{
		.devAddr = devAddr,
		.regAddr = regAddr,
		.buf = buf,
		.len = size,
		.type = dma::I2CTransferType::WriteRead,
		.sercom = SERCOM_REGS
	});
}
