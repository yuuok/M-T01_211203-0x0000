#ifndef _IWDG_C_
#define _IWDG_C_

#include "iwdg.h"


void Iwdg_Init(void)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	//Tout = (4 x 2^pre) / 40 x rlr
	//pre = 4 rlr = 800 -> Tout = 1280ms
	IWDG_SetPrescaler(IWDG_Prescaler_4);
	IWDG_SetReload(800);
	IWDG_Enable();	
}

void Iwdg_FeedDog(void)
{
	IWDG_ReloadCounter();
}



#endif
