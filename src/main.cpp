#include "device.h"
//#include <xc.h>  // TODO: explore, possibly delete Harmony files

#include "lib/inc/util.hpp"
#include "lib/inc/updates.hpp"
#include "lib/inc/usb.hpp"
#include "lib/inc/i2c.hpp"
#include "lib/inc/dma.hpp"


/*
 * THIS FILE IS FOR INITIALIZATION ONLY!
 * 
 * Use the updates.cpp file for the main program logic
 */

int main() {
    util::init();

    dma::init();
//    sbus::init();
    i2c::init();
    usb::init();

    updates::init();

    while (1) {
        util::sleep(1);

        updates::ms();

        if (util::getTickCount() % 20 == 0) {
            updates::fast();

            if (util::getTickCount() % 1000 == 0) {
                updates::slow();

                // TODO: Doesn't work, figure out why
            }
        }
    }

    return 1;
}
