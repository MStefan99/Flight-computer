#include "device.h"
//#include <xc.h>  // TODO: explore, possibly delete Harmony files

#include "lib/inc/util.hpp"
#include "lib/inc/data.hpp"
#include "lib/inc/nvm.hpp"
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
    
    nvm::load();

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
    
    for (uint8_t i {0}; i < data::outputChannelNumber; ++i) {
        servo::enable(i);
    }
    
    Mode mode {};

    while (1) {
        ADC_REGS->ADC_SWTRIG = ADC_SWTRIG_START(1); // Start conversion
        while (!(ADC_REGS->ADC_INTFLAG & ADC_INTFLAG_RESRDY_Msk)); // Wait for ADC result
        data::usbSensorsResponse.temperature = tempR + ((ADC_REGS->ADC_RESULT - adcR) * (tempH - tempR) / (adcH - adcR));
        
        LSM6DSO32::update();
        
        for (uint8_t i {0}; i < 3; ++i) {
            data::usbSensorsResponse.accelerations[i] = LSM6DSO32::getRawAcc()[2 - i][0];
            data::usbSensorsResponse.angularRates[i] = LSM6DSO32::getRawRot()[2 - i][0];
        }
        
        mahony.updateIMU(LSM6DSO32::getRot(), LSM6DSO32::getAcc(), 0.01f);
        Quaternion deviceOrientation {mahony.getQuat()};
        auto deviceAngles {deviceOrientation.toEuler()};
        
        data::usbStatusResponse.pitch = deviceAngles[1][0] * ATT_LSB;
        data::usbStatusResponse.roll = deviceAngles[2][0] * ATT_LSB;
        
        float pitchTarget {0};
        float rollTarget {0};
        
        if (!sbus::available()) {
            PORT_REGS->GROUP[0].PORT_OUTSET = 0x1 << 27u;
            mode = Mode::Attitude;
            pitchTarget = rollTarget = 0;
        } else {
            PORT_REGS->GROUP[0].PORT_OUTCLR = 0x1 << 27u;
            pitchTarget = sbus::getChannel(0) / 1273.0f;
            rollTarget = sbus::getChannel(1) / 1273.0f;
            mode = static_cast<Mode>((sbus::getChannel(3) + 1200) / 300);
        }
        
        switch (mode) {
            case (Mode::Manual): {
                data::inputs[0][0] = sbus::getChannel(0);
                data::inputs[1][0] = sbus::getChannel(1);
                break;
            }
            case (Mode::Attitude): {
                auto rotationAngles {deviceOrientation.toEuler()};
                
                data::inputs[0][0] = rotationAngles[2][0] * 1273;
                data::inputs[1][0] = rotationAngles[1][0] * 1273;
                break;
            }
            default: {
                for (uint8_t i {0}; i < data::inputChannelNumber; ++i) {
                    data::inputs[i][0] = 0;
                }
                break;
            }
        }
        
        Quaternion cameraOrientation {};
        Quaternion cameraRotation {cameraOrientation * deviceOrientation.conjugate()};
        auto cameraAngles {cameraRotation.toEuler()};
        
        for (uint8_t i {0}; i < 3; ++i) {
            data::inputs[i + 2][0] = cameraAngles[i][0] * 1273;
        }
        
        data::calculateOutputs();
        
        for (uint8_t i {0}; i < data::outputChannelNumber; ++i) {
            servo::setChannel(i, data::outputs[i][0]);
        }
        
        util::sleep(10);
    }

    return 1;
}
