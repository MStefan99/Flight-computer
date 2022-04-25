#include "lib/inc/util.h"


static uint32_t ticks
{
	0
};


extern "C" {


	void SysTick_Handler() {
		++ticks;
	}
}


void util::init() { // TODO: move away
	/* Clock distribution
	 * 
	 * OSC16M @ 8MHz
	 * |
	 *  `-> GCLK0 @ 8MHz 
	 *      |
	 *       `-> MCLK @ 8MHz
	 *
	 * OSCULP32K @ 32768Hz
	 * |
	 *  `-> GCLK1 @ 32768Hz
	 *      |
	 *       `-> GCLK_TC0-2 @ 32768Hz
	 */
	
	// OSCCTRL config
	OSCCTRL_REGS->OSCCTRL_OSC16MCTRL = OSCCTRL_OSC16MCTRL_ENABLE(1) // Enable OSC16M
					| OSCCTRL_OSC16MCTRL_FSEL_8; // Set frequency to 8MHz
	OSC32KCTRL_REGS->OSC32KCTRL_OSCULP32K = OSC32KCTRL_OSCULP32K_CALIB(15)
					| OSC32KCTRL_OSCULP32K_ULP32KSW(0);

	// NVIC config
	__DMB();
	__enable_irq();

	// SysTick config
	SysTick->CTRL = 0;
	SysTick->LOAD = 8000 - 1;
	SysTick->CTRL = SysTick_CTRL_TICKINT_Msk
					| SysTick_CTRL_CLKSOURCE_Msk
					| SysTick_CTRL_ENABLE_Msk;
	NVIC_EnableIRQ(SysTick_IRQn);
}


uint32_t util::getTickCount() {
	return ticks;
}


void util::sleep(uint32_t ms) {
	uint32_t t{ticks + ms};

	while (ticks < t) {
		__WFI();
	}
}
