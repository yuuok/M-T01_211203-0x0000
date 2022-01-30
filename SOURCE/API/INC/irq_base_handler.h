#ifndef _IRQ_BASE_HANDLER_H_
#define _IRQ_BASE_HANDLER_H_

#include "common.h"
#include "event.h"
#include "stm32f10x_tim.h"
#include "formatPrint.h"
#include "misc.h"

void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
void TIM5_IRQHandler(void);

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);

void DMA1_Channel1_IRQHandler(void);


#endif

