/* 
 * File:   cpu.h
 * Author: mikha
 *
 * Created on November 20, 2021, 7:55 PM
 */

#ifndef CPU_H
#define	CPU_H

#include "device.h"


namespace cpu {
	enum CommandType {
		TEST = 0
	};
	
	
	struct Command {
		CommandType _type;
		uint8_t _len;
		uint8_t data[];
	};
	
	
	void init();
	void sendCommand(Command command);
	Command getCommand();
}


#endif	/* CPU_H */

