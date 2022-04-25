#include "lib/inc/mpu6050.hpp"


#define G ( 9.81 )

#define ACC_LSB ( 16384.0 )
#define ACC_FACTOR ( G / ACC_LSB )

#define GYRO_LSB ( 131.0 )
#define GYRO_FACTOR ( DEG_TO_RAD / GYRO_LSB )


#define MPU6050_ADDR ( 0x68 )


static int16_t rawAcc[3] {0};
static int16_t rawRot[3] {0};


void mpu6050::init() {
	uint8_t power1{0};
	i2c::writeRegister(MPU6050_ADDR, 0x6b, &power1, 1);
}


void mpu6050::update() {
	i2c::readRegister(MPU6050_ADDR, 0x3b, (uint8_t*) rawAcc, 6);
	i2c::readRegister(MPU6050_ADDR, 0x43, (uint8_t*) rawRot, 6);
}


float mpu6050::getAccX() {
	return util::switchEndianness(rawAcc[0]) * ACC_FACTOR;
}


float mpu6050::getAccY() {
	return util::switchEndianness(rawAcc[1]) * ACC_FACTOR;
}


float mpu6050::getAccZ() {
	return util::switchEndianness(rawAcc[2]) * ACC_FACTOR;
}


float mpu6050::getRotP() {
	return util::switchEndianness(rawRot[0]) * GYRO_FACTOR;
}


float mpu6050::getRotQ() {
	return util::switchEndianness(rawRot[1]) * GYRO_FACTOR;
}


float mpu6050::getRotR() {
	return util::switchEndianness(rawRot[2]) * GYRO_FACTOR;
}


const int16_t* mpu6050::getAcc() {
	return rawAcc;
}


const int16_t* mpu6050::getRot() {
	return rawRot;
}
