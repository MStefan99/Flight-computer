/* 
 * File:   updates.h
 * Author: mikha
 *
 * Created on December 11, 2021, 11:33 AM
 */

#ifndef UPDATES_H
#define	UPDATES_H

#include "device.h"

#include "pc.h"
#include "servo.h"
#include "util.h"

#include "PID.hpp"
#include "AttitudeEstimator.h"

#include "mpu6050.h"


namespace updates {
	void init();

	void ms(); // Called every millisecond
	void fast(); // Called every 20ms
	void slow(); // Called every second
}

#endif	/* UPDATES_H */

