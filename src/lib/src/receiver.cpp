#include "lib/inc/receiver.hpp"


uint16_t timeRising[8];
uint16_t timeHigh[8];


static uint8_t getPin(uint8_t val) {
	for (uint8_t i {0}; i < 8; ++i) {
		if (val & 0x1) {
			return i;
		}
		val >>= 1u;
	}
	return 0;
}


extern "C" {
	void EIC_Handler() {
		TC2_REGS->COUNT16.TC_CTRLBSET = TC_CTRLBSET_CMD_READSYNC;
		while (TC2_REGS->COUNT16.TC_CTRLBSET);
		
		uint32_t time {TC2_REGS->COUNT16.TC_COUNT};
		uint8_t intFlag = EIC_REGS->EIC_INTFLAG >> 1u;
		uint8_t pin {getPin(intFlag)};
		uint8_t pinState = (PORT_REGS->GROUP[0].PORT_IN & 0xC00) >> 10u
						| (PORT_REGS->GROUP[0].PORT_IN & 0xC000) >> 12u;
		
		if (pinState & intFlag) {
			timeRising[pin] = time;
		} else {
			if (time > timeRising[pin]) {
				timeHigh[pin] = time - timeRising[pin];
			} else {
				timeHigh[pin] = 0xffff - timeRising[pin] + time;
			}
		}
		
		EIC_REGS->EIC_INTFLAG = 0xff;  // Clear interrupt flag
	}
}


void receiver::init() {
	PORT_REGS->GROUP[0].PORT_PINCFG[10] = PORT_PINCFG_PMUXEN(1);
	PORT_REGS->GROUP[0].PORT_PINCFG[11] = PORT_PINCFG_PMUXEN(1);
	PORT_REGS->GROUP[0].PORT_PINCFG[14] = PORT_PINCFG_PMUXEN(1);
	PORT_REGS->GROUP[0].PORT_PINCFG[15] = PORT_PINCFG_PMUXEN(1);
	
	PORT_REGS->GROUP[0].PORT_PMUX[5] = PORT_PMUX_PMUXE_A 
					| PORT_PMUX_PMUXO_A;
	PORT_REGS->GROUP[0].PORT_PMUX[7] = PORT_PMUX_PMUXE_A 
					| PORT_PMUX_PMUXO_A;
	
	EIC_REGS->EIC_INTENSET = 0xff;  // All 8 pins enabled
	EIC_REGS->EIC_ASYNCH = 0xff;  // Asynchronous mode
	EIC_REGS->EIC_CONFIG = 
					EIC_CONFIG_SENSE0_BOTH
					| EIC_CONFIG_SENSE1_BOTH
					| EIC_CONFIG_SENSE2_BOTH
					| EIC_CONFIG_SENSE3_BOTH
					| EIC_CONFIG_SENSE4_BOTH
					| EIC_CONFIG_SENSE5_BOTH
					| EIC_CONFIG_SENSE6_BOTH
					| EIC_CONFIG_SENSE7_BOTH;
	EIC_REGS->EIC_CTRLA = EIC_CTRLA_ENABLE(1);
	
	NVIC_EnableIRQ(EIC_EXTINT_0_IRQn);
	NVIC_EnableIRQ(EIC_EXTINT_1_IRQn);
	NVIC_EnableIRQ(EIC_EXTINT_2_IRQn);
	NVIC_EnableIRQ(EIC_EXTINT_3_IRQn);
	NVIC_EnableIRQ(EIC_OTHER_IRQn);	
}


int16_t receiver::getChannel(uint8_t channel) {
	return MAP(2667, 5333, (int16_t)0x8000, (int16_t)0x7fff, timeHigh[channel]);
}
