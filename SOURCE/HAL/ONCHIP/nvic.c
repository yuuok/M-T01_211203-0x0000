#ifndef _NVIC_C_
#define _NVIC_C_

#include "nvic.h"

void Nvic_Init(void)
{
	NVIC_InitTypeDef nvicInitStruct;
	EXTI_InitTypeDef extiInitStruct;
#if NVIC_TIM_2_IRQ_ENABLE
	nvicInitStruct.NVIC_IRQChannel = TIM2_IRQn;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_TIM_2_IRQ_PREEMPTIONPRIORITY;
	nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_TIM_2_IRQ_SUBPRIORITY;
	nvicInitStruct.NVIC_IRQChannelCmd = NVIC_TIM_2_IRQ_ENABLE;
	NVIC_Init(&nvicInitStruct);
#endif
#if NVIC_TIM_3_IRQ_ENABLE
	nvicInitStruct.NVIC_IRQChannel = TIM3_IRQn;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_TIM_3_IRQ_PREEMPTIONPRIORITY;
	nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_TIM_3_IRQ_SUBPRIORITY;
	nvicInitStruct.NVIC_IRQChannelCmd = NVIC_TIM_3_IRQ_ENABLE;
	NVIC_Init(&nvicInitStruct);
#endif
#if NVIC_TIM_4_IRQ_ENABLE
	nvicInitStruct.NVIC_IRQChannel = TIM4_IRQn;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_TIM_4_IRQ_PREEMPTIONPRIORITY;
	nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_TIM_4_IRQ_SUBPRIORITY;
	nvicInitStruct.NVIC_IRQChannelCmd = NVIC_TIM_4_IRQ_ENABLE;
	NVIC_Init(&nvicInitStruct);
#endif
#if NVIC_TIM_5_IRQ_ENABLE
	nvicInitStruct.NVIC_IRQChannel = TIM5_IRQn;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_TIM_5_IRQ_PREEMPTIONPRIORITY;
	nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_TIM_5_IRQ_SUBPRIORITY;
	nvicInitStruct.NVIC_IRQChannelCmd = NVIC_TIM_5_IRQ_ENABLE;
	NVIC_Init(&nvicInitStruct);
#endif

#if NVIC_EXTI_0_IRQ_ENABLE
	nvicInitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_EXTI_0_IRQ_PREEMPTIONPRIORITY;
	nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_EXTI_0_IRQ_SUBPRIORITY;
	nvicInitStruct.NVIC_IRQChannelCmd = NVIC_EXTI_0_IRQ_ENABLE;
	NVIC_Init(&nvicInitStruct);
#if NVIC_EXTI_0_IRQ_LINE_SELECT
	extiInitStruct.EXTI_Line = EXTI_Line0;
	extiInitStruct.EXTI_Mode = NVIC_EXTI_0_IRQ_MODE;
	extiInitStruct.EXTI_Trigger = NVIC_EXTI_0_IRQ_TRIGGEER;
	extiInitStruct.EXTI_LineCmd = NVIC_EXTI_0_IRQ_LINE_SELECT;
	EXTI_Init(&extiInitStruct);
#endif

#endif

#if NVIC_EXTI_1_IRQ_ENABLE
	nvicInitStruct.NVIC_IRQChannel = EXTI1_IRQn;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_EXTI_1_IRQ_PREEMPTIONPRIORITY;
	nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_EXTI_1_IRQ_SUBPRIORITY;
	nvicInitStruct.NVIC_IRQChannelCmd = NVIC_EXTI_1_IRQ_ENABLE;
	NVIC_Init(&nvicInitStruct);
#if NVIC_EXTI_1_IRQ_LINE_SELECT
	extiInitStruct.EXTI_Line = EXTI_Line1;
	extiInitStruct.EXTI_Mode = NVIC_EXTI_1_IRQ_MODE;
	extiInitStruct.EXTI_Trigger = NVIC_EXTI_1_IRQ_TRIGGEER;
	extiInitStruct.EXTI_LineCmd = NVIC_EXTI_1_IRQ_LINE_SELECT;
	EXTI_Init(&extiInitStruct);
#endif
#endif
#if NVIC_EXTI_2_IRQ_ENABLE
	nvicInitStruct.NVIC_IRQChannel = EXTI2_IRQn;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_EXTI_2_IRQ_PREEMPTIONPRIORITY;
	nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_EXTI_2_IRQ_SUBPRIORITY;
	nvicInitStruct.NVIC_IRQChannelCmd = NVIC_EXTI_2_IRQ_ENABLE;
	NVIC_Init(&nvicInitStruct);
#if NVIC_EXTI_2_IRQ_LINE_SELECT
	extiInitStruct.EXTI_Line = EXTI_Line2;
	extiInitStruct.EXTI_Mode = NVIC_EXTI_2_IRQ_MODE;
	extiInitStruct.EXTI_Trigger = NVIC_EXTI_2_IRQ_TRIGGEER;
	extiInitStruct.EXTI_LineCmd = NVIC_EXTI_2_IRQ_LINE_SELECT;
	EXTI_Init(&extiInitStruct);
#endif
#endif
#if NVIC_EXTI_3_IRQ_ENABLE
	nvicInitStruct.NVIC_IRQChannel = EXTI3_IRQn;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_EXTI_3_IRQ_PREEMPTIONPRIORITY;
	nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_EXTI_3_IRQ_SUBPRIORITY;
	nvicInitStruct.NVIC_IRQChannelCmd = NVIC_EXTI_3_IRQ_ENABLE;
	NVIC_Init(&nvicInitStruct);
#if NVIC_EXTI_3_IRQ_LINE_SELECT
	extiInitStruct.EXTI_Line = EXTI_Line3;
	extiInitStruct.EXTI_Mode = NVIC_EXTI_3_IRQ_MODE;
	extiInitStruct.EXTI_Trigger = NVIC_EXTI_3_IRQ_TRIGGEER;
	extiInitStruct.EXTI_LineCmd = NVIC_EXTI_3_IRQ_LINE_SELECT;
	EXTI_Init(&extiInitStruct);
#endif
#endif
#if NVIC_EXTI_4_IRQ_ENABLE
	nvicInitStruct.NVIC_IRQChannel = EXTI4_IRQn;
	nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_EXTI_4_IRQ_PREEMPTIONPRIORITY;
	nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_EXTI_4_IRQ_SUBPRIORITY;
	nvicInitStruct.NVIC_IRQChannelCmd = NVIC_EXTI_4_IRQ_ENABLE;
	NVIC_Init(&nvicInitStruct);
#if NVIC_EXTI_4_IRQ_LINE_SELECT
	extiInitStruct.EXTI_Line = EXTI_Line4;
	extiInitStruct.EXTI_Mode = NVIC_EXTI_4_IRQ_MODE;
	extiInitStruct.EXTI_Trigger = NVIC_EXTI_4_IRQ_TRIGGEER;
	extiInitStruct.EXTI_LineCmd = NVIC_EXTI_4_IRQ_LINE_SELECT;
	EXTI_Init(&extiInitStruct);
#endif
#endif
#if NVIC_EXTI_9_5_IRQ_ENABLE
		nvicInitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
		nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_EXTI_9_5_IRQ_PREEMPTIONPRIORITY;
		nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_EXTI_9_5_IRQ_SUBPRIORITY;
		nvicInitStruct.NVIC_IRQChannelCmd = NVIC_EXTI_9_5_IRQ_ENABLE;
		NVIC_Init(&nvicInitStruct);
#endif
#if NVIC_EXTI_15_10_IRQ_ENABLE
		nvicInitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
		nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_EXTI_15_10_IRQ_PREEMPTIONPRIORITY;
		nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_EXTI_15_10_IRQ_SUBPRIORITY;
		nvicInitStruct.NVIC_IRQChannelCmd = NVIC_EXTI_15_10_IRQ_ENABLE;
		NVIC_Init(&nvicInitStruct);
#endif

#if NVIC_USART_1_IRQ_ENABLE
		nvicInitStruct.NVIC_IRQChannel = USART1_IRQn;
		nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_USART_1_IRQ_PREEMPTIONPRIORITY;
		nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_USART_1_IRQ_SUBPRIORITY;
		nvicInitStruct.NVIC_IRQChannelCmd = NVIC_USART_1_IRQ_ENABLE;
		NVIC_Init(&nvicInitStruct);
#endif
#if NVIC_USART_2_IRQ_ENABLE
		nvicInitStruct.NVIC_IRQChannel = USART2_IRQn;
		nvicInitStruct.NVIC_IRQChannelPreemptionPriority = NVIC_USART_2_IRQ_PREEMPTIONPRIORITY;
		nvicInitStruct.NVIC_IRQChannelSubPriority = NVIC_USART_2_IRQ_SUBPRIORITY;
		nvicInitStruct.NVIC_IRQChannelCmd = NVIC_USART_2_IRQ_ENABLE;
		NVIC_Init(&nvicInitStruct);
#endif
}

#endif
