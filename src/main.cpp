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

enum class FlightMode : uint8_t {
    Manual = 0x0,
    Attitude = 0x1,
    Position = 0x2
};

enum class GimbalMode : uint8_t {
    Fixed = 0x0,
    Horizon = 0x1,
    Direction = 0x2
};

void calibrate(bool force = false) {
    if ((nvm::options->angularRateOffsets[0] == 0
            && nvm::options->angularRateOffsets[1] == 0
            && nvm::options->angularRateOffsets[2] == 0)
            || force) {
        // If all offsets are zero, recalibrate
        Vector3<float, uint8_t> zeroOffsets {};

        for (uint16_t i {0}; i < 100; ++i) {
            LSM6DSO32::update();
            auto rates {LSM6DSO32::getAngularRates()};

            zeroOffsets += (rates - zeroOffsets) / 2;
            util::sleep(1);
        }

        LSM6DSO32::setOffsets(zeroOffsets);
        
        for (uint8_t i {0}; i < 3; ++i) {
            nvm::edit(nvm::options->angularRateOffsets + i, zeroOffsets[i][0]);
        }
        
        nvm::write();
    } else { // Otherwise load previous calibration
        LSM6DSO32::setOffsets({{nvm::options->angularRateOffsets[0]},
            {nvm::options->angularRateOffsets[1]},
            {nvm::options->angularRateOffsets[2]}
        });
    }
}


// Temperature calibration values
static uint8_t tempR = NVMTEMP[0] & 0xff;
static uint16_t adcR = (NVMTEMP[1] & 0xfff00) >> 8u;
static uint8_t tempH = (NVMTEMP[0] & 0xff0000) >> 12u;
static uint16_t adcH = (NVMTEMP[1] & 0xfff00000) >> 20u;

static Mahony mahony {};
static Quaternion deviceOrientation {};


void updateSensors() {
    ADC_REGS->ADC_SWTRIG = ADC_SWTRIG_START(1); // Start conversion
    while (!(ADC_REGS->ADC_INTFLAG & ADC_INTFLAG_RESRDY_Msk)); // Wait for ADC result
    data::usbSensorsResponse.temperature = tempR + ((ADC_REGS->ADC_RESULT - adcR) * (tempH - tempR) / (adcH - adcR));

    LSM6DSO32::update();

    for (uint8_t i {0}; i < 3; ++i) {
        data::usbSensorsResponse.accelerations[i] = LSM6DSO32::getRawAccelerations()[2 - i][0];
        data::usbSensorsResponse.angularRates[i] = LSM6DSO32::getRawAngularRates()[2 - i][0];
    }

    mahony.updateIMU(LSM6DSO32::getAngularRates(), LSM6DSO32::getAccelerations(), 0.01f);
    deviceOrientation = mahony.getQuat();
    auto deviceAngles {deviceOrientation.toEuler()};

    data::usbStatusResponse.pitch = deviceAngles[1][0] * ATT_LSB;
    data::usbStatusResponse.roll = deviceAngles[2][0] * ATT_LSB;
}

void startWatchdog() {
    WDT_REGS->WDT_CONFIG = WDT_CONFIG_PER_CYC64;
    WDT_REGS->WDT_CTRLA = WDT_CTRLA_ENABLE(1);
}

int main() {
    util::init();
    
    nvm::load();

    dma::init();
    sbus::init();
    i2c::init();
    servo::init();
    LSM6DSO32::init();
    usb::init();
    
    calibrate();
    
    PORT_REGS->GROUP[0].PORT_DIR = 0x1 << 27u;
    
    for (uint8_t i {0}; i < data::outputChannelNumber; ++i) {
        servo::enable(i);
    }

    FlightMode flightMode {};
    float pitchTarget {0};
    float rollTarget {0};
    float headingTarget {0};
    bool failsafe {false};
    
    startWatchdog();

    while (1) {
        updateSensors();
        
        auto deviceAngles {deviceOrientation.toEuler()};
        
        pitchTarget = sbus::getChannel(0) / 1273.0f;
        rollTarget = sbus::getChannel(1) / 1273.0f;
        flightMode = sbus::available() ? static_cast<FlightMode>((sbus::getChannel(3) + 1100) / 500) : FlightMode::Position;
        
        if (!sbus::available()) {
            if (!failsafe) {
                PORT_REGS->GROUP[0].PORT_OUTSET = 0x1 << 27u;
                headingTarget = deviceAngles[0][0] + F_PI;
                if (headingTarget > F_2_PI) {
                    headingTarget -= F_2_PI;
                }
                failsafe = true;
            }  
        } else {
            PORT_REGS->GROUP[0].PORT_OUTCLR = 0x1 << 27u;
            failsafe = false;
        }
        
        switch (flightMode) {
            case (FlightMode::Manual): {
                data::inputs[0][0] = sbus::getChannel(0);
                data::inputs[1][0] = sbus::getChannel(1);
                break;
            }
            case (FlightMode::Position): {
                if (sbus::available()) {
                    headingTarget = sbus::getChannel(0) * F_PI / 1000;
                }
                rollTarget = data::headingPID.process(deviceAngles[0][0], headingTarget);
                pitchTarget = sbus::getChannel(1) * F_PI_4 / 1000;
                
                data::inputs[0][0] = data::rollPID.process(deviceAngles[2][0], rollTarget);
                data::inputs[1][0] = data::pitchPID.process(deviceAngles[1][0], pitchTarget);
                break;
            }
            case (FlightMode::Attitude): {
                rollTarget = sbus::getChannel(0) * F_PI_4 / 1000;
                pitchTarget = sbus::getChannel(1) * F_PI_4 / 1000;
                
                data::inputs[0][0] = data::rollPID.process(deviceAngles[2][0], rollTarget);
                data::inputs[1][0] = data::pitchPID.process(deviceAngles[1][0], pitchTarget);
                break;
            }
            default: {
                data::inputs[0][0] = 0;
                data::inputs[1][0] = 0;
                break;
            }
        }
        
        GimbalMode gimbalMode {static_cast<GimbalMode>((sbus::getChannel(4) + 1100) / 1000)};
        
        switch (gimbalMode) {
            case (GimbalMode::Fixed): {
                data::inputs[2][0] = sbus::getChannel(5);
                data::inputs[3][0] = sbus::getChannel(6);
                data::inputs[4][0] = 0;
                break;   
            }
            case (GimbalMode::Horizon): {
                Quaternion cameraOrientation {Quaternion::fromEuler(
                    deviceAngles[0][0] + sbus::getChannel(5) * F_PI_4 / 1000,
                    sbus::getChannel(6) * F_PI_4 / 1000,
                    0
                )};
                Quaternion cameraRotation {deviceOrientation.conjugate() * cameraOrientation};
                auto cameraAngles {cameraRotation.toEuler()};

                for (uint8_t i {0}; i < 3; ++i) {
                    data::inputs[i + 2][0] = cameraAngles[i][0] / F_PI_4 * 1000;
                }
                break;
            }
            case (GimbalMode::Direction): {
                Quaternion cameraOrientation {Quaternion::fromEuler(
                    sbus::getChannel(5) * F_PI / 1000,
                    sbus::getChannel(6) * F_PI_4 / 1000,
                    0
                )};
                Quaternion cameraRotation {deviceOrientation.conjugate() * cameraOrientation};
                auto cameraAngles {cameraRotation.toEuler()};

                for (uint8_t i {0}; i < 3; ++i) {
                    data::inputs[i + 2][0] = cameraAngles[i][0] / F_PI_4 * 1000;
                }
                break;
            }
        }
        
        for (uint8_t i {0}; i < 3; ++i) {
            data::inputs[i + 5][0] = deviceAngles[i][0] / F_PI * 1000;
        }
        
        data::calculateOutputs();
        
        for (uint8_t i {0}; i < data::outputChannelNumber; ++i) {
            servo::setChannel(i, data::outputs[i][0]);
        }
        
        util::sleep(10);
        
        WDT_REGS->WDT_CLEAR = WDT_CLEAR_CLEAR_KEY;
    }

    return 1;
}
