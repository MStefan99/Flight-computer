#include "lib/inc/updates.h"


static AttitudeEstimator e {0.5};


void updates::init() {
	e.init(0, 0);

	mpu6050::init();
}


void updates::ms() {
	// Nothing to do here yet
}


void updates::fast() {
	mpu6050::update();
	
	e.measure( {
		{mpu6050::getRotP()},
		{mpu6050::getRotQ()},
		{mpu6050::getRotR()}
	},
	{
		{mpu6050::getAccX()},
		{mpu6050::getAccY()},
		{mpu6050::getAccZ()}
	},
	0.02);
	
	uint16_t roll = e.getRoll() / 3.14 * 16384;
	uint16_t pitch = e.getPitch() / 3.14 * 16384;
	
	pc::Command cmd {8, pc::SendAccData};
	util::copy((uint16_t*)cmd.data, roll);
	util::copy((uint16_t*)cmd.data + 1, pitch);
	pc::sendCommand(cmd);
}


void updates::slow() {
	// Nothing to do here yet
}

