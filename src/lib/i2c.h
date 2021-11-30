/* 
 * File:   i2c.h
 * Author: mikha
 *
 * Created on November 23, 2021, 5:12 PM
 */

#ifndef I2C_H
#define	I2C_H


#include "device.h"
#include "lib/RingBuffer.h"
#include "lib/dma.h"


namespace i2c {
	void init();
	
	void streamOut(uint8_t devAddr, uint8_t* buf, uint8_t size = 1);
	void streamIn(uint8_t devAddr, uint8_t* buf, uint8_t size = 1);
	
	void writeRegister(uint8_t devAddr, uint8_t regAddr, uint8_t* buf, uint8_t size = 1);
	void readRegister(uint8_t devAddr, uint8_t regAddr, uint8_t* buf, uint8_t size = 1);
	
	// Note: The buffer for the writeRegister should contain one extra byte for the register address
	
	// If queue is used, startTransfer should be polled at regular intervals
	void startTransfer();
}


#endif	/* I2C_H */

