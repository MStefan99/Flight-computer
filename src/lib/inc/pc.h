/* 
 * File:   cpu.h
 * Author: mikha
 *
 * Created on November 20, 2021, 7:55 PM
 */

#ifndef PC_H
#define	PC_H

#include "device.h"

#include "lib/inc/tl/allocator.hpp"
#include "lib/inc/util.h"
#include "lib/inc/dma.h"


namespace pc {

	enum CommandType : uint8_t {
		NUL = 0,
		SendAccData = 1,
		SendRotData = 2
	};

	struct Command {
		uint8_t len;
		CommandType type;
		uint8_t data[6];
	};


	void init();
	void send(uint8_t* data, uint8_t size = 1);

	void sendCommand(const Command& command);

	uint8_t dataReceived();
	uint8_t* getData();
}


#endif	/* CPU_H */

