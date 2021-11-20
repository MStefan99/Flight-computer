#include "device.h"

#include "lib/systick.h"
#include "lib/servo.h"


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
	for (uint8_t i{0}; i < 6; ++i) {
		servo::enable(i);
	}

	// LED
	PORT_REGS->GROUP[0].PORT_DIRSET = 0x1 << 8u;

	uint8_t angle {0};

	while (1) {
		for (uint8_t i{0}; i < 6; ++i) {
			servo::setAngle(i, ++angle);
		}

		systick::sleep(10);
	}

	return 1;
}


