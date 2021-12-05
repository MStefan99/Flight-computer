#include "device.h"

#include "lib/systick.h"
#include "lib/servo.h"
#include "lib/cpu.h"
#include "lib/i2c.h"
#include "lib/lps22.h"


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

	systick::init();
	servo::init();
	cpu::init();
	i2c::init();
	//lps22::init();
	for (uint8_t i{0}; i < 6; ++i) {
		servo::enable(i);
	}
	
	systick::sleep(5);
	uint8_t buf[3] = {0};
	i2c::write(0x48, buf, 3);  //ok
	i2c::write(0x58, buf, 3);  // ok
	
	i2c::read(0x48, buf, 3);  //ok
	i2c::read(0x58, buf, 3); //ok
	
	i2c::writeRegister(0x48, 0x1, buf);
	i2c::writeRegister(0x58, 0x1, buf);
	
	i2c::readRegister(0x48, 0x0, buf, 3);
	i2c::readRegister(0x58, 0x0, buf, 3);
	//lps22::update();

	// LED
	//PORT_REGS->GROUP[0].PORT_DIRSET = 0x1 << 8u;

	while (1) {
		i2c::startTransfer();
		systick::sleep(1);
	}

	return 1;
}
