#include "lib/inc/updates.hpp"


static AttitudeEstimator e {0.5};
static PID<float> rollPID {3, 0, 10};
static PID<float> pitchPID {3, 0, 10};


void updates::init() {
	e.init(0, 0);

	mpu6050::init();
	
	servo::init();
	servo::enable(0);
	servo::enable(1);
	
	receiver::initSBUS();
}


void updates::ms() {
	// Nothing to do here yet
}


void updates::fast() {
	mpu6050::update();
	
	if (receiver::getChannel(6) > 0) {
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

		int16_t roll = e.getRoll() / 3.14 * 16384;
		int16_t pitch = e.getPitch() / 3.14 * 16384;

		servo::setChannel(0, rollPID.update(0, roll));
		servo::setChannel(1, pitchPID.update(0, pitch));
		
	} else {	
		servo::setChannel(0, receiver::getChannel(0));
		servo::setChannel(1, receiver::getChannel(1));
	}
	
	int16_t ch0 = receiver::getChannel(0);
	int16_t ch1 = receiver::getChannel(1);
	int16_t ch3 = receiver::getChannel(6);

	pc::Command cmd {8, pc::SendAccData};
	util::copy((uint16_t*)cmd.data, (uint16_t)ch0);
	util::copy((uint16_t*)cmd.data + 1, (uint16_t)ch1);
	util::copy((uint16_t*)cmd.data + 2, (uint16_t)ch3);
	pc::sendCommand(cmd);
}


void updates::slow() {
	// Nothing to do here yet
}

