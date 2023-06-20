/* 
 * File:   receiver.h
 * Author: mikha
 *
 * Created on December 7, 2021, 12:34 PM
 */

#ifndef RECEIVER_H
#define	RECEIVER_H

#include "device.h"

#include "util.hpp"
#include "dma.hpp"


namespace sbus {
	void init();

	int16_t getChannel(uint8_t channel);  // Channels start from 0
}

#endif	/* RECEIVER_H */

