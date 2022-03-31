#include "lib/inc/lps22.h"


#define LPS22_ADDR_INT 0x5c
#define LPS22_ADDR_EXT 0x5d


static uint32_t staticPressure
{
};
static uint32_t ramPressure{};


void lps22::init() {
	uint8_t ctrl1[2]{0x40};
	i2c::writeRegister(LPS22_ADDR_EXT, 0x10, ctrl1);
}


void lps22::update() {
	i2c::readRegister(LPS22_ADDR_EXT, 0xa8, (uint8_t*) & staticPressure, 3);
}


uint32_t lps22::getStaticPressure() {
	return staticPressure;
}


uint32_t lps22::getRamPressure() {
	return ramPressure;
}
