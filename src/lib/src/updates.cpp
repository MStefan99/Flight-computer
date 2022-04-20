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

	e.measure( {
		{mpu6050::getRotP()},
		{mpu6050::getRotP()},
		{mpu6050::getRotP()}
	},
	{
		{mpu6050::getAccX()},
		{mpu6050::getAccY()},
		{mpu6050::getAccZ()}
	},
	0.2);
	
	uint16_t roll = e.getRoll();
	uint16_t pitch = e.getPitch();

	pc::Command cmd {8, pc::SendAccData};
	memcpy(cmd.data, (uint8_t*)&roll, 2);
	memcpy(cmd.data + 2, (uint8_t*)&pitch, 2);
	pc::sendCommand(cmd);
}


void updates::slow() {
	// Nothing to do here yet
}

