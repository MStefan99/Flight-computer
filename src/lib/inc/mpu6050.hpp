/* 
 * File:   mpu6050.h
 * Author: MStefan99
 *
 * Created on March 24, 2022, 7:44 PM
 */

#ifndef MPU6050_H
#define	MPU6050_H

#include "device.h"

#include "util.hpp"
#include "lib/inc/i2c.hpp"


namespace mpu6050 {
	// I2C needs to be initialized first
	void init();
	void update();

	float getAccX();
	float getAccY();
	float getAccZ();

	float getRotP();
	float getRotQ();
	float getRotR();
	
	// Temporary, to be removed
	const int16_t* getAcc();
	const int16_t* getRot();
}

#endif	/* MPU6050_H */

