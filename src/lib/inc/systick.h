/* 
 * File:   system.h
 * Author: mikha
 *
 * Created on November 20, 2021, 1:15 PM
 */


#ifndef SYSTEM_H
#define	SYSTEM_H

#include "device.h"


#define MAP(x1, y1, x2, y2, value) ((value - x1) * (y2 - x2) / (y1 - x1) + x2)
#define AVG(a, b) ((a + b) / 2)
#define ABS(a) ((a > 0)? (a) : -(a))
#define MIN(a, b) ((a < b)? (a) : (b))
#define MAX(a, b) ((a > b)? (a) : (b))
#define SWAP(a, b) {\
  auto t {a};  \
  a = b;  \
  b = t;\
}
#define timeout(condition, time, body) {uint32_t _tme {system::getTickCount() + time}; \
    while (condition && _tme < system::getTickCount()) \
        body\
}


namespace systick {
	void init();

	uint32_t getTickCount();
	void sleep(uint32_t ms);
}


#endif	/* SYSTEM_H */

