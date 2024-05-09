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
#include "lib/inc/sbus.hpp"
#include "lib/inc/uart.hpp"

#define NVMTEMP ((uint32_t*)0x00806030)

static constexpr float ATT_LSB {10430.0f};

enum class Mode : uint8_t {
    Manual = 0x0,
    Attitude = 0x1,
    Heading = 0x2
};


int main() {
    util::init();
    
    dma::init();
    sbus::init();
    i2c::init();
    servo::init();
    LSM6DSO32::init();
    usb::init();
    
    Mahony mahony {};
    
    PORT_REGS->GROUP[0].PORT_DIR = 0x1 << 27u;

    // Temperature calibration values
    uint8_t tempR = NVMTEMP[0] & 0xff;
    uint16_t adcR = (NVMTEMP[1] & 0xfff00) >> 8u;
    uint8_t tempH = (NVMTEMP[0] & 0xff0000) >> 12u;
    uint16_t adcH = (NVMTEMP[1] & 0xfff00000) >> 20u;
    
    for (uint8_t i {0}; i < 8; ++i) {
        servo::enable(i);
    }
    
    Mode mode {};

    while (1) {
        ADC_REGS->ADC_SWTRIG = ADC_SWTRIG_START(1); // Start conversion
        while (!(ADC_REGS->ADC_INTFLAG & ADC_INTFLAG_RESRDY_Msk)); // Wait for ADC result
        data::statusDescriptor.temperature = tempR + ((ADC_REGS->ADC_RESULT - adcR) * (tempH - tempR) / (adcH - adcR));
        
        LSM6DSO32::update();
        
        for (uint8_t i {0}; i < 3; ++i) {
            data::statusDescriptor.accelerations[i] = LSM6DSO32::getRawAcc()[2 - i][0];
            data::statusDescriptor.angularRates[i] = LSM6DSO32::getRawRot()[2 - i][0];
        }
        
        mahony.updateIMU(LSM6DSO32::getRot(), LSM6DSO32::getAcc(), 0.01f);
        Quaternion deviceOrientation {mahony.getQuat()};
        auto deviceAngles {deviceOrientation.toEuler()};
        
        data::statusDescriptor.pitch = deviceAngles[1][0] * ATT_LSB;
        data::statusDescriptor.roll = deviceAngles[2][0] * ATT_LSB;
        
        Quaternion targetOrientation {Quaternion::fromEuler(deviceAngles[0][0], data::inputs[1][0], data::inputs[0][0])};
        Quaternion cameraOrientation {};
        
        Quaternion deviceRotation {targetOrientation * deviceOrientation.conjugate()};
        
        mode = static_cast<Mode>((sbus::getChannel(3) + 1200) / 300);
        
        if (!sbus::available()) {
            PORT_REGS->GROUP[0].PORT_OUTSET = 0x1 << 27u;
            mode = Mode::Attitude;
        } else {
            PORT_REGS->GROUP[0].PORT_OUTCLR = 0x1 << 27u;
        }
        
        switch (mode) {
            case (Mode::Manual): {   
                servo::setChannel(0, sbus::getChannel(0));
                servo::setChannel(1, sbus::getChannel(1));
                break;
            }
            case (Mode::Attitude): {
                auto rotationAngles {deviceRotation.toEuler()};
                
                servo::setChannel(0, rotationAngles[2][0] * 1910);
                servo::setChannel(1, rotationAngles[1][0] * 1910);
                break;
            }
            default: {
                for (uint8_t i {0}; i < 8; ++i) {
                    servo::setChannel(i, 0);
                }
                break;
            }
        }
        
        Quaternion cameraRotation {cameraOrientation * deviceOrientation.conjugate()};
        auto cameraAngles {cameraRotation.toEuler()};
        
        servo::setChannel(2, cameraAngles[0][0] * 1273);
        servo::setChannel(3, cameraAngles[1][0] * 1273);
        servo::setChannel(4, cameraAngles[2][0] * 1273);
        
        util::sleep(10);
    }

    return 1;
}
