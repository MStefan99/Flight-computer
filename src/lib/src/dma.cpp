#include "lib/inc/dma.h"


dmac_descriptor_registers_t dma::DESCRIPTOR_TABLE[DMA_CH_COUNT];
dmac_descriptor_registers_t dma::WRITE_BACK_DESCRIPTOR_TABLE[DMA_CH_COUNT];


static bool transferOngoing {false};
static tl::allocator<uint8_t> byteAllocator {};


static tl::list<dma::I2CTransfer> pendingI2CTransfers{};
static tl::list<dma::UARTTransfer> pendingUARTTransfers{};


static void nextTransfer();
static void nextI2CTransfer();
static void nextUARTTransfer();


static void I2CStreamOut(const dma::I2CTransfer& transfer);
static void I2CStreamIn(const dma::I2CTransfer& transfer);


static void completeI2CTransfer();
static void completeUARTTransfer();


// Interrupt handlers
extern "C" {


	void DMA_Handler() {
		switch (DMAC_REGS->DMAC_INTPEND & DMAC_INTPEND_ID_Msk) {
			case 0:
			case 1:
				completeI2CTransfer();
				break;
			case 2:
			case 3:
				completeUARTTransfer();
				break;
		}
		nextTransfer();
		DMAC_REGS->DMAC_CHID = DMAC_REGS->DMAC_INTPEND & DMAC_INTPEND_ID_Msk;
		DMAC_REGS->DMAC_CHINTFLAG = DMAC_CHINTFLAG_Msk;
	}


	void I2C_Handler() {
		dma::I2CTransfer transfer{pendingI2CTransfers.front()};

		if (transfer.sercom->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_ERROR_Msk ||
						(transfer.sercom->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_RXNACK_Msk)) {
			completeI2CTransfer();
			nextTransfer();
			DMAC_REGS->DMAC_CHID = transfer.type == dma::I2CTransferType::Read ? DMA_CH_I2C_RX : DMA_CH_I2C_TX;
			transfer.sercom->I2CM.SERCOM_CTRLB = SERCOM_I2CM_CTRLB_CMD(3);
			DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(0);
		} else {
			static bool regAddrWritten{false};

			if (!regAddrWritten) {
				transfer.sercom->I2CM.SERCOM_DATA = transfer.regAddr;
				regAddrWritten = true;
			} else {
				I2CStreamIn(transfer);
				transfer.sercom->I2CM.SERCOM_INTENCLR = SERCOM_I2CM_INTENSET_MB(1);
				regAddrWritten = false;
			}
		}

		transfer.sercom->I2CM.SERCOM_INTFLAG = SERCOM_I2CM_INTFLAG_Msk;
	}
}


// Initialization


void dma::initI2C() {
	// DMA config
	DMAC_REGS->DMAC_BASEADDR = (uint32_t) dma::DESCRIPTOR_TABLE;
	DMAC_REGS->DMAC_WRBADDR = (uint32_t) dma::WRITE_BACK_DESCRIPTOR_TABLE;
	DMAC_REGS->DMAC_CTRL = DMAC_CTRL_LVLEN0(1)
					| DMAC_CTRL_DMAENABLE(1);

	// DMA I2C TX config
	DMAC_REGS->DMAC_CHID = DMA_CH_I2C_TX;
	DMAC_REGS->DMAC_CHCTRLB = DMAC_CHCTRLB_TRIGACT_BEAT
					| DMAC_CHCTRLB_TRIGSRC_SERCOM0_TX;
	DMAC_REGS->DMAC_CHINTENSET = DMAC_CHINTENSET_TCMPL(1) | DMAC_CHINTENSET_TERR(1);

	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_TX].DMAC_BTCTRL = DMAC_BTCTRL_BEATSIZE_BYTE
					| DMAC_BTCTRL_SRCINC(1)
					| DMAC_BTCTRL_VALID(1);

	// DMA I2C RX config
	DMAC_REGS->DMAC_CHID = DMA_CH_I2C_RX;
	DMAC_REGS->DMAC_CHCTRLB = DMAC_CHCTRLB_TRIGACT_BEAT
					| DMAC_CHCTRLB_TRIGSRC_SERCOM0_RX;
	DMAC_REGS->DMAC_CHINTENSET = DMAC_CHINTENSET_TCMPL(1) | DMAC_CHINTENSET_TERR(1);

	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_RX].DMAC_BTCTRL = DMAC_BTCTRL_BEATSIZE_BYTE
					| DMAC_BTCTRL_DSTINC(1)
					| DMAC_BTCTRL_VALID(1);

	// Interrupt config
	NVIC_EnableIRQ(DMAC_0_IRQn);
	NVIC_EnableIRQ(DMAC_1_IRQn);
}


void dma::initUART() {
	// DMA config
	DMAC_REGS->DMAC_BASEADDR = (uint32_t) dma::DESCRIPTOR_TABLE;
	DMAC_REGS->DMAC_WRBADDR = (uint32_t) dma::WRITE_BACK_DESCRIPTOR_TABLE;
	DMAC_REGS->DMAC_CTRL = DMAC_CTRL_LVLEN0(1)
					| DMAC_CTRL_DMAENABLE(1);

	// DMA I2C TX config
	DMAC_REGS->DMAC_CHID = DMA_CH_CPU_TX;
	DMAC_REGS->DMAC_CHCTRLB = DMAC_CHCTRLB_TRIGACT_BEAT
					| DMAC_CHCTRLB_TRIGSRC_SERCOM2_TX;
	DMAC_REGS->DMAC_CHINTENSET = DMAC_CHINTENSET_TCMPL(1) | DMAC_CHINTENSET_TERR(1);

	dma::DESCRIPTOR_TABLE[DMA_CH_CPU_TX].DMAC_BTCTRL = DMAC_BTCTRL_BEATSIZE_BYTE
					| DMAC_BTCTRL_SRCINC(1)
					| DMAC_BTCTRL_VALID(1);

	// DMA I2C RX config
	DMAC_REGS->DMAC_CHID = DMA_CH_CPU_RX;
	DMAC_REGS->DMAC_CHCTRLB = DMAC_CHCTRLB_TRIGACT_BEAT
					| DMAC_CHCTRLB_TRIGSRC_SERCOM2_RX;
	DMAC_REGS->DMAC_CHINTENSET = DMAC_CHINTENSET_TCMPL(1) | DMAC_CHINTENSET_TERR(1);

	dma::DESCRIPTOR_TABLE[DMA_CH_CPU_RX].DMAC_BTCTRL = DMAC_BTCTRL_BEATSIZE_BYTE
					| DMAC_BTCTRL_DSTINC(1)
					| DMAC_BTCTRL_VALID(1);

	// Interrupt config
	NVIC_EnableIRQ(DMAC_2_IRQn);
	NVIC_EnableIRQ(DMAC_3_IRQn);
}


static void nextTransfer() {
	// I2C gets priority but doesn't lock UART
	if (pendingUARTTransfers.size() > 5) {
		nextUARTTransfer();
	} else if (pendingI2CTransfers.size()) {
		nextI2CTransfer();
	} else if (pendingUARTTransfers.size()) {
		nextUARTTransfer();
	}
}


// I2C Transfers


void dma::startTransfer(const I2CTransfer& transfer) {
	pendingI2CTransfers.push_back(transfer);
	nextI2CTransfer();
}


static void nextI2CTransfer() {
	dma::I2CTransfer transfer{pendingI2CTransfers.front()};

	if (transferOngoing) {
		return; // SERCOM/DMA busy, cannot start another transfer
	}

	switch (transfer.type) {
		case dma::I2CTransferType::Read:
			I2CStreamIn(transfer);
			break;
		case dma::I2CTransferType::Write:
			I2CStreamOut(transfer);
			break;
		case dma::I2CTransferType::WriteRead:
			transfer.sercom->I2CM.SERCOM_INTENSET = SERCOM_I2CM_INTENSET_MB(1);
			transfer.sercom->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(transfer.devAddr << 1u);
			break;
	}
	
	transferOngoing = true;
}


static void I2CStreamOut(const dma::I2CTransfer& transfer) {
	DMAC_REGS->DMAC_CHID = DMA_CH_I2C_TX;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_TX].DMAC_BTCNT = transfer.len;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_TX].DMAC_SRCADDR = (uint32_t) (transfer.buf + transfer.len);
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_TX].DMAC_DSTADDR = (uint32_t) & transfer.sercom->I2CM.SERCOM_DATA;
	DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(1);

	transfer.sercom->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(transfer.devAddr << 1u)
					| SERCOM_I2CM_ADDR_LEN(transfer.len)
					| SERCOM_I2CM_ADDR_LENEN(1);
}


static void I2CStreamIn(const dma::I2CTransfer& transfer) {
	DMAC_REGS->DMAC_CHID = DMA_CH_I2C_RX;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_RX].DMAC_BTCNT = transfer.len;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_RX].DMAC_SRCADDR = (uint32_t) & transfer.sercom->I2CM.SERCOM_DATA;
	dma::DESCRIPTOR_TABLE[DMA_CH_I2C_RX].DMAC_DSTADDR = (uint32_t) (transfer.buf + transfer.len);
	DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(1);

	transfer.sercom->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(transfer.devAddr << 1u | 0x1)
					| SERCOM_I2CM_ADDR_LEN(transfer.len)
					| SERCOM_I2CM_ADDR_LENEN(1);
}


static void completeI2CTransfer() {
	dma::I2CTransfer transfer{pendingI2CTransfers.front()};
	if (transfer.type == dma::I2CTransferType::Write) {
		byteAllocator.deallocate(transfer.buf);
	}
	pendingI2CTransfers.pop_front();
	transferOngoing = false;
}


// UART transfers


void dma::startTransfer(const dma::UARTTransfer& transfer) {
	pendingUARTTransfers.push_back(transfer);
	nextUARTTransfer();
}


static void nextUARTTransfer() {
	dma::UARTTransfer transfer{pendingUARTTransfers.front()};

	if (transferOngoing) {
		return; // SERCOM/DMA busy, cannot start another transfer
	}

	DMAC_REGS->DMAC_CHID = DMA_CH_CPU_TX;
	dma::DESCRIPTOR_TABLE[DMA_CH_CPU_TX].DMAC_BTCNT = transfer.len;
	dma::DESCRIPTOR_TABLE[DMA_CH_CPU_TX].DMAC_SRCADDR = (uint32_t) (transfer.buf + transfer.len);
	dma::DESCRIPTOR_TABLE[DMA_CH_CPU_TX].DMAC_DSTADDR = (uint32_t) & transfer.sercom->USART_INT.SERCOM_DATA;
	DMAC_REGS->DMAC_CHCTRLA = DMAC_CHCTRLA_ENABLE(1);
	
	transferOngoing = true;
}


static void completeUARTTransfer() {
	dma::UARTTransfer transfer{pendingUARTTransfers.front()};
	byteAllocator.deallocate(transfer.buf);
	pendingUARTTransfers.pop_front();
	transferOngoing = false;
}
