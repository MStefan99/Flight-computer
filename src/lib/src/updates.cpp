#include "lib/inc/updates.h"


void millisecondUpdate() {
	// Nothing to do here yet
}


void fastUpdate() {
	servo::setAngle(0, MAP(-1200, 1200, 0, 0xff, lsm303::getAccY()));
	servo::setAngle(1, MAP(-1200, 1200, 0, 0xff, lsm303::getAccX()));
}


void slowUpdate() {
	// Nothing to do here yet
}

