#include "lib/inc/pc.h"
#include "lib/inc/list.h"

#define SERCOM_REGS SERCOM2_REGS


typedef struct __attribute__((packed)) {
	uint8_t* buf;
	uint8_t len;
}
UARTTransfer;


static void startTransfer();
static void send(uint8_t* data, uint8_t size);
static tl::list<UARTTransfer> pendingTransfers;


static uint8_t incomingData[8] {};
static uint8_t bytesReceived {0};


extern "C" {
    void UART_Handler() {
        if (bytesReceived < 8) {
            incomingData[bytesReceived++] = SERCOM_REGS->USART_INT.SERCOM_DATA;
        }
        SERCOM_REGS->USART_INT.SERCOM_INTFLAG = SERCOM_USART_INT_INTENSET_RXC(1);
    }
}


void dma::UART_TCMPL_Handler() {
	UARTTransfer transfer{pendingTransfers.front()};
	delete[](transfer.buf);
	pendingTransfers.pop_front();
    startTransfer();
}


void pc::init() {
	GCLK_REGS->GCLK_PCHCTRL[13] = GCLK_PCHCTRL_CHEN(1) // Enable SERCOM2 clock
					| GCLK_PCHCTRL_GEN_GCLK0; //Set GCLK0 as a clock source

	// PORT config
	PORT_REGS->GROUP[0].PORT_PINCFG[22] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin 22
	PORT_REGS->GROUP[0].PORT_PINCFG[23] = PORT_PINCFG_PMUXEN(1); // Enable mux on pin 23
	PORT_REGS->GROUP[0].PORT_PMUX[11] = PORT_PMUX_PMUXE_D // Mux pin 22 to SERCOM2
					| PORT_PMUX_PMUXO_D; // Mux pin 23 to SERCOM2

	// DMA config
	dma::initUART();

	// SERCOM config
	SERCOM_REGS->USART_INT.SERCOM_CTRLB = SERCOM_USART_INT_CTRLB_RXEN(1)
					| SERCOM_USART_INT_CTRLB_TXEN(1)
					| SERCOM_USART_INT_CTRLB_PMODE_EVEN
					| SERCOM_USART_INT_CTRLB_SBMODE_1_BIT
					| SERCOM_USART_INT_CTRLB_CHSIZE_8_BIT;
	SERCOM_REGS->USART_INT.SERCOM_BAUD = 0;  // 500KHz
	SERCOM_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_DORD_LSB
					| SERCOM_USART_INT_CTRLA_CMODE_ASYNC
					| SERCOM_USART_INT_CTRLA_FORM_USART_FRAME_WITH_PARITY
					| SERCOM_USART_INT_CTRLA_RXPO_PAD1
					| SERCOM_USART_INT_CTRLA_TXPO_PAD0
					| SERCOM_USART_INT_CTRLA_MODE_USART_INT_CLK
					| SERCOM_USART_INT_CTRLA_ENABLE(1);
    SERCOM_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTENSET_RXC(1);
}


static void send(uint8_t* data, uint8_t size) {
	uint8_t* txBuf = new uint8_t[size];
	memcpy(txBuf, data, size);

	pendingTransfers.push_back({
		.buf = txBuf,
		.len = size
	});
    
    startTransfer();
}


void pc::sendCommand(const pc::Command& command) {
	send((uint8_t*)&command, sizeof(pc::Command));
}


static void startTransfer() {
	if ((SERCOM_REGS->USART_INT.SERCOM_STATUS & SERCOM_USART_INT_STATUS_CTS_Msk)
					|| DMAC_REGS->DMAC_ACTIVE & DMAC_ACTIVE_ABUSY_Msk) {
		return; // SERCOM/DMA busy, cannot start another transfer
	} else if (pendingTransfers.empty()) {
		return; // No pending transfer
	}

	UARTTransfer transfer{pendingTransfers.front()};

    DMAC_REGS->DMAC_CHID = DMA_CH_CPU_TX;
    dma::DESCRIPTOR_TABLE[DMA_CH_CPU_TX].DMAC_BTCNT = transfer.len;
    dma::DESCRIPTOR_TABLE[DMA_CH_CPU_TX].DMAC_SRCADDR = (uint32_t)(transfer.buf + transfer.len);
    dma::DESCRIPTOR_TABLE[DMA_CH_CPU_TX].DMAC_DSTADDR = (uint32_t) & SERCOM_REGS->USART_INT.SERCOM_DATA;
    DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(1);
}


uint8_t pc::dataReceived() {
    return bytesReceived;
}


uint8_t* pc::getData() {
    bytesReceived = 0;
    return incomingData;
}
