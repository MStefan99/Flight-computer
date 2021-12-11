#include "lib/inc/updates.h"


void millisecondUpdate() {
	// Nothing to do here yet
}


void fastUpdate() {
	int16_t a {lsm303::getAccelerationY()};
	servo::setAngle(0, MAP(-1000, 1000, 0, 0xff, a));
}


void slowUpdate() {
	// Nothing to do here yet
}

