#include "lib/inc/updates.hpp"


static AttitudeEstimator e {0.5};
static PID rollPID {3, 1, 5, MAX_INT16 / 4, MAX_INT16};
static PID pitchPID {3, 1, 5, MAX_INT16 / 4, MAX_INT16};

#define ROLL_LIMIT ( 45 * DEG_TO_RAD )
#define PITCH_LIMIT ( 45 * DEG_TO_RAD )


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
	
	int16_t inRoll {receiver::getChannel(1)}, inPitch {receiver::getChannel(2)};
	int16_t outRoll, outPitch;


	if (receiver::getChannel(6) < 0) {
		outRoll = inRoll;
		outPitch = inPitch;
	} else {	
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
		
		outRoll = rollPID.update(inRoll / 4, e.getRoll() / PI * MAX_INT16);
		outPitch = pitchPID.update(inPitch / 4, e.getPitch() / PI * MAX_INT16);
	}
	
	servo::setChannel(1, outRoll);
	servo::setChannel(2, outPitch);

	pc::Command cmd {8, pc::SendAccData};
	util::copy((uint16_t*)cmd.data, (uint16_t)outRoll);
	util::copy((uint16_t*)cmd.data + 1, (uint16_t)outPitch);
	pc::sendCommand(cmd);
}


void updates::slow() {
	// Nothing to do here yet
}

