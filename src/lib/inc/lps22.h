/* 
 * File:   lps22.h
 * Author: mikha
 *
 * Created on December 5, 2021, 1:12 PM
 */

#ifndef LPS22_H
#define	LPS22_H

#include "device.h"
#include "lib/inc/i2c.h"


namespace lps22 {
	// I2C needs to be initialized first
	void init();
	void update();
	
	uint32_t getStaticPressure();
	uint32_t getRamPressure();
}

#endif	/* LPS22_H */

