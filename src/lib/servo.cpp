#include "lib/servo.h"


static tc_registers_t* getTimer(uint8_t channel);
static uint8_t getTimerChannel(uint8_t channel);
static uint8_t getPin(uint8_t channel);


static tc_registers_t* getTimer(uint8_t channel) {
	if (channel < 2) {
		return TC2_REGS;
	} else if (channel < 4) {
		return TC0_REGS;
	} else {
		return TC1_REGS;
	}
}


static uint8_t getTimerChannel(uint8_t channel) {
	return channel & 0x1;
}


static uint8_t getPin(uint8_t channel) {
	uint8_t pin = channel;
	if (channel > 1) {
		pin += 2;
	}
	return pin;
}


void servo::init() {
	// GLCK config
	GCLK_REGS->GCLK_GENCTRL[1] = GCLK_GENCTRL_GENEN(1) // Enable GCLK 1
					| GCLK_GENCTRL_SRC_OSC16M // Set OSC16M as a source
					| GCLK_GENCTRL_DIVSEL_DIV2 // Set division mode (2^(x+1))
					| GCLK_GENCTRL_DIV(6); // Divide by 128 (2^(6+1))
	GCLK_REGS->GCLK_PCHCTRL[14] = GCLK_PCHCTRL_CHEN(1) // Enable TC0-1 clock
					| GCLK_PCHCTRL_GEN_GCLK1; //Set GCLK1 as a clock source
	GCLK_REGS->GCLK_PCHCTRL[15] = GCLK_PCHCTRL_CHEN(1) // Enable TC2 clock
					| GCLK_PCHCTRL_GEN_GCLK1; //Set GCLK1 as a clock source
}


void servo::enable(const uint8_t channel) {
	tc_registers_t * timer{getTimer(channel)};

	// TC config
	timer->COUNT16.TC_CTRLA = TC_CTRLA_MODE_COUNT16;
	timer->COUNT16.TC_DBGCTRL = TC_DBGCTRL_DBGRUN(1);
	timer->COUNT16.TC_WAVE = TC_WAVE_WAVEGEN_NPWM;
	timer->COUNT16.TC_PER = 1250;
	timer->COUNT16.TC_CC[getTimerChannel(channel)] = 96;
	timer->COUNT16.TC_CTRLA |= TC_CTRLA_ENABLE(1);

	// PORT config
	uint8_t pin{getPin(channel)};
	PORT_REGS->GROUP[0].PORT_PINCFG[pin] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin
	if (pin & 0x1) { // Odd pin
		PORT_REGS->GROUP[0].PORT_PMUX[pin / 2] = PORT_REGS->GROUP[0].PORT_PMUX[pin / 2] & 0xf
						| PORT_PMUX_PMUXO_E;
	} else { // Even pin
		PORT_REGS->GROUP[0].PORT_PMUX[pin / 2] = PORT_PMUX_PMUXE_E
						| PORT_REGS->GROUP[0].PORT_PMUX[pin / 2] & 0xf0;
	}
}


void servo::disable(const uint8_t channel) {
	uint8_t pin{getPin(channel)};
	PORT_REGS->GROUP[0].PORT_PINCFG[pin] = PORT_PINCFG_PMUXEN(0); // Enable mux on pin
	PORT_REGS->GROUP[0].PORT_OUTCLR = 0x1 << pin;
}


void servo::setAngle(const uint8_t channel, const uint8_t angle) {
	getTimer(channel)->COUNT16.TC_CC[getTimerChannel(channel)] = angle / 4 + 63;
}
