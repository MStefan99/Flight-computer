#include "device.h"
//#include <xc.h>  // TODO: explore, possibly delete Harmony files

#include "lib/inc/system.h"
#include "lib/inc/servo.h"
#include "lib/inc/cpu.h"
#include "lib/inc/i2c.h"
#include "lib/inc/lps22.h"
#include "lib/inc/lsm303.h"
#include "lib/inc/updates.h"


int main() {
	system::init();
	servo::init();
	for (uint8_t i{0}; i < 4; ++i) {
		servo::enable(i);
	}

	cpu::init();
	i2c::init();
	lps22::init();
	lsm303::init();
	
	uint8_t buf[] = {0xa5, 0x0f, 0xf0, 0x5a, 0xe7, 0x7e};

	while (1) {
		system::sleep(1);
		
		i2c::startTransfer();
		cpu::startTransfer();
		
		millisecondUpdate();
		
		if (!(system::getTickCount() % 20)) {
			fastUpdate();
			lps22::update();
			lsm303::update();
			cpu::send(buf, 6);
		}
		
		if (!(system::getTickCount() % 1000)) {
			slowUpdate();
		}
	}

	return 1;
}
