#include "device.h"

#include "lib/inc/systick.h"
#include "lib/inc/servo.h"
#include "lib/inc/cpu.h"
#include "lib/inc/i2c.h"
#include "lib/inc/lps22.h"
#include "lib/inc/lsm303.h"


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


int main() {
	// OSCCTRL config
	OSCCTRL_REGS->OSCCTRL_OSC16MCTRL = OSCCTRL_OSC16MCTRL_ENABLE(1) // Enable OSC16M
					| OSCCTRL_OSC16MCTRL_FSEL_8; // Set frequency to 8MHz
	OSC32KCTRL_REGS->OSC32KCTRL_OSCULP32K = OSC32KCTRL_OSCULP32K_CALIB(15)
					| OSC32KCTRL_OSCULP32K_ULP32KSW(0);

	// NVIC config
	__DMB();
	__enable_irq();

	systick::init();
	servo::init();
	cpu::init();
	i2c::init();
	lps22::init();
	lsm303::init();
	for (uint8_t i{0}; i < 6; ++i) {
		servo::enable(i);
	}

	// LED
	//PORT_REGS->GROUP[0].PORT_DIRSET = 0x1 << 8u;
	lps22::update();
	lsm303::update();

	while (1) {
		i2c::startTransfer();
		systick::sleep(1);
	}

	return 1;
}
