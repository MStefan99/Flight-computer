/* 
 * File:   mpu6050.h
 * Author: MStefan99
 *
 * Created on March 24, 2022, 7:44 PM
 */

#ifndef MPU6050_H
#define	MPU6050_H

#include "device.h"
#include "lib/inc/i2c.h"


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
}

#endif	/* MPU6050_H */

