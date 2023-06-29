#include "lib/inc/lsm6dso.hpp"

static constexpr uint8_t LSM6DSO_ADDR {0x6a};


static int16_t rawAcc[3] {0};
static int16_t rawRot[3] {0};
static float acc[3] {0};
static float rot[3] {0};


void lsm6dso::init() {
    uint8_t ctrl1_xl {0x30};
    uint8_t ctrl2_g {0x030};
    i2c::writeRegister(LSM6DSO_ADDR, 0x10, &ctrl1_xl);
    i2c::writeRegister(LSM6DSO_ADDR, 0x11, &ctrl2_g);
}


void lsm6dso::update() {
	i2c::readRegister(LSM6DSO_ADDR, 0x28, (uint8_t*) rawAcc, 6);
	i2c::readRegister(LSM6DSO_ADDR, 0x22, (uint8_t*) rawRot, 6, [](bool success) {
       for (uint8_t i {0}; i < 3; ++i) {
//            acc[i] = rawAcc[i] / 4096.0;
//            rot[i] = rawRot[i] * 65.0;
        } 
    });
}


const int16_t* lsm6dso::getRawAcc() {
	return rawAcc;
}


const int16_t* lsm6dso::getRawRot() {
	return rawRot;
}


const float* lsm6dso::getAcc() {
	return acc;
}


const float* lsm6dso::getRot() {
	return rot;
}
