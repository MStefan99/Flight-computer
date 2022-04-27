#include "lib/inc/updates.hpp"


static AttitudeEstimator e {0.5};
static PID<float> rollPID {3, 0, 10};
static PID<float> pitchPID {3, 0, 10};


void updates::init() {
	e.init(0, 0);

	mpu6050::init();
	
	servo::init();
	servo::enable(1);
	servo::enable(2);
	
	receiver::initSBUS();
}


void updates::ms() {
	// Nothing to do here yet
}


void updates::fast() {
	mpu6050::update();

	e.measure({
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

	int16_t roll = e.getRoll() / PI * (int16_t)0x7fff;
	int16_t pitch = e.getPitch() / PI * (int16_t)0x7fff;

	if (receiver::getChannel(6) < 0) {
		servo::setChannel(1, receiver::getChannel(1));
		servo::setChannel(2, receiver::getChannel(2));
	} else {	
		servo::setChannel(1, rollPID.update(0, roll));
		servo::setChannel(2, pitchPID.update(0, pitch));	
	}

	pc::Command cmd {8, pc::SendAccData};
	util::copy((uint16_t*)cmd.data, (uint16_t)roll);
	util::copy((uint16_t*)cmd.data + 1, (uint16_t)pitch);
	pc::sendCommand(cmd);
}


void updates::slow() {
	// Nothing to do here yet
}

