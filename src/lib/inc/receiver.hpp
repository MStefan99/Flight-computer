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
#include "pc.hpp"


namespace receiver {
	void initPWM();  // Not supported on L10
	void initSBUS();

	int16_t getChannel(uint8_t channel);
}

#endif	/* RECEIVER_H */

