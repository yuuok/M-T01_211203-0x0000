#ifndef _PWMTIM1_C_
#define _PWMTIM1_C_


#include "pwmTim1.h"

void PwmTim1_DutySet(u16 duty1, u16 duty2, u16 duty3)
{
	u16 cmp1 = 0;
	u16 cmp2 = 0;
	u16 cmp3 = 0;
	if(duty1 > 1000)
	{
		duty1 = 1000;
	}
	if(duty2 > 1000)
	{
		duty2 = 1000;
	}
	if(duty3 > 1000)
	{
		duty3 = 1000;
	}
	cmp1 = (((u32)duty1) * PWM_FREQ) / 1000;
	cmp2 = (((u32)duty2) * PWM_FREQ) / 1000;
	cmp3 = (((u32)duty3) * PWM_FREQ) / 1000;
	TIM_SetCompare1(TIM1, cmp1);
	TIM_SetCompare2(TIM1, cmp2);
	TIM_SetCompare3(TIM1, cmp3);

	
}

void PwmTim1_BridgeSet(pwm_bridge_status OC1, pwm_bridge_status OC1N,
								pwm_bridge_status OC2, pwm_bridge_status OC2N,
								pwm_bridge_status OC3, pwm_bridge_status OC3N)
{
	switch(OC1)
	{
		case PWM_OFF:
			TIM1->CCER &= ~(1 << 0); 
			Gpio_Init(GPIO_PORT_A, GPIO_PIN_8, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_A, GPIO_PIN_8, Bit_RESET);
		break;
		case PWM_ON:
			TIM1->CCER &= ~(1 << 0); 
			Gpio_Init(GPIO_PORT_A, GPIO_PIN_8, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_A, GPIO_PIN_8, Bit_SET);
		break;
		case PWM_PWM:
			TIM1->CCER |=  (1 << 0); 
			Gpio_SetPort(GPIO_PORT_A, GPIO_PIN_8, Bit_RESET);
			Gpio_Init(GPIO_PORT_A, GPIO_PIN_8, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ);
		break;
	}
	switch(OC1N)
	{
		case PWM_OFF:
			TIM1->CCER &= ~(1 << 2); 
			Gpio_Init(GPIO_PORT_B, GPIO_PIN_13, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_B, GPIO_PIN_13, Bit_RESET);
		break;
		case PWM_ON:
			TIM1->CCER &= ~(1 << 2); 
			Gpio_Init(GPIO_PORT_B, GPIO_PIN_13, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_B, GPIO_PIN_13, Bit_SET);
		break;
		case PWM_PWM:
			TIM1->CCER |=  (1 << 2); 
			Gpio_SetPort(GPIO_PORT_B, GPIO_PIN_13, Bit_RESET);
			Gpio_Init(GPIO_PORT_B, GPIO_PIN_13, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ);
		break;
	}

	switch(OC2)
	{
		case PWM_OFF:
			TIM1->CCER &= ~(1 << 4); 
			Gpio_Init(GPIO_PORT_A, GPIO_PIN_9, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_A, GPIO_PIN_9, Bit_RESET);
		break;
		case PWM_ON:
			TIM1->CCER &= ~(1 << 4); 
			Gpio_Init(GPIO_PORT_A, GPIO_PIN_9, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_A, GPIO_PIN_9, Bit_SET);
		break;
		case PWM_PWM:
			TIM1->CCER |=  (1 << 4); 
			Gpio_SetPort(GPIO_PORT_A, GPIO_PIN_9, Bit_RESET);
			Gpio_Init(GPIO_PORT_A, GPIO_PIN_9, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ);
		break;
	}
	switch(OC2N)
	{
		case PWM_OFF:
			TIM1->CCER &= ~(1 << 6); 
			Gpio_Init(GPIO_PORT_B, GPIO_PIN_14, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_B, GPIO_PIN_14, Bit_RESET);
		break;
		case PWM_ON:
			TIM1->CCER &= ~(1 << 6); 
			Gpio_Init(GPIO_PORT_B, GPIO_PIN_14, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_B, GPIO_PIN_14, Bit_SET);
		break;
		case PWM_PWM:
			TIM1->CCER |=  (1 << 6); 
			Gpio_SetPort(GPIO_PORT_B, GPIO_PIN_14, Bit_RESET);
			Gpio_Init(GPIO_PORT_B, GPIO_PIN_14, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ);
		break;
	}

	switch(OC3)
	{
		case PWM_OFF:
			TIM1->CCER &= ~(1 << 8); 
			Gpio_Init(GPIO_PORT_A, GPIO_PIN_10, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_A, GPIO_PIN_10, Bit_RESET);
		break;
		case PWM_ON:
			TIM1->CCER &= ~(1 << 8); 
			Gpio_Init(GPIO_PORT_A, GPIO_PIN_10, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_A, GPIO_PIN_10, Bit_SET);
		break;
		case PWM_PWM:
			TIM1->CCER |=  (1 << 8); 
			Gpio_SetPort(GPIO_PORT_A, GPIO_PIN_10, Bit_RESET);
			Gpio_Init(GPIO_PORT_A, GPIO_PIN_10, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ);
		break;
	}
	switch(OC3N)
	{
		case PWM_OFF:
			TIM1->CCER &= ~(1 << 10); 
			Gpio_Init(GPIO_PORT_B, GPIO_PIN_15, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_B, GPIO_PIN_15, Bit_RESET);
		break;
		case PWM_ON:
			TIM1->CCER &= ~(1 << 10); 
			Gpio_Init(GPIO_PORT_B, GPIO_PIN_15, GPIO_Mode_Out_PP, GPIO_SPEED_50MHZ);
			Gpio_SetPort(GPIO_PORT_B, GPIO_PIN_15, Bit_SET);
		break;
		case PWM_PWM:
			TIM1->CCER |=  (1 << 10); 
			Gpio_SetPort(GPIO_PORT_B, GPIO_PIN_15, Bit_RESET);
			Gpio_Init(GPIO_PORT_B, GPIO_PIN_15, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ);
		break;
	}

	if(((OC1 | OC2 | OC3 | OC1N | OC2N | OC3N) & PWM_PWM) > 0)
	{
		TIM_CtrlPWMOutputs(TIM1, ENABLE); 
	}else
	{
		TIM_CtrlPWMOutputs(TIM1, DISABLE); 
	}

}


void PwmTim1_init(void)
{

	Gpio_Init(GPIO_PORT_A, GPIO_PIN_8, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ); //PA8  OC1
	Gpio_Init(GPIO_PORT_B, GPIO_PIN_13, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ);//PB13 OC1N


	Gpio_Init(GPIO_PORT_A, GPIO_PIN_9, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ); //PA9  OC2
	Gpio_Init(GPIO_PORT_B, GPIO_PIN_14, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ);//PB14 OC2N

	Gpio_Init(GPIO_PORT_A, GPIO_PIN_10, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ);//PA10 OC3
	Gpio_Init(GPIO_PORT_B, GPIO_PIN_15, GPIO_Mode_AF_PP, GPIO_SPEED_50MHZ);//PB14 OC3N


	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruce;
	/*
	 * MAIN CLK = 72M
	 * DES  CLK = 20K
	 * factor = DES/MAIN = 24M/72M = 3
	 * TIM_Prescaler = 3 - 1;
	 */
	TIM_TimeBaseInitStruce.TIM_Prescaler = 0;
	TIM_TimeBaseInitStruce.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruce.TIM_CounterMode = TIM_CounterMode_CenterAligned1;
	TIM_TimeBaseInitStruce.TIM_Period = PWM_FREQ;
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStruce);


	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Disable;
	TIM_OCInitStruct.TIM_OCPolarity  = TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Disable;
	TIM_OCInitStruct.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStruct.TIM_Pulse = 0;	
	TIM_OC1Init(TIM1, &TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Disable;
	TIM_OCInitStruct.TIM_OCPolarity  = TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Disable;
	TIM_OCInitStruct.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStruct.TIM_Pulse = 0;	
	TIM_OC2Init(TIM1, &TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Disable;
	TIM_OCInitStruct.TIM_OCPolarity  = TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Disable;
	TIM_OCInitStruct.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStruct.TIM_Pulse = 0;	
	TIM_OC3Init(TIM1, &TIM_OCInitStruct);

	TIM1->BDTR &= ~(0xF << 0);
	TIM1->BDTR |=  (0x6C << 0);

	TIM_ARRPreloadConfig(TIM1, ENABLE);

	TIM_Cmd(TIM1, ENABLE);

	TIM_CtrlPWMOutputs(TIM1, DISABLE); 
	
}





#endif

