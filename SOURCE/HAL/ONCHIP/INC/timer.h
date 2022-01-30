#ifndef _TIMER_H_
#define _TIMER_H_

#include "common.h"
#include "rcc.h"
#include "stm32f10x_tim.h"
#include "misc.h"

//////////////////////////////WARNING//////////////////////////////////////
#ifndef ENABLE
#define ENABLE                                  1
#define DISABLE                                 0
#endif
///////////////////////////////////////////////////////////////////////////

#define TIM_CLK									72

#define PERIOD_STEP_US(x)						((TIM_CLK * x) - 1)
#define PERIOD_DESIRED_US(x)					(x)
////////////////////////////COMMON TIMER SELECT////////////////////////////
///////////TIMER2
#define TIMER_2_INIT_ENABLE  					ENABLE
#define TIMER_2_PRESCALER						PERIOD_STEP_US(1)
#define TIMER_2_PERIOD							100
#define TIMER_2_COUNT_MODE						TIM_CounterMode_Up
#define TIMER_2_CLOCKDIVISION					TIM_CKD_DIV1
//TIMER2_IRQ
#define TIMER_2_IRQ_ENABLE						ENABLE
#define TIMER_2_IRQ_PREEMPTIONPRIORITY			2
#define TIMER_2_IRQ_SUBPRIORITY					3
#define TIMER_2_IRQ_UPDATE						ENABLE
#define TIMER_2_IRQ_TRIGGER						DISABLE
#define TIMER_2_IRQ_BREAK						DISABLE
/////////////

void Timer2_Init(void);



#endif

