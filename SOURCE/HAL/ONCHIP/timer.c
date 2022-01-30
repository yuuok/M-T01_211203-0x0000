#ifndef _TIMER_C_
#define _TIMER_C_

#include "timer.h"

void Timer2_Init(void)
{
	TIM_TimeBaseInitTypeDef timeBaseInitStruce;
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_TIM2EN, TIMER_2_INIT_ENABLE);
	timeBaseInitStruce.TIM_Prescaler = TIMER_2_PRESCALER;
	timeBaseInitStruce.TIM_CounterMode = TIMER_2_COUNT_MODE;
	timeBaseInitStruce.TIM_Period = TIMER_2_PERIOD;
	timeBaseInitStruce.TIM_ClockDivision = TIMER_2_CLOCKDIVISION;
	TIM_TimeBaseInit(TIM2, &timeBaseInitStruce);
	TIM_ITConfig(TIM2, TIM_IT_Update, TIMER_2_IRQ_ENABLE);
	TIM_Cmd(TIM2, TIMER_2_IRQ_ENABLE);
}

#endif

