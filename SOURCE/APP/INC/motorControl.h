#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "common.h"
#include "parameters.h"
#include "pwmTim1.h"
#include "mc_cal.h"
#include "dma.h"
#include "adc.h"




extern u16 Mc_ShuntCurrent_Zero_A;
extern s16 Mc_ShuntCurrent_A;
extern u16 Mc_ShuntCurrent_Raw_A;

extern u16 Mc_ShuntCurrent_Zero_C;
extern s16 Mc_ShuntCurrent_C;
extern u16 Mc_ShuntCurrent_Raw_C;







void Mc_Svpwm(void);







#endif

