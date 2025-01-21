#include "device.h"
// #include <xc.h>  // TODO: explore, possibly delete Harmony files

#include "data.hpp"
#include "dma.hpp"
#include "i2c.hpp"
#include "LSM6DSO32.hpp"
#include "Mahony.hpp"
#include "nvm.hpp"
#include "Quaternion.hpp"
#include "sbus.hpp"
#include "servo.hpp"
#include "uart.hpp"
#include "usb.hpp"
#include "util.hpp"

#define DV_OUT 0

constexpr static float ATT_LSB {10430.0f};

enum class FlightMode : uint8_t {
	Manual = 0x0,
	Attitude = 0x1,
	Position = 0x2
};

enum class OrientationMode : uint8_t {
	Normal = 0x0,
	Inverted = 0x1,
	Tailsitter = 0x2  // Unused for now
};

enum class GimbalMode : uint8_t {
	Fixed = 0x0,
	Horizon = 0x1,
	Direction = 0x2
};

void calibrate(bool force = false) {
	if ((nvm::options->angularRateOffsets[0] == 0 && nvm::options->angularRateOffsets[1] == 0
	     && nvm::options->angularRateOffsets[2] == 0)
	    || force) {
		// If all offsets are zero, recalibrate
		Vector3<float, uint8_t> zeroOffsets {};

		for (uint16_t i {0}; i < 100; ++i) {
			LSM6DSO32::update();
			auto rates {LSM6DSO32::getAngularRates()};

			zeroOffsets += (rates - zeroOffsets) / 2;
			util::sleep(10);
		}

		LSM6DSO32::setOffsets(zeroOffsets);

		for (uint8_t i {0}; i < 3; ++i) {
			nvm::edit(nvm::options->angularRateOffsets + i, zeroOffsets[i][0]);
		}

		nvm::write();
	} else {  // Otherwise load previous calibration
		LSM6DSO32::setOffsets(
		    {{nvm::options->angularRateOffsets[0]},
		     {nvm::options->angularRateOffsets[1]},
		     {nvm::options->angularRateOffsets[2]}}
		);
	}
}

// Temperature calibration values
static uint8_t tempR = TEMP_LOG_FUSES_REGS->FUSES_TEMP_LOG_WORD_0 & FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Msk;
static uint8_t tempH = (TEMP_LOG_FUSES_REGS->FUSES_TEMP_LOG_WORD_0 & FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Msk)
                    >> FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Pos;
static uint16_t adcR = (TEMP_LOG_FUSES_REGS->FUSES_TEMP_LOG_WORD_1 & FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_Msk)
                    >> FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_Pos;
static uint16_t adcH = (TEMP_LOG_FUSES_REGS->FUSES_TEMP_LOG_WORD_1 & FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_Msk)
                    >> FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_Pos;

static Mahony     mahony {};
static Quaternion deviceOrientation {};

void updateSensors() {
	ADC_REGS->ADC_SWTRIG = ADC_SWTRIG_START(1);                 // Start conversion
	while (!(ADC_REGS->ADC_INTFLAG & ADC_INTFLAG_RESRDY_Msk));  // Wait for ADC result
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
	data::usbStatusResponse.receiverStatus = !!sbus::available() | (!!sbus::failsafeActive() << 1u);
}

float getDifference(float angleA, float angleB) {
	float diff = angleA - angleB;

	if (diff > F_PI) {
		return diff - F_2_PI;
	} else if (diff < -F_PI) {
		return diff + F_2_PI;
	} else {
		return diff;
	}
}

void startWatchdog() {
	WDT_REGS->WDT_CONFIG = WDT_CONFIG_PER_CYC64;
	WDT_REGS->WDT_CTRLA = WDT_CTRLA_ENABLE(1);
}

#if DV_OUT
struct DVData {
	uint8_t  header {0x03};
	uint16_t dt {};
	float    yaw {};
	float    pitch {};
	float    roll {};
	uint8_t  footer {0xfc};
} __attribute__((packed));
#endif

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
	float      pitchTarget {0};
	float      rollTarget {0};
	float      headingTarget {0};
	bool       rthSet {false};

	startWatchdog();

	while (1) {
#if DV_OUT
		auto startMs = util::getTime();
		auto startUs = SysTick->VAL;
#endif

		updateSensors();

		auto deviceAngles {deviceOrientation.toEuler()};

		flightMode = sbus::available() ? static_cast<FlightMode>((sbus::getChannel(8) + 1100) / 333) : FlightMode::Position;
		OrientationMode orientationMode {
		  sbus::available() ? static_cast<OrientationMode>((sbus::getChannel(9) + 1100) / 1000) : OrientationMode::Normal
		};

		if (!sbus::available()) {
			PORT_REGS->GROUP[0].PORT_OUTSET = 0x1 << 27u;
		} else {
			PORT_REGS->GROUP[0].PORT_OUTCLR = 0x1 << 27u;
		}

		if (sbus::failsafeActive()) {
			if (!rthSet) {
				headingTarget = deviceAngles[0][0] + F_PI;
				if (headingTarget > F_PI) {
					headingTarget -= F_2_PI;
				}
				rthSet = true;
			}
		} else {
			rthSet = false;
		}

		switch (flightMode) {
			case (FlightMode::Manual):
			default: {
				data::inputs[0][0] = sbus::getChannel(0);
				data::inputs[1][0] = sbus::getChannel(1);
				break;
			}
			case (FlightMode::Attitude): {
				rollTarget = sbus::getChannel(0) * F_PI_4 / 1000;
				pitchTarget = -sbus::getChannel(1) * F_PI_4 / 1000;

				if (orientationMode == OrientationMode::Inverted) {
					rollTarget = rollTarget + F_PI;
					if (rollTarget > F_PI) {
						rollTarget -= F_2_PI;
					}
				}

				data::inputs[0][0] = data::rollPID.process(getDifference(rollTarget, deviceAngles[2][0]));
				data::inputs[1][0] = data::pitchPID.process(getDifference(pitchTarget, deviceAngles[1][0]));

				if (deviceAngles[2][0] < -F_PI_2 || deviceAngles[2][0] > F_PI_2) {
					data::inputs[1][0] = -data::inputs[1][0];
				}
				break;
			}
			case (FlightMode::Position): {
				if (!rthSet) {
					headingTarget = -sbus::getChannel(0) * F_PI / 1000;
				}
				rollTarget =
				    util::clamp(data::headingPID.process(getDifference(deviceAngles[0][0], headingTarget), 0), -F_PI_4, F_PI_4);
				pitchTarget = -sbus::getChannel(1) * F_PI_4 / 1000;

				if (orientationMode == OrientationMode::Inverted) {
					rollTarget = rollTarget + F_PI;
					if (rollTarget > F_PI) {
						rollTarget -= F_2_PI;
					}
				}

				data::inputs[0][0] = data::rollPID.process(getDifference(rollTarget, deviceAngles[2][0]));
				data::inputs[1][0] = data::pitchPID.process(getDifference(pitchTarget, deviceAngles[1][0]));

				if (deviceAngles[2][0] < -F_PI_2 || deviceAngles[2][0] > F_PI_2) {
					data::inputs[1][0] = -data::inputs[1][0];
				}
				break;
			}
		}

		GimbalMode gimbalMode {
		  sbus::available() ? static_cast<GimbalMode>((sbus::getChannel(10) + 1100) / 1000) : GimbalMode::Horizon
		};

		switch (gimbalMode) {
			case (GimbalMode::Fixed): {
				data::inputs[2][0] = -sbus::getChannel(3);
				data::inputs[3][0] = -sbus::getChannel(4);
				data::inputs[4][0] = 0;
				break;
			}
			case (GimbalMode::Horizon): {
				Quaternion cameraOrientation {Quaternion::fromEuler(
				    deviceAngles[0][0] - sbus::getChannel(3) * F_PI_4 / 1000,
				    -sbus::getChannel(4) * F_PI_4 / 1000,
				    0
				)};
				Quaternion cameraRotation {deviceOrientation.conjugate() * cameraOrientation};
				auto       cameraAngles {cameraRotation.toEuler()};

				for (uint8_t i {0}; i < 3; ++i) {
					data::inputs[i + 2][0] = cameraAngles[i][0] / F_PI_4 * 1000;
				}
				break;
			}
			case (GimbalMode::Direction): {
				Quaternion cameraOrientation {
				  Quaternion::fromEuler(-sbus::getChannel(3) * F_PI / 1000, -sbus::getChannel(4) * F_PI_4 / 1000, 0)
				};
				Quaternion cameraRotation {deviceOrientation.conjugate() * cameraOrientation};
				auto       cameraAngles {cameraRotation.toEuler()};

				for (uint8_t i {0}; i < 3; ++i) {
					data::inputs[i + 2][0] = cameraAngles[i][0] / F_PI_4 * 1000;
				}
				break;
			}
		}

		data::calculateOutputs();

		for (uint8_t i {0}; i < data::outputChannelNumber; ++i) {
			servo::setChannel(i, data::outputs[i][0]);
		}

#if DV_OUT
		DVData data {};

		data.dt = (util::getTime() - startMs) * 1000 + (startUs - SysTick->VAL) / 48;
		data.yaw = deviceAngles[0][0];
		data.pitch = deviceAngles[1][0];
		data.roll = deviceAngles[2][0];
		uart::sendTo1(reinterpret_cast<uint8_t*>(&data), sizeof(data));
#endif

		util::sleep(10);

		WDT_REGS->WDT_CLEAR = WDT_CLEAR_CLEAR_KEY;
	}

	return 1;
}
