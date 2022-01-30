#ifndef _PARAMETERS_C_
#define _PARAMETERS_C_

#include "parameters.h"


/////////////////////////////SystemTimeCounter//////////////////////////
u16 PAR_TimeFlag_1ms;
u16 PAR_TimeFlag_5ms;
u16 PAR_TimeFlag_10ms;
u16 PAR_TimeFlag_10_5ms;
u16 PAR_TimeFlag_50ms = 0;
u16 PAR_TimeFlag_100ms = 0;

u16 PAR_DcLinkVol;
u16 PAR_DclinkVol_Q16;
u16	PAR_TempVol;

void Par_init(void)
{

	PAR_TimeFlag_1ms = PAR_TIME_STEMP_DUR_1MS;
	PAR_TimeFlag_5ms = PAR_TIME_STEMP_DUR_5MS;
	PAR_TimeFlag_10ms = PAR_TIME_STEMP_DUR_10MS;
	PAR_TimeFlag_10_5ms = PAR_TIME_STEMP_DUR_10MS + PAR_TIME_STEMP_DUR_5MS_DELAY;
	PAR_TimeFlag_50ms = PAR_TIME_STEMP_DUR_50MS;
	PAR_TimeFlag_100ms = PAR_TIME_STEMP_DUR_100MS;

}





#endif

