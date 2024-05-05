#include "device.h"
//#include <xc.h>  // TODO: explore, possibly delete Harmony files

#include "lib/inc/util.hpp"
#include "lib/inc/data.hpp"
#include "lib/inc/usb.hpp"
#include "lib/inc/i2c.hpp"
#include "lib/inc/dma.hpp"
#include "lib/inc/LSM6DSO32.hpp"
#include "lib/inc/servo.hpp"
#include "lib/inc/Quaternion.hpp"
#include "lib/inc/Mahony.hpp"

#define NVMTEMP ((uint32_t*)0x00806030)

static constexpr float ATT_LSB {10430.0f};

int main() {
    util::init();
    
    dma::init();
//    sbus::init();
    i2c::init();
    LSM6DSO32::init();
    usb::init();
    
    Mahony mahony {};

    // Temperature calibration values
    uint8_t tempR = NVMTEMP[0] & 0xff;
    uint16_t adcR = (NVMTEMP[1] & 0xfff00) >> 8u;
    uint8_t tempH = (NVMTEMP[0] & 0xff0000) >> 12u;
    uint16_t adcH = (NVMTEMP[1] & 0xfff00000) >> 20u;

    while (1) {
        ADC_REGS->ADC_SWTRIG = ADC_SWTRIG_START(1); // Start conversion
        while (!(ADC_REGS->ADC_INTFLAG & ADC_INTFLAG_RESRDY_Msk)); // Wait for ADC result
        data::statusDescriptor.bTemp = tempR + ((ADC_REGS->ADC_RESULT - adcR) * (tempH - tempR) / (adcH - adcR));
        
        LSM6DSO32::update();
        
        for (uint8_t i {0}; i < 3; ++i) {
            data::statusDescriptor.wAcc[i] = LSM6DSO32::getRawAcc()[i][0];
            data::statusDescriptor.wRot[i] = LSM6DSO32::getRawRot()[i][0];
        }
        
        mahony.updateIMU(LSM6DSO32::getRot(), LSM6DSO32::getAcc(), 0.01f);
        Quaternion deviceOrientation {mahony.getQuat()};
        auto deviceAngles {deviceOrientation.toEuler()};
        
        data::statusDescriptor.wPitch = deviceAngles[1][0] * ATT_LSB;
        data::statusDescriptor.wRoll = deviceAngles[2][0] * ATT_LSB;
        
        Quaternion targetOrientation {Quaternion::fromEuler(deviceAngles[0][0], data::inputs[1][0], data::inputs[0][0])};
        Quaternion cameraOrientation {Quaternion::fromEuler(deviceAngles[0][0] + data::inputs[4][0], data::inputs[5][0], 0)};
        
        Quaternion deviceRotation {deviceOrientation * targetOrientation.conjugate()};
        Quaternion cameraRotation {deviceOrientation * cameraOrientation.conjugate()};
        
        util::sleep(10);
    }

    return 1;
}
