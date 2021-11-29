#include "i2c.h"


//extern "C" {
//	void I2C_TCMPL_Handler() {
//		// Transaction complete, restart if needed
//	}
//}


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
	
	SERCOM0_REGS->I2CM.SERCOM_STATUS |= SERCOM_I2CM_STATUS_BUSSTATE(1);
	while (!(SERCOM0_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk));
}


void i2c::read(uint8_t devAdd, uint8_t regAdd, uint8_t size, uint8_t* buf) {
	uint8_t src {15};
	
	DMAC_DESCRIPTORS[DMA_CH_I2C_TX].DMAC_SRCADDR = (uint32_t) &src;
	DMAC_DESCRIPTORS[DMA_CH_I2C_TX].DMAC_DSTADDR = (uint32_t) buf;
	DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(1);
	
	SERCOM0_REGS->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(devAdd << 1u | 0x1)
					| SERCOM_I2CM_ADDR_LEN(size)
					| SERCOM_I2CM_ADDR_LENEN(1);
}


void i2c::write(uint8_t devAdd, uint8_t regAdd, uint8_t size, uint8_t* buf) {
	
}
