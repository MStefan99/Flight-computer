/* 
 * File:   dma.h
 * Author: mikha
 *
 * Created on November 28, 2021, 1:42 PM
 */

#ifndef DMA_H
#define	DMA_H

#include "device.h"


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
	
	void initI2C();
	void initUART();
}

#endif	/* DMA_H */

