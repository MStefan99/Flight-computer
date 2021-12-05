/* 
 * File:   lsm303.h
 * Author: mikha
 *
 * Created on December 5, 2021, 10:04 PM
 */

#ifndef LSM303_H
#define	LSM303_H

#include "device.h"
#include "lib/inc/i2c.h"


namespace lsm303 {
	// I2C needs to be initialized first
	void init();
	void update();
	
	int16_t getAccelerationX();
	int16_t getAccelerationY();
	int16_t getAccelerationZ();
	
	int16_t getMagneticX();
	int16_t getMagneticY();
	int16_t getMagneticZ();
}


#endif	/* LSM303_H */

