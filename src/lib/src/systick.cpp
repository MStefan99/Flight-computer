#include "lib/inc/systick.h"


static uint32_t ticks {0};


extern "C" {


	void SysTick_Handler() {
		++ticks;
	}
}


void systick::init() {
	SysTick->CTRL = 0;
	SysTick->LOAD = 8000 - 1;
	SysTick->CTRL = SysTick_CTRL_TICKINT_Msk
					| SysTick_CTRL_CLKSOURCE_Msk
					| SysTick_CTRL_ENABLE_Msk;
	NVIC_EnableIRQ(SysTick_IRQn);
}


uint32_t systick::getTickCount() {
	return ticks;
}


void systick::sleep(uint32_t ms) {
	uint32_t t {ticks + ms};
	
	while (ticks < t) {
		__WFI();
	}
}

