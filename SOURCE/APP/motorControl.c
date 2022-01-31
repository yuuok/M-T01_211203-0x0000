#ifndef MOTOR_CONTROL_C
#define MOTOR_CONTROL_C

#include "motorControl.h"


u8  OpenFlag = 0;
u16 Mc_ShuntCurrent_Zero_A;
s16 Mc_ShuntCurrent_A;
u16 Mc_ShuntCurrent_Raw_A;

s16 Mc_ShuntCurrent_B;

u16 Mc_ShuntCurrent_Zero_C;
s16 Mc_ShuntCurrent_C;
u16 Mc_ShuntCurrent_Raw_C;

s16 Mc_PhaseCurrent_Alpha;
s16 Mc_PhaseCurrent_Beta;
s16 Mc_PhaseCurrent_Alpha_FL;
s16 Mc_PhaseCurrent_Beta_FL;


u16 Mc_Electric_Angle = 0;
s16 Mc_Electric_Speed = 50;
u16 Mc_Electric_Acc = 0;
u16 Mc_Electric_Duty = 300;

s16 Mc_Duty_Ua;
s16 Mc_Duty_Ub;
s16 Mc_Duty_Uc;
s16 Mc_Volt_Ualpha;
s16 Mc_Volt_Ubeta;


u8 NSector = 0;
s16 XTime = 0;
s16 YTime = 0;
s16 ZTime = 0;
s16 T1Time = 0;
s16 T2Time = 0;
s16 Cm1Time = 0;
s16 Cm2Time = 0;
s16 Cm3Time = 0;

Mc_LpParType Mc_Lp_Ialpha = {
	2000,
	2000,
	0
};
Mc_LpParType Mc_Lp_Ibeta = {
	2000,
	2000,
	0,
};
Mc_LpParType Mc_Lp_ActSpeed = {
	2000,
	2000,
	0,
};
Mc_LpParType Mc_inte_Vsa = {
	161,
	35,
	0,
};

Mc_LpParType Mc_inte_Vsb = {
	161,
	35,
	0,
};
Mc_LpParType Mc_inte_AnglePll = {
	161,
	35,
	0,
};
s16 Mc_StatorResistor = 1;
s16 Mc_StatorInductor = 1;



typedef struct
{	

	s16 actSpeed;

	s32 rsiaQ16;
	s32 rsibQ16;
	s32 lsiaQ16;
	s32 lsibQ16;
	
	s32 fluxAlphaQ16;
	s32 fluxBetaQ16;

	u16 fluxCalAngle;
	u16 fluxCalAngleLast;
	u32 fluxAmpQ16;

	u16 fluxAnglePll;
	s16 angleSpeedPll;
} foc_svm_para_struct;
foc_svm_para_struct FOCSystemCtrl;

void Mc_Svpwm_NSectorCal(s16 Ualpha, s16 Ubeta)
{
	u8 A = 0;
	u8 B = 0;
	u8 C = 0;
	s16 U1 = 0;
	s16 U2 = 0;
	s16 U3 = 0;
	U1 = Ubeta;
	U2 = 173*Ualpha/200 - Ubeta/2;
	U3 = -173*Ualpha/200 - Ubeta/2;
	if(U1 > 0)
	{
		A = 1;
	}
	if(U2 > 0)
	{
		B = 1;
	}
	if(U3 > 0)
	{
		C = 1;
	}
	NSector = 4 * C + 2 * B + A;
}
void Mc_Svpwm_XYZTimeCal(s16 Ualpha, s16 Ubeta)
{
    XTime = (173*Ubeta/100);
    YTime = (3*Ualpha/2 + 173*Ubeta/200);
    ZTime = (-3*Ualpha/2 + 173*Ubeta/200);
}
void Mc_Svpwm_TsubCal(s16 X,s16 Y, s16 Z, u8 N)
{
	s16 t1 = 0;
	s16 t2 = 0;
	switch(N)
	{
		case 1:
			T1Time = Z;
			T2Time = Y;
		break;
		case 2:
			T1Time = Y;
			T2Time = -X;
		break;
		case 3:
			T1Time = -Z;
			T2Time = X;
		break;
		case 4:
			T1Time = -X;
			T2Time = Z;
		break;
		case 5:
			T1Time = X;
			T2Time = -Y;
		break;	
		default://6
			T1Time = -Y;
			T2Time = -Z;
		break;
	}
    if((T1Time + T2Time) > 1000)
    {
    	t1 = ((s32)T1Time * 1000)/((s32)T1Time + (s32)T2Time);
    	t2 = ((s32)T2Time * 1000)/((s32)T1Time + (s32)T2Time);
    	T1Time = t1;
    	T2Time = t2;
    }	
}
void Mc_Svpwm_TcmCal(u8 N,s16 T1, s16 T2)
{
	s16 Ta = 0;
	s16 Tb = 0;
	s16 Tc = 0;
	Ta = (1000 - T1 - T2)/4;
	Tb = Ta + T1/2;
	Tc = Tb + T2/2;
	
	switch(N)
	{
		case 1:
			Cm1Time = Tb;
			Cm2Time = Ta;
			Cm3Time = Tc;
		break;
		case 2:
			Cm1Time = Ta;
			Cm2Time = Tc;
			Cm3Time = Tb;
		break;
		case 3:
			Cm1Time = Ta;
			Cm2Time = Tb;
			Cm3Time = Tc;
		break;
		case 4:
			Cm1Time = Tc;
			Cm2Time = Tb;
			Cm3Time = Ta;
		break;
		case 5:
			Cm1Time = Tc;
			Cm2Time = Ta;
			Cm3Time = Tb;
		break;	
		default://6
			Cm1Time = Tb;
			Cm2Time = Tc;
			Cm3Time = Ta;
		break;
	}	 

}
u16 CalAngle = 0;
u32 FluxAmp = 0;
void Mc_FluxAngleCal(s16 ualpha, s16 ubeta, s16 curalpha, s16 curbeta)
{
	//fluxa = inteUsa-inteRia-Lsia
	//fluxb = inteUsb-inteRib-Lsib
	FOCSystemCtrl.lsiaQ16 = ((s32)Mc_StatorInductor * (s32)curalpha*65536)/1000;
	FOCSystemCtrl.lsibQ16 = ((s32)Mc_StatorInductor * (s32)curbeta*65536)/1000;
	FOCSystemCtrl.rsiaQ16 = ((s32)Mc_StatorResistor * (s32)curalpha*65536)/1000;
	FOCSystemCtrl.rsibQ16 = ((s32)Mc_StatorResistor * (s32)curbeta*65536)/1000;
	FOCSystemCtrl.fluxAlphaQ16 = Mc_LowPassFilter(&Mc_inte_Vsa, ((s32)ualpha*65536)/10 - FOCSystemCtrl.rsiaQ16) - FOCSystemCtrl.lsiaQ16;
	FOCSystemCtrl.fluxBetaQ16 = Mc_LowPassFilter(&Mc_inte_Vsb, ((s32)ubeta*65536)/10 - FOCSystemCtrl.rsibQ16) - FOCSystemCtrl.lsibQ16;
	FOCSystemCtrl.fluxCalAngleLast = FOCSystemCtrl.fluxCalAngle;
	FOCSystemCtrl.fluxCalAngle = Math_ArcTanCal(FOCSystemCtrl.fluxAlphaQ16,FOCSystemCtrl.fluxBetaQ16,&FOCSystemCtrl.fluxAmpQ16);

}
s16 pllKp = 1;
u8 PLLSpeedSwitchFlag = 0;
void Mc_AnglePll(void)
{
	s32 deltaAngle = 0;
	s32 omega = 0;
	static u16 anglePllLast = 0;
	
	deltaAngle = (s32)FOCSystemCtrl.fluxCalAngle - (s32)FOCSystemCtrl.fluxAnglePll;
	if(PLLSpeedSwitchFlag ==0)
	{
		FOCSystemCtrl.angleSpeedPll = Mc_Electric_Speed;
	}
	else
	{
		if(FOCSystemCtrl.fluxAnglePll > anglePllLast)
			FOCSystemCtrl.angleSpeedPll = FOCSystemCtrl.fluxAnglePll - anglePllLast;

	}
	omega = (s32)deltaAngle  + (s32)FOCSystemCtrl.angleSpeedPll;
	anglePllLast = FOCSystemCtrl.fluxAnglePll;
	FOCSystemCtrl.fluxAnglePll = Mc_LowPassFilter(&Mc_inte_AnglePll,((s32)omega * (s32)pllKp)/100);	
}
u8 closeLoopFlag = 0;
u16 AngleDelta = 0;
u16 calAngleAddDelta = 0;
u16 speedCnt = 0;
u16 speedSum = 0;
void Mc_Svpwm(void)
{
	u16 angle = 0;
	s16 currentA = 0;
	s16 currentB = 0;
	s16 currentC = 0;
	s16 dutyAlpha = 0;	
	s16 dutyBeta = 0;
	
	angle = (1500 * Mc_Electric_Angle) >> 16;
	dutyAlpha = ((s32)Mc_Electric_Duty * Math_Cos(angle)) >> 15;
	dutyBeta = ((s32)Mc_Electric_Duty * Math_Sin(angle)) >> 15;

	
	Mc_Svpwm_NSectorCal(dutyAlpha,dutyBeta);
	Mc_Svpwm_XYZTimeCal(dutyAlpha,dutyBeta);
	Mc_Svpwm_TsubCal(XTime,YTime, ZTime, NSector);
	Mc_Svpwm_TcmCal(NSector,T1Time, T2Time);
	if(OpenFlag > 0)
	{
		PwmTim1_BridgeSet(PWM_PWM,PWM_PWM,PWM_PWM,PWM_PWM,PWM_PWM,PWM_PWM);
		PwmTim1_DutySet(Cm1Time, Cm2Time, Cm3Time);
	}
	else
	{
		PwmTim1_BridgeSet(PWM_OFF,PWM_OFF,PWM_OFF,PWM_OFF,PWM_OFF,PWM_OFF);
		PwmTim1_DutySet(0, 0, 0);
	}
	currentA = (s16)Mc_ShuntCurrent_Raw_A - (s16)Mc_ShuntCurrent_Zero_A;
	currentC = (s16)Mc_ShuntCurrent_Raw_C - (s16)Mc_ShuntCurrent_Zero_C;

	//adcVol = adc*maxVol/4095
	//inputVol = adcVol/10
	//current = inputVol / 0.005
	//current = adcvol*0.1*200;
	//current = adc*3.3*200*0.1/4095
	//ampCurrent = 1000*current;
	
	Mc_ShuntCurrent_A = (s32)currentA*3223/100;
	Mc_ShuntCurrent_C = (s32)currentC*3223/100;
	Mc_ShuntCurrent_B = -Mc_ShuntCurrent_A - Mc_ShuntCurrent_C;
	Mc_Volt_Ualpha = (dutyAlpha * PAR_DcLinkVol / 10);
	Mc_Volt_Ubeta = (dutyBeta * PAR_DcLinkVol / 10);
	Math_Clack(Mc_ShuntCurrent_A, Mc_ShuntCurrent_B, Mc_ShuntCurrent_C, &Mc_PhaseCurrent_Alpha, &Mc_PhaseCurrent_Beta);
	
	Mc_PhaseCurrent_Alpha_FL = (Mc_LowPassFilter(&Mc_Lp_Ialpha, Mc_PhaseCurrent_Alpha));
	Mc_PhaseCurrent_Beta_FL = (Mc_LowPassFilter(&Mc_Lp_Ibeta, Mc_PhaseCurrent_Beta));

	Mc_FluxAngleCal(Mc_Volt_Ualpha, Mc_Volt_Ubeta, Mc_PhaseCurrent_Alpha_FL, Mc_PhaseCurrent_Beta_FL);

	//Mc_FluxAngleCal(Mc_Volt_Ualpha, Mc_Volt_Ubeta, Mc_PhaseCurrent_Alpha, Mc_PhaseCurrent_Beta);
	Mc_AnglePll();


	if( (FOCSystemCtrl.fluxCalAngle < 2000) && (FOCSystemCtrl.fluxCalAngleLast > 63000))
	{
		FOCSystemCtrl.actSpeed = Mc_LowPassFilter(&Mc_Lp_ActSpeed,speedSum / speedCnt);
		speedCnt = 0;
		speedSum = 0;
	}
	else
	{
		speedSum += FOCSystemCtrl.fluxCalAngle - FOCSystemCtrl.fluxCalAngleLast;
		speedCnt++;
	}
	
	if(closeLoopFlag > 0)
	{
		Mc_Electric_Angle = FOCSystemCtrl.fluxCalAngle + AngleDelta;
	}
	
	Mc_Electric_Angle += Mc_Electric_Speed;
	
	
}





#endif

