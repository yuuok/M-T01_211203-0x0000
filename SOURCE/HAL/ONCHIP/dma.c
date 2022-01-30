#ifndef DMA_C
#define DMA_C

#include "dma.h"


#define ADC1_DR_Address 0x4001244C
volatile u16 ADC_Convertedvalue = 0;



void Dma_Init(void)
{
	DMA_InitTypeDef dma_initStruct;
	NVIC_InitTypeDef nvic_initStruct;
	DMA_DeInit(DMA1_Channel1);
	dma_initStruct.DMA_PeripheralBaseAddr = ADC1_DR_Address;
	dma_initStruct.DMA_MemoryBaseAddr = (u32)&ADC_Convertedvalue;
	dma_initStruct.DMA_DIR =DMA_DIR_PeripheralSRC;
	dma_initStruct.DMA_BufferSize = 1;
	dma_initStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	dma_initStruct.DMA_MemoryInc = DMA_MemoryInc_Disable;
	dma_initStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	dma_initStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	dma_initStruct.DMA_Mode = DMA_Mode_Circular;
	dma_initStruct.DMA_Priority = DMA_Priority_High;
	dma_initStruct.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &dma_initStruct);
	nvic_initStruct.NVIC_IRQChannel = DMA1_Channel1_IRQn;
	nvic_initStruct.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_initStruct.NVIC_IRQChannelSubPriority =0;
	nvic_initStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_initStruct);
	DMA_ITConfig(DMA1_Channel1, DMA1_IT_TC1, ENABLE);
	DMA_Cmd(DMA1_Channel1, ENABLE);
}







#endif
