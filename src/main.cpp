#include "device.h"

#include "lib/systick.h"


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

	// GLCK config
	GCLK_REGS->GCLK_GENCTRL[1] = GCLK_GENCTRL_GENEN(1) // Enable GCLK 1
					| GCLK_GENCTRL_SRC_OSC16M // Set OSC16M as a source
					| GCLK_GENCTRL_DIVSEL_DIV2 // Set division mode (2^(x+1))
					| GCLK_GENCTRL_DIV(6); // Divide by 128 (2^(6+1))
	GCLK_REGS->GCLK_PCHCTRL[14] = GCLK_PCHCTRL_CHEN(1) // Enable TC0-1 clock
					| GCLK_PCHCTRL_GEN_GCLK1; //Set GCLK1 as a clock source
	//GCLK_REGS->GCLK_PCHCTRL[15] = GCLK_PCHCTRL_CHEN(1) // Enable TC2 clock
	//				| GCLK_PCHCTRL_GEN_GCLK1; //Set GCLK1 as a clock source

	// NVIC config
	__DMB();
	__enable_irq();
	NVIC_EnableIRQ(SysTick_IRQn);

	// PORT config
	PORT_REGS->GROUP[0].PORT_PINCFG[4] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin 4
	PORT_REGS->GROUP[0].PORT_PINCFG[5] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin 5
	PORT_REGS->GROUP[0].PORT_PMUX[2] = PORT_PMUX_PMUXE_E // Mux pin 4 to TC0
					| PORT_PMUX_PMUXO_E; // Mux pin 5 to TC0

	// TC0 config
	TC0_REGS->COUNT16.TC_CTRLA = TC_CTRLA_MODE_COUNT16;
	TC0_REGS->COUNT16.TC_DBGCTRL = TC_DBGCTRL_DBGRUN(1);
	TC0_REGS->COUNT16.TC_WAVE = TC_WAVE_WAVEGEN_NPWM;
	TC0_REGS->COUNT16.TC_PER = 1250;
	TC0_REGS->COUNT16.TC_CC[0] = 64;
	TC0_REGS->COUNT16.TC_CC[1] = 96;
	TC0_REGS->COUNT16.TC_CTRLA |= TC_CTRLA_ENABLE(1);
	
	systick::init();

	// LED
	PORT_REGS->GROUP[0].PORT_DIRSET = 0x1 << 8u;
	
	int8_t dir {1};

	while (1) {
		PORT_REGS->GROUP[0].PORT_OUTTGL = 0x1 << 8u;
		
		if (TC0_REGS->COUNT16.TC_CC[0] > 128) {
			dir = -1;
		} else if (TC0_REGS->COUNT16.TC_CC[0] < 64) {
			dir = 1;
		}
		TC0_REGS->COUNT16.TC_CC[0] += dir;
		
		systick::sleep(10);
	}

	return 1;
}


