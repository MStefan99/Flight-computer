/* 
 * File:   dma.h
 * Author: mikha
 *
 * Created on November 28, 2021, 1:42 PM
 */

#ifndef DMA_H
#define	DMA_H

#include "device.h"
#include "lib/inc/list.h"


#define DMA_CH_COUNT 4

#define DMA_CH_I2C_TX 0
#define DMA_CH_I2C_RX 1
#define DMA_CH_CPU_TX 2
#define DMA_CH_CPU_RX 3


namespace dma {
	extern dmac_descriptor_registers_t DESCRIPTOR_TABLE[];
	extern dmac_descriptor_registers_t WRITE_BACK_DESCRIPTOR_TABLE[];


	// Interrupts are cleared automatically for the following handlers
	extern void I2C_TCMPL_Handler();
	extern void UART_TCMPL_Handler();

	enum I2CTransferType : uint8_t {
		Read,
		Write,
		WriteRead
	};

	typedef struct __attribute__((packed)) {
		uint8_t devAddr;
		uint8_t regAddr;
		uint8_t* buf;
		uint8_t len;
		I2CTransferType type;
		sercom_registers_t* sercom;
	}
	I2CTransfer;

	typedef struct __attribute__((packed)) {
		uint8_t* buf;
		uint8_t len;
		sercom_registers_t* sercom;
	}
	UARTTransfer;


	void initI2C();
	void initUART();


	// The following functions are for internal use only, don't call them!
	void startTransfer(const I2CTransfer& transfer);
	void startTransfer(const UARTTransfer& transfer);
}

#endif	/* DMA_H */

