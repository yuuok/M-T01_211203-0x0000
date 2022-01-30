#ifndef ADC_C
#define ADC_C

#include "adc.h"


u8 ADCFlag = 0;
void Adc_Init(void)
{
	//PORT PIN
	Gpio_Init(GPIO_PORT_C, GPIO_PIN_0, GPIO_MODE_AIN, GPIO_SPEED_50MHZ);//M0SO1--ch10
	Gpio_Init(GPIO_PORT_C, GPIO_PIN_1, GPIO_MODE_AIN, GPIO_SPEED_50MHZ);//M0SO2--ch11
	Gpio_Init(GPIO_PORT_C, GPIO_PIN_2, GPIO_MODE_AIN, GPIO_SPEED_50MHZ);//M0TEMP--ch12
	Gpio_Init(GPIO_PORT_C, GPIO_PIN_3, GPIO_MODE_AIN, GPIO_SPEED_50MHZ);//VBUS_S--ch13

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//72M/6 = 12M
	/*********************************ADC1*********************************/
	ADC_InitTypeDef adc_initStruct;

	adc_initStruct.ADC_Mode = ADC_Mode_Independent;
	adc_initStruct.ADC_ScanConvMode = DISABLE;
	adc_initStruct.ADC_ContinuousConvMode = DISABLE;
	adc_initStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	adc_initStruct.ADC_DataAlign = ADC_DataAlign_Right;
	adc_initStruct.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &adc_initStruct);

	//ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_239Cycles5);
	ADC_DMACmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE);

	//Calibration
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));

	Mc_ShuntCurrent_Zero_A = Adc_Get_Value(ADC1,ADC_Channel_10,5);
	Mc_ShuntCurrent_Raw_A = Mc_ShuntCurrent_Zero_A;
	Mc_ShuntCurrent_Zero_C = Adc_Get_Value(ADC1,ADC_Channel_11,5);
	Mc_ShuntCurrent_Raw_C = Mc_ShuntCurrent_Zero_C;
	Adc_SetTo_CC1();
	ADC_ExternalTrigConvCmd(ADC1, ENABLE);
	/*********************************ADC2*********************************/
	adc_initStruct.ADC_Mode = ADC_Mode_Independent;
	adc_initStruct.ADC_ScanConvMode = DISABLE;
	adc_initStruct.ADC_ContinuousConvMode = DISABLE;
	adc_initStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	adc_initStruct.ADC_DataAlign = ADC_DataAlign_Right;
	adc_initStruct.ADC_NbrOfChannel = 1;
	ADC_Init(ADC2, &adc_initStruct);
	ADC_Cmd(ADC2, ENABLE);
	ADC_ResetCalibration(ADC2);
	while(ADC_GetResetCalibrationStatus(ADC2));
	ADC_StartCalibration(ADC2);
	while(ADC_GetCalibrationStatus(ADC2));
	
}

void Adc_SetTo_CC1(void)
{
	ADC_InitTypeDef adc_initStruct;

	adc_initStruct.ADC_Mode = ADC_Mode_Independent;
	adc_initStruct.ADC_ScanConvMode = DISABLE;
	adc_initStruct.ADC_ContinuousConvMode = DISABLE;
	adc_initStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
	adc_initStruct.ADC_DataAlign = ADC_DataAlign_Right;
	adc_initStruct.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &adc_initStruct);

	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_239Cycles5);
}
void Adc_SetTo_CC3(void)
{
	ADC_InitTypeDef adc_initStruct;

	adc_initStruct.ADC_Mode = ADC_Mode_Independent;
	adc_initStruct.ADC_ScanConvMode = DISABLE;
	adc_initStruct.ADC_ContinuousConvMode = DISABLE;
	adc_initStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC3;
	adc_initStruct.ADC_DataAlign = ADC_DataAlign_Right;
	adc_initStruct.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &adc_initStruct);

	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_239Cycles5);
}

u16 Adc_Get_Value(ADC_TypeDef * ADCx, u8 ch, u8 times)
{
	u32 temp_val = 0;
	u8 t;
	ADC_RegularChannelConfig(ADCx, ch, 1, ADC_SampleTime_239Cycles5);

	for(t = 0; t < times; t++)
	{
		ADC_SoftwareStartConvCmd(ADCx, ENABLE);
		while(!ADC_GetFlagStatus(ADCx, ADC_FLAG_EOC));
		temp_val += ADC_GetConversionValue(ADCx);
	}

	return temp_val/times;
}

void Adc_PeriodTask(void)
{			
	PAR_DcLinkVol = (u32)Adc_Get_Value(ADC2,ADC_Channel_13,5)*844/4700;
	PAR_TempVol = Adc_Get_Value(ADC2,ADC_Channel_12,5);
}

#endif

