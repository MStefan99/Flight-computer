/* 
 * File:   i2c.h
 * Author: mikha
 *
 * Created on November 23, 2021, 5:12 PM
 */

#ifndef I2C_H
#define	I2C_H


#include "device.h"
#include "lib/dma.h"


namespace i2c {
	void init();
	void read(uint8_t devAdd, uint8_t regAdd, uint8_t size, uint8_t* buf);
	void write(uint8_t devAdd, uint8_t regAdd, uint8_t size, uint8_t* buf);
}


#endif	/* I2C_H */

