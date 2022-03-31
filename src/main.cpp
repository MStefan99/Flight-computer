#include <cstring>
#include "device.h"
//#include <xc.h>  // TODO: explore, possibly delete Harmony files

#include "lib/inc/system.h"
#include "lib/inc/updates.h"
#include "lib/inc/servo.h"
#include "lib/inc/pc.h"
#include "lib/inc/i2c.h"
#include "lib/inc/lps22.h"
#include "lib/inc/lsm303.h"
#include "lib/inc/mpu6050.h"


int main() {
	system::init();
	servo::init();
	for (uint8_t i{0}; i < 4; ++i) {
	servo::enable(i);
}

	pc::init();
	i2c::init();
	mpu6050::init();

	while (1) {
		system::sleep(1);

		millisecondUpdate();

		if (!(system::getTickCount() % 20)) {
			fastUpdate();
			
			mpu6050::update();
			
			pc::Command acc{8, pc::SendAccData};
			memcpy(acc.data, mpu6050::getAcc(), 6);
			pc::sendCommand(acc);
			
			pc::Command rot{8, pc::SendRotData};
			memcpy(rot.data, mpu6050::getRot(), 6);
			pc::sendCommand(rot);
		}

		if (!(system::getTickCount() % 1000)) {
			slowUpdate();
		}
	}

	return 1;
}
