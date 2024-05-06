/* 
 * File:   receiver.h
 * Author: mikha
 *
 * Created on December 7, 2021, 12:34 PM
 */

#ifndef SBUS_H
#define	SBUS_H

#include "device.h"

#include "util.hpp"
#include "dma.hpp"


namespace sbus {
	void init();

    bool available();
	int16_t getChannel(uint8_t channel);  // Channels start from 0
    bool frameLost();
    bool failsafeActive();
}

#endif	/* SBUS_H */

