/* 
 * File:   servo.h
 * Author: mikha
 *
 * Created on November 20, 2021, 4:05 PM
 */

#ifndef SERVO_H
#define	SERVO_H

#include "device.h"
#include "system.h"


namespace servo {
	void init();
	void enable(const uint8_t channel);
	void disable(const uint8_t channel);
	void setAngle(const uint8_t channel, const uint8_t angle);
}


#endif	/* PWM_H */

