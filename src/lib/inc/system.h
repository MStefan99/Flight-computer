/* 
 * File:   system.h
 * Author: mikha
 *
 * Created on November 20, 2021, 1:15 PM
 */


#ifndef SYSTEM_H
#define	SYSTEM_H

#include "device.h"


namespace system {
	void init();
	
	uint32_t getTickCount();
	void sleep(uint32_t ms);
}


#endif	/* SYSTEM_H */

