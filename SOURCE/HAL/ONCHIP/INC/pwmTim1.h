#ifndef _PWMTIM1_H_
#define _PWMTIM1_H_


#include "common.h"
#include "rcc.h"
#include "stm32f10x_tim.h"
#include "misc.h"
#include "gpio.h"


#define PWM_FREQ			1800//(1/0.02M)/(1/72M)/2 <- 20K


typedef enum{
	PWM_OFF = 0,
	PWM_ON,
	PWM_PWM,
}pwm_bridge_status;

void PwmTim1_init(void);
void PwmTim1_DutySet(u16 duty1, u16 duty2, u16 duty3);
void PwmTim1_BridgeSet(pwm_bridge_status OC1, pwm_bridge_status OC1N,
								pwm_bridge_status OC2, pwm_bridge_status OC2N,
								pwm_bridge_status OC3, pwm_bridge_status OC3N);






#endif

