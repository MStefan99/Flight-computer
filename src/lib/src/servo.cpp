#include "lib/servo.hpp"


static tcc_registers_t* getTimer(uint8_t channel);
static uint8_t getTimerChannel(uint8_t channel);
static uint8_t getPin(uint8_t channel);


static tcc_registers_t* getTimer(uint8_t channel) {
	return TCC2_REGS;
}


static uint8_t getTimerChannel(uint8_t channel) {
	return channel & 0x1;
}


static uint8_t getPin(uint8_t channel) {
	return channel + 16;
}


void servo::init() {
	// GLCK config
	GCLK_REGS->GCLK_GENCTRL[1] = GCLK_GENCTRL_GENEN(1) // Enable GCLK 1
					| GCLK_GENCTRL_OE(1)
					| GCLK_GENCTRL_SRC_OSC16M // Set OSC16M as a source
					| GCLK_GENCTRL_DIVSEL_DIV1 // Set division mode (x)
					| GCLK_GENCTRL_DIV(8); // Divide by 8 (osc running at 8 MHz)
	GCLK_REGS->GCLK_PCHCTRL[25] = GCLK_PCHCTRL_CHEN(1) // Enable TCC[0:1] clock
					| GCLK_PCHCTRL_GEN_GCLK1; //Set GCLK1 as a clock source
	GCLK_REGS->GCLK_PCHCTRL[26] = GCLK_PCHCTRL_CHEN(1) // Enable TCC2 clock
					| GCLK_PCHCTRL_GEN_GCLK1; //Set GCLK1 as a clock source
}


void servo::enable(uint8_t channel) {
	tcc_registers_t* timer {getTimer(channel)};

	// TCC config
	timer->TCC_CTRLA = TC_CTRLA_MODE_COUNT16; // 16-bit mode
	timer->TCC_DBGCTRL = TC_DBGCTRL_DBGRUN(1); // Run while debugging
	timer->TCC_WAVE = TC_WAVE_WAVEGEN_NPWM; // PWM generation
	timer->TCC_PER = 20000; // 20ms * GCLK_TCC
	timer->TCC_CC[getTimerChannel(channel)] = 1500; // 1.5ms * GCLK_TCC
	timer->TCC_CTRLA |= TC_CTRLA_ENABLE(1); // Enable timer

	// PORT config
	uint8_t pin {getPin(channel)};
	PORT_REGS->GROUP[0].PORT_PINCFG[pin] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin
	if (pin & 0x1) { // Odd pin
		PORT_REGS->GROUP[0].PORT_PMUX[pin / 2] = (PORT_REGS->GROUP[0].PORT_PMUX[pin / 2] & 0xf)
						| PORT_PMUX_PMUXO_E;
	} else { // Even pin
		PORT_REGS->GROUP[0].PORT_PMUX[pin / 2] = PORT_PMUX_PMUXE_E
						| (PORT_REGS->GROUP[0].PORT_PMUX[pin / 2] & 0xf0);
	}
}


void servo::disable(uint8_t channel) {
	uint8_t pin {getPin(channel)};
	PORT_REGS->GROUP[0].PORT_OUTCLR = 0x1 << pin;
	PORT_REGS->GROUP[0].PORT_PINCFG[pin] = PORT_PINCFG_PMUXEN(0); // Enable mux on pin
}


void servo::setChannel(uint8_t channel, int16_t angle) {
	// Range: [1ms * GCLK_TC; 2ms * GCLK_TCC]
	getTimer(channel)->TCC_CCBUF[getTimerChannel(channel)] = angle / 2 + 1500;
}
