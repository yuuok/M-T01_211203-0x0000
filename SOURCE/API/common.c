#ifndef _COMMON_C_
#define _COMMON_C_

#include "common.h"


volatile common_delay_struct Common_Delay_Struct = 
{
	0,
	0,
	0
};

void delay_dead_1ms(void)
{
	Common_Delay_Struct.startFlag_ms = 1;
	while(!Common_Delay_Struct.doneFlag_ms);
	Common_Delay_Struct.doneFlag_ms = 0;
}

void delay_dead_ms(uint16 ms)
{
	volatile uint16 i;
	for(i = 0; i < ms; i++)
	{
		delay_dead_1ms();
	}
}



#endif
