#include "lib/inc/updates.h"


static AttitudeEstimator e {0.5};
//static PID<float> rollPID {3, 0, 10};
static PID<float> pitchPID {3, 0, 20};


void updates::init() {
	e.init(0, 0);

	mpu6050::init();
	
	servo::init();
	servo::enable(0);
	PORT_REGS->GROUP[0].PORT_DIRSET = 1 << 1;
	//servo::enable(1);
}


void updates::ms() {
	// Nothing to do here yet
}


void updates::fast() {
	mpu6050::update();
	
	PORT_REGS->GROUP[0].PORT_OUTSET = 1 << 1;
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
	
	uint16_t roll = e.getRoll() / 3.14 * 16384;
	uint16_t pitch = e.getPitch() / 3.14 * 16384;
	
	//servo::setAngle(0, rollPID.update(0, roll));
	servo::setAngle(0, pitchPID.update(0, pitch));
	
	pc::Command cmd {8, pc::SendAccData};
	util::copy((uint16_t*)cmd.data, roll);
	util::copy((uint16_t*)cmd.data + 1, pitch);
	pc::sendCommand(cmd);
	PORT_REGS->GROUP[0].PORT_OUTCLR = 1 << 1;
}


void updates::slow() {
	// Nothing to do here yet
}

