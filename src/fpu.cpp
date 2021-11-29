#include "device.h"

#include "lib/systick.h"
#include "lib/servo.h"
#include "lib/cpu.h"
#include "lib/i2c.h"
#include "config/default/peripheral/sercom/i2c_master/plib_sercom0_i2c_master.h"


/* Clock distribution
 * 
 * OSC16M @ 8MHz
 * |
 * |--> GCLK0 @ 8MHz 
 * |    |
 * |     `-> MCLK @ 8MHz
 * |
 *  `-> GCLK1 @ 62500Hz
 *      |
 *       `-> GCLK_TC0-2 @ 62500Hz
 */


int main() {
	// OSCCTRL config
	OSCCTRL_REGS->OSCCTRL_OSC16MCTRL = OSCCTRL_OSC16MCTRL_ENABLE(1) // Enable OSC16M
					| OSCCTRL_OSC16MCTRL_FSEL_8; // Set frequency to 8MHz

	// NVIC config
	__DMB();
	__enable_irq();
	NVIC_EnableIRQ(SysTick_IRQn);

	systick::init();
	servo::init();
	cpu::init();
	//i2c::init();
	for (uint8_t i{0}; i < 6; ++i) {
		servo::enable(i);
	}
	
	// GCLK config
	GCLK_REGS->GCLK_PCHCTRL[11] = GCLK_PCHCTRL_CHEN(1) // Enable SERCOM0 clock
					| GCLK_PCHCTRL_GEN_GCLK0; //Set GCLK0 as a clock source
	
	// PORT config
	PORT_REGS->GROUP[0].PORT_PINCFG[16] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin 16
	PORT_REGS->GROUP[0].PORT_PINCFG[17] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin 17
	PORT_REGS->GROUP[0].PORT_PMUX[8] = PORT_PMUX_PMUXE_D // Mux pin 16 to SERCOM0
					| PORT_PMUX_PMUXO_D; // Mux pin 17 to SERCOM0
	
	DMAC_REGS->DMAC_BASEADDR = (uint32_t) DMAC_DESCRIPTORS;
	DMAC_REGS->DMAC_WRBADDR = (uint32_t) _DMAC_WRITE_BACK_DESCRIPTORS;
	DMAC_REGS->DMAC_CTRL = DMAC_CTRL_LVLEN0(1)
					| DMAC_CTRL_DMAENABLE(1);
	
	DMAC_REGS->DMAC_CHID = 0;
	DMAC_REGS->DMAC_CHCTRLB = DMAC_CHCTRLB_TRIGACT_BLOCK;
	
	DMAC_REGS->DMAC_CHINTENSET = DMAC_CHINTENSET_TCMPL(1) | DMAC_CHINTENSET_TERR(1);
	NVIC_EnableIRQ(DMAC_0_IRQn);
	
	DMAC_DESCRIPTORS[DMA_CH_I2C_TX].DMAC_BTCTRL = DMAC_BTCTRL_BEATSIZE_BYTE
					| DMAC_BTCTRL_VALID(1);
	
	uint8_t src {5};
	uint8_t dst {};
	DMAC_DESCRIPTORS[DMA_CH_I2C_TX].DMAC_SRCADDR = (uint32_t) &src;
	DMAC_DESCRIPTORS[DMA_CH_I2C_TX].DMAC_DSTADDR = (uint32_t) &dst;
	DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(1);
	DMAC_REGS->DMAC_SWTRIGCTRL = 1;
	
	//i2c::read(0x19, 0x0f, 1, &data);

	// LED
	//PORT_REGS->GROUP[0].PORT_DIRSET = 0x1 << 8u;

	uint8_t angle {0};

	while (1) {
		for (uint8_t i{0}; i < 6; ++i) {
			servo::setAngle(i, ++angle);
		}

		systick::sleep(10);
	}

	return 1;
}


