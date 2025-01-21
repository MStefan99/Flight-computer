/*
 * File:   receiver.h
 * Author: mikha
 *
 * Created on December 7, 2021, 12:34 PM
 */

#ifndef SBUS_HPP
#define SBUS_HPP

#include "device.h"

#include "dma.hpp"
#include "util.hpp"

namespace sbus {
	void init();

	bool    available();
	int16_t getChannel(uint8_t channel);  // Channels start from 0
	bool    frameLost();
	bool    failsafeActive();
}

#endif /* SBUS_HPP */
