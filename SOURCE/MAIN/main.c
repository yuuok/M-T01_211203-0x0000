#ifndef _MAIN_C_
#define _MAIN_C_

#include "main.h"

u16 adcValueCheck = 0;
u16 volValueCheck = 0;
u16 VbusValueCheck = 0;
int main(void)
{
	Rcc_Init();
	Iwdg_Init();
	Timer2_Init();
	PwmTim1_init();
	Adc_Init();
	Dma_Init();
	Nvic_Init();	
	delay_dead_ms(10);
	
	while(1)
	{
		if(PAR_TimeFlag_1ms == 0)
		{	
			PAR_TimeFlag_1ms = PAR_TIME_STEMP_DUR_1MS;	
			Iwdg_FeedDog();
		}
		if(PAR_TimeFlag_5ms == 0)
		{
			PAR_TimeFlag_5ms = PAR_TIME_STEMP_DUR_5MS;	
		}
		if(PAR_TimeFlag_10ms == 0)
		{
			PAR_TimeFlag_10ms = PAR_TIME_STEMP_DUR_10MS;
		}
		if(PAR_TimeFlag_10_5ms == 0)
		{
			PAR_TimeFlag_10_5ms = PAR_TIME_STEMP_DUR_10MS;
		}
		if(PAR_TimeFlag_50ms == 0)
		{
			PAR_TimeFlag_50ms = PAR_TIME_STEMP_DUR_50MS;
			Adc_PeriodTask();
		}
		if(PAR_TimeFlag_100ms == 0)
		{
			PAR_TimeFlag_100ms = PAR_TIME_STEMP_DUR_100MS;
		}		
	}
	return 0;
}





#endif

