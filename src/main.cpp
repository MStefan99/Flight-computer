#include "device.h"
//#include <xc.h>  // TODO: explore, possibly delete Harmony files

#include "lib/inc/util.h"
#include "lib/inc/updates.h"
#include "lib/inc/servo.h"
#include "lib/inc/pc.h"
#include "lib/inc/i2c.h"


int main() {
	util::init();
	servo::init();
	updates::init();
	
	for (uint8_t i{0}; i < 4; ++i) {
		servo::enable(i);
	}

	pc::init();
	i2c::init();

	while (1) {
		util::sleep(1);

		updates::ms();

		if (!(util::getTickCount() % 20)) {
			updates::fast();
		}

		if (!(util::getTickCount() % 1000)) {
			updates::slow();
		}
	}

	return 1;
}
