#include "device.h"
//#include <xc.h>  // TODO: explore, possibly delete Harmony files

#include "lib/inc/util.h"
#include "lib/inc/updates.h"
#include "lib/inc/pc.h"
#include "lib/inc/i2c.h"


/*
 * THIS FILE IS FOR INITIALIZATION ONLY!
 * 
 * Use the updates.cpp file for the main program logic
 */

int main() {
	util::init();

	pc::init();
	i2c::init();
	
	updates::init();

	while (1) {
		util::sleep(1);

		updates::ms();

		if (!(util::getTickCount() % 20)) {
			updates::fast();
		}

		if (!(util::getTickCount() % 1000)) {
			updates::slow();
		}
	}

	return 1;
}
