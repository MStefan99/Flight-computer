/* 
 * File:   dma.h
 * Author: mikha
 *
 * Created on November 28, 2021, 1:42 PM
 */

#ifndef DMA_H
#define	DMA_H

#include "device.h"


#define DMA_CH_COUNT 1

#define DMA_CH_I2C_TX 0
#define DMA_CH_I2C_RX 1
#define DMA_CH_SPI_TX 2
#define DMA_CH_SPI_RX 3
#define DMA_CH_UART_TX 4
#define DMA_CH_UART_RX 5


namespace dma {
	extern dmac_descriptor_registers_t DESCRIPTOR_TABLE[];
	extern dmac_descriptor_registers_t WRITE_BACK_DESCRIPTOR_TABLE[];
	
	extern void I2C_TRCPT_Handler();
	
	void initI2C();
}

#endif	/* DMA_H */

