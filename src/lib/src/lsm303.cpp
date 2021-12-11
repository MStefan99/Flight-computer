#include "lib/inc/lsm303.h"


#define LSM303_ADDR_ACC 0x19
#define LSM303_ADDR_MAG 0x1d


static uint8_t accData[6];
static uint8_t magData[6];


void lsm303::init() {
	uint8_t ctrl_reg1 {0x47};
	i2c::writeRegister(LSM303_ADDR_ACC, 0x20, &ctrl_reg1);
}


void lsm303::update() {
	i2c::readRegister(LSM303_ADDR_ACC, 0xa8, accData, 6);
}


int16_t lsm303::getAccelerationX() {
	return (int16_t)(accData[0] | accData[1] << 8u) >> 4u;
}


int16_t lsm303::getAccelerationY() {
	return (int16_t)(accData[2] | accData[3] << 8u) >> 4u;
}


int16_t lsm303::getAccelerationZ() {
	return (int16_t)(accData[4] | accData[5] << 8u) >> 4u;
}
