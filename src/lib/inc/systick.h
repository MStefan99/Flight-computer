/* 
 * File:   systick.h
 * Author: mikha
 *
 * Created on November 20, 2021, 1:15 PM
 */


#ifndef SYSTICK_H
#define	SYSTICK_H

#include "device.h"


namespace systick {
	void init();
	uint32_t getTickCount();
	void sleep(uint32_t ms);
}


#endif	/* SYSTICK_H */

