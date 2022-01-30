#ifndef _EVENT_H_
#define _EVENT_H_

#include "common.h"
#include "parameters.h"
#include "stm32f10x_usart.h"
#include "formatPrint.h"
#include "motorControl.h"

void TIM2_Update_Handler(void);
void TIM2_CC1_Handler(void);
void TIM2_CC2_Handler(void);
void TIM2_CC3_Handler(void);
void TIM2_CC4_Handler(void);
void TIM2_COM_Handler(void);
void TIM2_Trigger_Handler(void);
void TIM2_Break_Handler(void);

void TIM3_Update_Handler(void);
void TIM3_CC1_Handler(void);
void TIM3_CC2_Handler(void);
void TIM3_CC3_Handler(void);
void TIM3_CC4_Handler(void);
void TIM3_COM_Handler(void);
void TIM3_Trigger_Handler(void);
void TIM3_Break_Handler(void);

void TIM4_Update_Handler(void);
void TIM4_CC1_Handler(void);
void TIM4_CC2_Handler(void);
void TIM4_CC3_Handler(void);
void TIM4_CC4_Handler(void);
void TIM4_COM_Handler(void);
void TIM4_Trigger_Handler(void);
void TIM4_Break_Handler(void);

void TIM5_Update_Handler(void);
void TIM5_CC1_Handler(void);
void TIM5_CC2_Handler(void);
void TIM5_CC3_Handler(void);
void TIM5_CC4_Handler(void);
void TIM5_COM_Handler(void);
void TIM5_Trigger_Handler(void);
void TIM5_Break_Handler(void);

void EXTI_Line_0_Handler(void);
void EXTI_Line_1_Handler(void);
void EXTI_Line_2_Handler(void);
void EXTI_Line_3_Handler(void);
void EXTI_Line_4_Handler(void);
void EXTI_Line_5_Handler(void);
void EXTI_Line_6_Handler(void);
void EXTI_Line_7_Handler(void);
void EXTI_Line_8_Handler(void);
void EXTI_Line_9_Handler(void);
void EXTI_Line_10_Handler(void);
void EXTI_Line_11_Handler(void);
void EXTI_Line_12_Handler(void);
void EXTI_Line_13_Handler(void);
void EXTI_Line_14_Handler(void);
void EXTI_Line_15_Handler(void);
void EXTI_Line_16_Handler(void);
void EXTI_Line_17_Handler(void);
void EXTI_Line_18_Handler(void);
void EXTI_Line_19_Handler(void);

#endif

