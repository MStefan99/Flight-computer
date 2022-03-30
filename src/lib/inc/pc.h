/* 
 * File:   cpu.h
 * Author: mikha
 *
 * Created on November 20, 2021, 7:55 PM
 */

#ifndef PC_H
#define	PC_H

#include <cstring>
#include "device.h"
#include "lib/inc/dma.h"


namespace pc {
	enum CommandType: uint8_t {
		NUL = 0,
		SendAxisData = 1
	};
	
	
	struct Command {
		uint8_t len;
		CommandType type;
		uint8_t data[6];
	};
	
	
	void init();
	void sendCommand(const Command& command);
    
    uint8_t dataReceived();
	uint8_t* getData();
}


#endif	/* CPU_H */

