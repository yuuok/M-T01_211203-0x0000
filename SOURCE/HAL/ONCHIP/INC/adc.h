#ifndef ADC_H
#define ADC_H

#include "common.h"
#include "parameters.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_rcc.h"
#include "gpio.h"
#include "motorControl.h"

extern u8 ADCFlag;


extern void Adc_Init(void);
extern void Adc_SetTo_CC1(void);

extern void Adc_SetTo_CC3(void);

extern u16 Adc_Get_Value(ADC_TypeDef * ADCx, u8 ch, u8 times);

extern void Adc_PeriodTask(void);


#endif

