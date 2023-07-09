/* 
 * File:   bldc.hpp
 * Author: Mikhail
 *
 * Created on July 9, 2023, 4:33 PM
 */

#ifndef BLDC_HPP
#define	BLDC_HPP

#include "device.h"

#include "util.hpp"


namespace bldc {
    void init();
    
    void setAngle(int16_t angle);
}

#endif	/* BLDC_HPP */

