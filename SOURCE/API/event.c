#ifndef _EVENT_C_
#define _EVENT_C_

#include "event.h"


void TIM2_Update_Handler(void)
{
	//Mc_Svpwm();
	Mc_FocMainFunc();
	if(Common_Delay_Struct.startFlag_ms > 0)
	{
		if(Common_Delay_Struct.count_1ms > 0)
		{
			Common_Delay_Struct.count_1ms--;
		}else
		{
			Common_Delay_Struct.startFlag_ms = 0;
			Common_Delay_Struct.doneFlag_ms = 1;
		}
	}else
	{
		Common_Delay_Struct.count_1ms = 10;
	}

	if(PAR_TimeFlag_1ms > 0)
	{
		PAR_TimeFlag_1ms--;
	}
	if(PAR_TimeFlag_5ms > 0)
	{
		PAR_TimeFlag_5ms--;
	}
	if(PAR_TimeFlag_10ms > 0)
	{
		PAR_TimeFlag_10ms--;
	}
	if(PAR_TimeFlag_10_5ms > 0)
	{
		PAR_TimeFlag_10_5ms--;
	}
	if(PAR_TimeFlag_50ms > 0)
	{
		PAR_TimeFlag_50ms--;
	}
	if(PAR_TimeFlag_100ms > 0)
	{
		PAR_TimeFlag_100ms--;
	}
	

}
void TIM2_CC1_Handler(void)
{
}
void TIM2_CC2_Handler(void)
{
}
void TIM2_CC3_Handler(void)
{
}
void TIM2_CC4_Handler(void)
{
}
void TIM2_COM_Handler(void)
{
}
void TIM2_Trigger_Handler(void)
{
}
void TIM2_Break_Handler(void)
{
}


void TIM3_Update_Handler(void)
{
}
void TIM3_CC1_Handler(void)
{
}
void TIM3_CC2_Handler(void)
{
}
void TIM3_CC3_Handler(void)
{
}
void TIM3_CC4_Handler(void)
{
}
void TIM3_COM_Handler(void)
{
}
void TIM3_Trigger_Handler(void)
{
}
void TIM3_Break_Handler(void)
{
}


void TIM4_Update_Handler(void)
{

}
void TIM4_CC1_Handler(void)
{
}
void TIM4_CC2_Handler(void)
{
}
void TIM4_CC3_Handler(void)
{
}
void TIM4_CC4_Handler(void)
{
}
void TIM4_COM_Handler(void)
{
}
void TIM4_Trigger_Handler(void)
{
}
void TIM4_Break_Handler(void)
{
}

void TIM5_Update_Handler(void)
{
	//Led_Toggle(&Led_1_struct);
}
uint16 PeriodValue;
uint16 DutyValue;
uint16 DutyCycle;
void TIM5_CC1_Handler(void)
{
	/*
	PeriodValue = TIM_GetCapture1(TIM5);
	*/
}
void TIM5_CC2_Handler(void)
{
	/*
	Led_Toggle(&Led_1_struct);
	DutyValue = TIM_GetCapture2(TIM5);
	DutyCycle = DutyValue*1000/PeriodValue;
	*/
}
void TIM5_CC3_Handler(void)
{
}
void TIM5_CC4_Handler(void)
{
}
void TIM5_COM_Handler(void)
{
}
void TIM5_Trigger_Handler(void)
{
}
void TIM5_Break_Handler(void)
{
}


void EXTI_Line_0_Handler(void)
{
}
void EXTI_Line_1_Handler(void)
{
}
void EXTI_Line_2_Handler(void)
{
}
void EXTI_Line_3_Handler(void)
{
}
void EXTI_Line_4_Handler(void)
{
}
void EXTI_Line_5_Handler(void)
{
}
void EXTI_Line_6_Handler(void)
{
}
void EXTI_Line_7_Handler(void)
{
}
void EXTI_Line_8_Handler(void)
{
}
void EXTI_Line_9_Handler(void)
{
}
void EXTI_Line_10_Handler(void)
{
}
void EXTI_Line_11_Handler(void)
{
}
void EXTI_Line_12_Handler(void)
{
}
void EXTI_Line_13_Handler(void)
{
}
void EXTI_Line_14_Handler(void)
{
}
void EXTI_Line_15_Handler(void)
{
}
void EXTI_Line_16_Handler(void)
{
}
void EXTI_Line_17_Handler(void)
{
}
void EXTI_Line_18_Handler(void)
{
}
void EXTI_Line_19_Handler(void)
{
}

#endif

