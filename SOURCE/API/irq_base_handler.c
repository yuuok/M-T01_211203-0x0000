#ifndef _IRQ_BASE_HANDLER_C_
#define _IRQ_BASE_HANDLER_C_

#include "irq_base_handler.h"


void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update))
	{
		TIM2_Update_Handler();
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	if(TIM_GetITStatus(TIM2, TIM_IT_CC1))
	{
		TIM2_CC1_Handler();
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);

	if(TIM_GetITStatus(TIM2, TIM_IT_CC2))
	{
		TIM2_CC2_Handler();
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);

	if(TIM_GetITStatus(TIM2, TIM_IT_CC3))
	{
		TIM2_CC3_Handler();
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_CC3);

	if(TIM_GetITStatus(TIM2, TIM_IT_CC4))
	{
		TIM2_CC4_Handler();
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_CC4);

	if(TIM_GetITStatus(TIM2, TIM_IT_COM))
	{
		TIM2_COM_Handler();
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_COM);

	if(TIM_GetITStatus(TIM2, TIM_IT_Trigger))
	{
		TIM2_Trigger_Handler();
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_Trigger);

	if(TIM_GetITStatus(TIM2, TIM_IT_Break))
	{
		TIM2_Break_Handler();
	}
	TIM_ClearITPendingBit(TIM2, (TIM2, TIM_IT_Break));
}


void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update))
	{
		TIM3_Update_Handler();
	}
	TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

	if(TIM_GetITStatus(TIM3, TIM_IT_CC1))
	{
		TIM3_CC1_Handler();
	}
	TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);

	if(TIM_GetITStatus(TIM3, TIM_IT_CC2))
	{
		TIM3_CC2_Handler();
	}
	TIM_ClearITPendingBit(TIM3, TIM_IT_CC2);

	if(TIM_GetITStatus(TIM3, TIM_IT_CC3))
	{
		TIM3_CC3_Handler();
	}
	TIM_ClearITPendingBit(TIM3, TIM_IT_CC3);

	if(TIM_GetITStatus(TIM3, TIM_IT_CC4))
	{
		TIM3_CC4_Handler();
	}
	TIM_ClearITPendingBit(TIM3, TIM_IT_CC4);

	if(TIM_GetITStatus(TIM3, TIM_IT_COM))
	{
		TIM3_COM_Handler();
	}
	TIM_ClearITPendingBit(TIM3, TIM_IT_COM);

	if(TIM_GetITStatus(TIM3, TIM_IT_Trigger))
	{
		TIM3_Trigger_Handler();
	}
	TIM_ClearITPendingBit(TIM3, TIM_IT_Trigger);

	if(TIM_GetITStatus(TIM3, TIM_IT_Break))
	{
		TIM3_Break_Handler();
	}
	TIM_ClearITPendingBit(TIM3, (TIM3, TIM_IT_Break));
}


void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update))
	{
		TIM4_Update_Handler();
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);

	if(TIM_GetITStatus(TIM4, TIM_IT_CC1))
	{
		TIM4_CC1_Handler();
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_CC1);

	if(TIM_GetITStatus(TIM4, TIM_IT_CC2))
	{
		TIM4_CC2_Handler();
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_CC2);

	if(TIM_GetITStatus(TIM4, TIM_IT_CC3))
	{
		TIM4_CC3_Handler();
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_CC3);

	if(TIM_GetITStatus(TIM4, TIM_IT_CC4))
	{
		TIM4_CC4_Handler();
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_CC4);

	if(TIM_GetITStatus(TIM4, TIM_IT_COM))
	{
		TIM4_COM_Handler();
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_COM);

	if(TIM_GetITStatus(TIM4, TIM_IT_Trigger))
	{
		TIM4_Trigger_Handler();
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_Trigger);

	if(TIM_GetITStatus(TIM4, TIM_IT_Break))
	{
		TIM4_Break_Handler();
	}
	TIM_ClearITPendingBit(TIM4, (TIM4, TIM_IT_Break));
}

void TIM5_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM5, TIM_IT_Update))
	{
		TIM5_Update_Handler();
	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_Update);

	if(TIM_GetITStatus(TIM5, TIM_IT_CC1))
	{
		TIM5_CC1_Handler();
	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_CC1);

	if(TIM_GetITStatus(TIM5, TIM_IT_CC2))
	{
		TIM5_CC2_Handler();
	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_CC2);

	if(TIM_GetITStatus(TIM5, TIM_IT_CC3))
	{
		TIM5_CC3_Handler();
	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_CC3);

	if(TIM_GetITStatus(TIM5, TIM_IT_CC4))
	{
		TIM5_CC4_Handler();
	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_CC4);

	if(TIM_GetITStatus(TIM5, TIM_IT_COM))
	{
		TIM5_COM_Handler();
	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_COM);

	if(TIM_GetITStatus(TIM5, TIM_IT_Trigger))
	{
		TIM5_Trigger_Handler();
	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_Trigger);

	if(TIM_GetITStatus(TIM5, TIM_IT_Break))
	{
		TIM5_Break_Handler();
	}
	TIM_ClearITPendingBit(TIM5, (TIM5, TIM_IT_Break));
}


void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0))
	{
		EXTI_Line_0_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}
void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1))
	{
		EXTI_Line_1_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line1);
}
void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2))
	{
		EXTI_Line_2_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}
void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3))
	{
		EXTI_Line_3_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4))
	{
		EXTI_Line_4_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
}
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line5))
	{
		EXTI_Line_5_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line5);
	
	if(EXTI_GetITStatus(EXTI_Line6))
	{
		EXTI_Line_6_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line6);
	
	if(EXTI_GetITStatus(EXTI_Line7))
	{
		EXTI_Line_7_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line7);
	
	if(EXTI_GetITStatus(EXTI_Line8))
	{
		EXTI_Line_8_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line8);
	
	if(EXTI_GetITStatus(EXTI_Line9))
	{
		EXTI_Line_9_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line9);
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line10))
	{
		EXTI_Line_10_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line10);

	if(EXTI_GetITStatus(EXTI_Line11))
	{
		EXTI_Line_11_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line11);

	if(EXTI_GetITStatus(EXTI_Line12))
	{
		EXTI_Line_12_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line12);

	if(EXTI_GetITStatus(EXTI_Line13))
	{
		EXTI_Line_13_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line13);

	if(EXTI_GetITStatus(EXTI_Line14))
	{
		EXTI_Line_14_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line14);

	if(EXTI_GetITStatus(EXTI_Line15))
	{
		EXTI_Line_15_Handler();
	}
	EXTI_ClearITPendingBit(EXTI_Line15);

}


void DMA1_Channel1_IRQHandler(void)
{
	if(DMA_GetITStatus(DMA1_IT_TC1) != RESET)
	{

		if(ADCFlag>0)
		{
			ADCFlag = 0;
			Mc_ShuntCurrent_Raw_C = ADC_Convertedvalue;
			Adc_SetTo_CC1();
		}
		else
		{
			ADCFlag = 1;
			Mc_ShuntCurrent_Raw_A = ADC_Convertedvalue;
			Adc_SetTo_CC3();
		}
	}
	DMA_ClearITPendingBit(DMA1_IT_TC1);
}

#endif

