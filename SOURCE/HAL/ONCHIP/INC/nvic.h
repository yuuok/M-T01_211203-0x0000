#ifndef _NVIC_H_
#define _NVIC_H_

#include "misc.h"
#include "common.h"
#include "stm32f10x_exti.h"
#include "gpio.h"


//////////////////////////////WARNING////////////////////////
#ifndef ENABLE
#define ENABLE                                  1
#define DISABLE                                 0
#endif
/////////////////////////////////////////////////////////////


///////////////////////////COM_TIM///////////////////////////
#define NVIC_TIM_2_IRQ_ENABLE 					ENABLE
#define NVIC_TIM_2_IRQ_PREEMPTIONPRIORITY		2
#define NVIC_TIM_2_IRQ_SUBPRIORITY				3

#define NVIC_TIM_3_IRQ_ENABLE 					DISABLE
#define NVIC_TIM_3_IRQ_PREEMPTIONPRIORITY		2
#define NVIC_TIM_3_IRQ_SUBPRIORITY				3

#define NVIC_TIM_4_IRQ_ENABLE 					DISABLE
#define NVIC_TIM_4_IRQ_PREEMPTIONPRIORITY		2
#define NVIC_TIM_4_IRQ_SUBPRIORITY				3

#define NVIC_TIM_5_IRQ_ENABLE 					DISABLE
#define NVIC_TIM_5_IRQ_PREEMPTIONPRIORITY		2
#define NVIC_TIM_5_IRQ_SUBPRIORITY				3

/////////////////////////////////////////////////////////////


/////////////////////////////EXTI////////////////////////////
//////////////EXTI0
#define NVIC_EXTI_0_IRQ_ENABLE 					DISABLE
#define NVIC_EXTI_0_IRQ_PREEMPTIONPRIORITY		2
#define NVIC_EXTI_0_IRQ_SUBPRIORITY				3
////EXTI_LINE0
#define NVIC_EXTI_0_IRQ_LINE_SELECT				DISABLE
#define NVIC_EXTI_0_IRQ_MODE					EXTI_Mode_Interrupt
#define NVIC_EXTI_0_IRQ_TRIGGEER				EXTI_Trigger_Rising

//////////////EXTI1
#define NVIC_EXTI_1_IRQ_ENABLE 					DISABLE
#define NVIC_EXTI_1_IRQ_PREEMPTIONPRIORITY		2
#define NVIC_EXTI_1_IRQ_SUBPRIORITY				2
////EXTI_LINE1
#define NVIC_EXTI_1_IRQ_LINE_SELECT				DISABLE
#define NVIC_EXTI_1_IRQ_MODE					EXTI_Mode_Interrupt
#define NVIC_EXTI_1_IRQ_TRIGGEER				EXTI_Trigger_Rising

//////////////EXTI2
#define NVIC_EXTI_2_IRQ_ENABLE 					DISABLE
#define NVIC_EXTI_2_IRQ_PREEMPTIONPRIORITY		2
#define NVIC_EXTI_2_IRQ_SUBPRIORITY				2
////EXTI_LINE2
#define NVIC_EXTI_2_IRQ_LINE_SELECT				DISABLE
#define NVIC_EXTI_2_IRQ_MODE					EXTI_Mode_Interrupt
#define NVIC_EXTI_2_IRQ_TRIGGEER				EXTI_Trigger_Falling

//////////////EXTI3
#define NVIC_EXTI_3_IRQ_ENABLE 					DISABLE
#define NVIC_EXTI_3_IRQ_PREEMPTIONPRIORITY		2
#define NVIC_EXTI_3_IRQ_SUBPRIORITY				1
////EXTI_LINE3
#define NVIC_EXTI_3_IRQ_LINE_SELECT				DISABLE
#define NVIC_EXTI_3_IRQ_MODE					EXTI_Mode_Interrupt
#define NVIC_EXTI_3_IRQ_TRIGGEER				EXTI_Trigger_Falling

//////////////EXTI4
#define NVIC_EXTI_4_IRQ_ENABLE 					DISABLE
#define NVIC_EXTI_4_IRQ_PREEMPTIONPRIORITY		2
#define NVIC_EXTI_4_IRQ_SUBPRIORITY				0
////EXTI_LINE4
#define NVIC_EXTI_4_IRQ_LINE_SELECT				DISABLE
#define NVIC_EXTI_4_IRQ_MODE					EXTI_Mode_Interrupt
#define NVIC_EXTI_4_IRQ_TRIGGEER				EXTI_Trigger_Falling

//////////////EXTI5~9
#define NVIC_EXTI_9_5_IRQ_ENABLE 				DISABLE
#define NVIC_EXTI_9_5_IRQ_PREEMPTIONPRIORITY	2
#define NVIC_EXTI_9_5_IRQ_SUBPRIORITY			3
//////////////EXTI10~15
#define NVIC_EXTI_15_10_IRQ_ENABLE 				DISABLE
#define NVIC_EXTI_15_10_IRQ_PREEMPTIONPRIORITY	2
#define NVIC_EXTI_15_10_IRQ_SUBPRIORITY			3
/////////////////////////////////////////////////////////////


///////////////////////////USART(1-5)///////////////////////////
#define NVIC_USART_1_IRQ_ENABLE 					ENABLE
#define NVIC_USART_1_IRQ_PREEMPTIONPRIORITY			3
#define NVIC_USART_1_IRQ_SUBPRIORITY				2

#define NVIC_USART_2_IRQ_ENABLE 					ENABLE
#define NVIC_USART_2_IRQ_PREEMPTIONPRIORITY			3
#define NVIC_USART_2_IRQ_SUBPRIORITY				3
/////////////////////////////////////////////////////////////

void Nvic_Init(void);


#endif

