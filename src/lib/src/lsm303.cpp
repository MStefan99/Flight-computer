#include "lib/inc/lsm303.h"


#define LSM303_ADDR_ACC 0x19
#define LSM303_ADDR_MAG 0x1d


static uint8_t accBuf[6];
static uint8_t magBuf[6];

static int16_t accDataFiltered[3] {0};


void lsm303::init() {
	uint8_t ctrl_reg1{0x47};
	i2c::writeRegister(LSM303_ADDR_ACC, 0x20, &ctrl_reg1);
}


void lsm303::update() {
	for (uint8_t i{0}; i < 3; ++i) {
		accDataFiltered[i] += (((int16_t)(accBuf[i * 2] | accBuf[i * 2 + 1] << 8u) >> 4u) - accDataFiltered[i]) / 8;
	}
	i2c::readRegister(LSM303_ADDR_ACC, 0xa8, accBuf, 6);
}


int16_t lsm303::getAccelerationX() {
	return accDataFiltered[0];
}


int16_t lsm303::getAccelerationY() {
	return accDataFiltered[1];
}


int16_t lsm303::getAccelerationZ() {
	return accDataFiltered[2];
}
