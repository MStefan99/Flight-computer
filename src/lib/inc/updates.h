/* 
 * File:   updates.h
 * Author: mikha
 *
 * Created on December 11, 2021, 11:33 AM
 */

#ifndef UPDATES_H
#define	UPDATES_H

#include "device.h"
#include "lsm303.h"
#include "servo.h"


void millisecondUpdate();  // Called every millisecond
void fastUpdate();  // Called every 20ms
void slowUpdate();  // Called every second


#endif	/* UPDATES_H */

