#include "lib/inc/mpu6050.h"


#define MPU6050_ADDR 0x68


static int16_t buf[6]{0};


void mpu6050::init() {
	uint8_t power1{0};
	i2c::writeRegister(MPU6050_ADDR, 0x6b, &power1, 1);
}


void mpu6050::update() {
	i2c::readRegister(MPU6050_ADDR, 0x3b, (uint8_t*) buf, 6);
}


const int16_t* mpu6050::getAcc() {
	return buf;
}
