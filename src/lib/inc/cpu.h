/* 
 * File:   cpu.h
 * Author: mikha
 *
 * Created on November 20, 2021, 7:55 PM
 */

#ifndef CPU_H
#define	CPU_H

#include <cstring>
#include "device.h"
#include "lib/inc/dma.h"


namespace cpu {
	enum CommandType: uint8_t {
		NUL = 0
	};
	
	
	struct Command {
		CommandType _type;
		uint8_t _len;
		uint8_t data[6];
	};
	
	
	void init();
	
	void send(uint8_t* data, uint8_t size);
	void sendCommand(Command command);
	Command getCommand();
	
	// I2C transfers are queued, call this function to start next transaction
	void startTransfer();
	bool transferPending();
}


#endif	/* CPU_H */

