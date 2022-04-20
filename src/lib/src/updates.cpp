#include "lib/inc/updates.h"


static AttitudeEstimator e {0.05};


void updates::init() {
	e.init(0, 0);

	mpu6050::init();
}


void updates::ms() {
	// Nothing to do here yet
}


void updates::fast() {
	mpu6050::update();

	pc::Command acc {8, pc::SendAccData};
	memcpy(acc.data, mpu6050::getAcc(), 6);
	pc::sendCommand(acc);

	pc::Command rot {8, pc::SendRotData};
	memcpy(rot.data, mpu6050::getRot(), 6);
	pc::sendCommand(rot);
}


void updates::slow() {
	// Nothing to do here yet
}

