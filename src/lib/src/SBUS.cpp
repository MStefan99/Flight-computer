#include "lib/inc/sbus.hpp"

#define SERCOM_REGS SERCOM1_REGS


uint8_t SBUSBuffer[25] {};


static uint16_t getValue(const uint8_t* data, uint8_t idx) {
	uint16_t res = 0;

	uint8_t startBit = idx * 11;
	uint8_t endBit = startBit + 11;

	while (startBit < endBit) {
		uint8_t bitsLeft = endBit - startBit;
		uint8_t startPos = startBit % 8;
		uint8_t endPos = bitsLeft > 8? 8 : bitsLeft;
		uint8_t bitCount = endPos - startPos;
		auto shift = static_cast<int8_t>(11 - bitsLeft - startPos);

		res |= shift < 0? data[startBit / 8] >> -shift : data[startBit / 8] << shift;
		startBit += bitCount;
	}

	return res & 0x7ff;
}



void sbus::init() {
	GCLK_REGS->GCLK_PCHCTRL[19] = GCLK_PCHCTRL_CHEN(1) | // Enable SERCOM1 clock
					GCLK_PCHCTRL_GEN_GCLK0; //Set GCLK0 as a clock source

	// PORT config
	PORT_REGS->GROUP[0].PORT_PINCFG[17] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin 17
	PORT_REGS->GROUP[0].PORT_PMUX[8] = PORT_PMUX_PMUXO_C; // Mux pin 17 to SERCOM1

	// SERCOM config
	SERCOM_REGS->USART_INT.SERCOM_CTRLB = SERCOM_USART_INT_CTRLB_RXEN(1) |
					//SERCOM_USART_INT_CTRLB_TXEN(1) |  // For future use
					SERCOM_USART_INT_CTRLB_PMODE_EVEN |
					SERCOM_USART_INT_CTRLB_SBMODE_2_BIT |
					SERCOM_USART_INT_CTRLB_CHSIZE_8_BIT;
	SERCOM_REGS->USART_INT.SERCOM_BAUD = 52429; // 100KHz
	SERCOM_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_DORD_LSB |
					SERCOM_USART_INT_CTRLA_CMODE_ASYNC |
					SERCOM_USART_INT_CTRLA_FORM_USART_FRAME_WITH_PARITY |
					SERCOM_USART_INT_CTRLA_RXPO_PAD1 |
					//SERCOM_USART_INT_CTRLA_TXPO_PAD0 |
					SERCOM_USART_INT_CTRLA_MODE_USART_INT_CLK |
					SERCOM_USART_INT_CTRLA_ENABLE(1);
}


int16_t sbus::getChannel(uint8_t channel) {
	// TODO: clamp values
	int16_t value = getValue(SBUSBuffer + 1, channel);
	return value? util::map(static_cast<int>(value), 160, 1850, 0x8000, 0x7fff) : 0;
}
