#include "lib/inc/sbus.hpp"

#define SERCOM_REGS SERCOM3_REGS

static constexpr uint8_t PACKET_SIZE = 25;
static constexpr uint8_t START_BYTE = 0x0f;
static constexpr uint8_t END_BYTE = 0x00;

uint8_t buffer[PACKET_SIZE] {};
uint8_t bytesReceived {0};
uint32_t lastPacketReceived {0};


extern "C" {
    void SERCOM3_Handler() {
        uint8_t byte = SERCOM_REGS->USART_INT.SERCOM_DATA;
        
        if (!bytesReceived && byte != START_BYTE) {
            return;
        }
        
        buffer[bytesReceived++] = byte;
        
        if (bytesReceived == PACKET_SIZE) {
            bytesReceived = 0; // Reset counter to start receiving new packet
            if (byte == END_BYTE) {
                lastPacketReceived = util::getTime();
            } else {
                lastPacketReceived = 0;
            }
        }
    }
}


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
	GCLK_REGS->GCLK_PCHCTRL[SERCOM3_GCLK_ID_CORE] = GCLK_PCHCTRL_CHEN(1) // Enable SERCOM3 clock
					| GCLK_PCHCTRL_GEN_GCLK0; //Set GCLK0 as a clock source

	// PORT config
    PORT_REGS->GROUP[0].PORT_WRCONFIG = PORT_WRCONFIG_PINMASK((0x1 << 6u) | (0x1 << 7u))
            | PORT_WRCONFIG_PMUXEN(1)
            | PORT_WRCONFIG_PMUX(MUX_PA22C_SERCOM3_PAD0)
            | PORT_WRCONFIG_WRPMUX(1)
            | PORT_WRCONFIG_WRPINCFG(1)
            | PORT_WRCONFIG_HWSEL(1);

	// SERCOM config
	SERCOM_REGS->USART_INT.SERCOM_CTRLB = 
            SERCOM_USART_INT_CTRLB_RXEN(1)
            //| SERCOM_USART_INT_CTRLB_TXEN(1)
			| SERCOM_USART_INT_CTRLB_PMODE_EVEN
			| SERCOM_USART_INT_CTRLB_SBMODE_2_BIT
			| SERCOM_USART_INT_CTRLB_CHSIZE_8_BIT;
	SERCOM_REGS->USART_INT.SERCOM_BAUD = 63351; // 100KHz
    SERCOM_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTENSET_RXC(1);
	SERCOM_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_DORD_LSB
            | SERCOM_USART_INT_CTRLA_CMODE_ASYNC
            | SERCOM_USART_INT_CTRLA_SAMPR_16X_ARITHMETIC
			| SERCOM_USART_INT_CTRLA_FORM_USART_FRAME_WITH_PARITY
			| SERCOM_USART_INT_CTRLA_RXPO_PAD1
			| SERCOM_USART_INT_CTRLA_TXPO_PAD0
			| SERCOM_USART_INT_CTRLA_MODE_USART_INT_CLK
			| SERCOM_USART_INT_CTRLA_ENABLE(1);
    
    NVIC_EnableIRQ(SERCOM3_IRQn);
    
    util::sleep(1);
    SERCOM_REGS->USART_INT.SERCOM_DATA = 0x55;
}


bool sbus::available() {
    return bytesReceived && (util::getTime() - lastPacketReceived < 20);
}


int16_t sbus::getChannel(uint8_t channel) {
    if (!available) {
        return 0;
    } else if (channel < 16) {   
        int16_t value = getValue(buffer + 1, channel);
        
        return value? util::map(static_cast<int>(value), 160, 1850, -1500, 1500) : 0;
    } else if (channel < 18) {
        /* Calculate the bit corresponding to the channel
         * 
         * Bit 7: digital channel 17 (0x80)
         * Bit 6: digital channel 18 (0x40)
         */
        uint8_t bit = 24 - channel;
        return ((buffer[23]) >> bit) & 0x1;
    } else {
        return 0;
    }
}


bool sbus::frameLost() {
    return (buffer[23] >> 5u) & 0x1;
}


bool sbus::failsafeActive() {
    return (buffer[23] >> 4u) & 0x1;
}
