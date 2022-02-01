#ifndef MOTOR_CONTROL_C
#define MOTOR_CONTROL_C

#include "motorControl.h"


u8  OpenFlag = 0;
u16 Mc_ShuntCurrent_Zero_A;

u16 Mc_ShuntCurrent_Raw_A;

s16 Mc_ShuntCurrent_A;

s16 Mc_ShuntCurrent_B;

s16 Mc_ShuntCurrent_C;

s16 Mc_PhaseCurrent_Alpha;
s16 Mc_PhaseCurrent_Beta;
s16 Mc_PhaseCurrent_Alpha_FL;
s16 Mc_PhaseCurrent_Beta_FL;

u16 Mc_ShuntCurrent_Zero_C;

u16 Mc_ShuntCurrent_Raw_C;




u16 Mc_Electric_Angle = 0;
s16 Mc_Electric_Speed = 50;
u16 Mc_Electric_Acc = 0;
u16 Mc_Electric_Duty = 300;


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
	u16 angle;
	u16 angleLast;
	s16 speed;
	u32 sum;
	u16 cnt;
	u16 pllKp;
}mc_anglePll_struct;

typedef struct 
{
	s32 rsiaQ16;
	s32 rsibQ16;
	s32 lsiaQ16;
	s32 lsibQ16;
	
	s32 AQ16;
	s32 BQ16;
	
	u16 angle;
	u16 angleLast;
	
	u32 ampQ16;

	Mc_LpParType inteA;
	Mc_LpParType inteB;	
}mc_fluxEst_struct;

typedef struct 
{
	u16 angle;
	u16 duty;
	
	s16 dutyA;
	s16 dutyB;

	u8 n;	
	s16 xTime;
	s16 yTime;
	s16 zTime;	
	s16 t1Time;
	s16 t2Time;	
	s16 cm1Time;
	s16 cm2Time;
	s16 cm3Time;	
}mc_svmGen_struct;

typedef struct
{
	/*stator three*/
	s16 a;
	s16 b;
	s16 c;
	/*stator tow*/
	s16 A;
	s16 B;
	s16 filA;
	s16 filB;
	/*spin polr*/
	s16 d;
	s16 q;
	/*lp para*/
	Mc_LpParType lpA;
	Mc_LpParType lpB;
}mc_current_struct;

typedef struct 
{
	s16 a;
	s16 b;
	s16 c;
	
	s16 A;
	s16 B;

	s16 d;
	s16 q;
}mc_voltage_struct;

typedef struct
{
	u16 res;
	u16 ind;
}mc_motor_para;

typedef struct 
{
	s16 actSpeed;
	s16 wmSpeed;
	s16 refSpeed;
	s16 angleSpeed;
}mc_operate_var;

typedef struct
{	

	mc_operate_var oper;
	mc_motor_para mPara;
	mc_svmGen_struct svmGen;
	mc_current_struct current;
	mc_voltage_struct voltage;
	mc_fluxEst_struct  fluxEst;
	mc_anglePll_struct anglePll;

} foc_svm_para_struct;
foc_svm_para_struct FocCtrlVar;


void Mc_SwInit(void)
{
	FocCtrlVar.mPara.res = 1;
	FocCtrlVar.mPara.ind = 1;

	FocCtrlVar.svmGen.angle = 0;
	FocCtrlVar.svmGen.duty = 200;
	FocCtrlVar.oper.angleSpeed = 0;

	FocCtrlVar.current.lpA.coefA = 2000;
	FocCtrlVar.current.lpA.coefB = 2000;
	FocCtrlVar.current.lpB.coefA = 2000;
	FocCtrlVar.current.lpB.coefB = 2000;

	FocCtrlVar.fluxEst.inteA.coefA = 161;
	FocCtrlVar.fluxEst.inteA.coefB = 35;
	FocCtrlVar.fluxEst.inteB.coefA = 161;
	FocCtrlVar.fluxEst.inteB.coefB = 35;

}

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
	FocCtrlVar.svmGen.n = 4 * C + 2 * B + A;
}
void Mc_Svpwm_XYZTimeCal(s16 Ualpha, s16 Ubeta)
{
    FocCtrlVar.svmGen.xTime = (173*Ubeta/100);
    FocCtrlVar.svmGen.yTime = (3*Ualpha/2 + 173*Ubeta/200);
    FocCtrlVar.svmGen.zTime = (-3*Ualpha/2 + 173*Ubeta/200);
}
void Mc_Svpwm_TsubCal(s16 X,s16 Y, s16 Z, u8 N)
{
	s16 t1 = 0;
	s16 t2 = 0;
	switch(N)
	{
		
		case 1:
			FocCtrlVar.svmGen.t1Time = Z;
			FocCtrlVar.svmGen.t2Time = Y;
		break;
		case 2:
			FocCtrlVar.svmGen.t1Time = Y;
			FocCtrlVar.svmGen.t2Time = -X;
		break;
		case 3:
			FocCtrlVar.svmGen.t1Time = -Z;
			FocCtrlVar.svmGen.t2Time = X;
		break;
		case 4:
			FocCtrlVar.svmGen.t1Time = -X;
			FocCtrlVar.svmGen.t2Time = Z;
		break;
		case 5:
			FocCtrlVar.svmGen.t1Time = X;
			FocCtrlVar.svmGen.t2Time = -Y;
		break;	
		default://6
			FocCtrlVar.svmGen.t1Time = -Y;
			FocCtrlVar.svmGen.t2Time = -Z;
		break;
	}
    if((FocCtrlVar.svmGen.t1Time + FocCtrlVar.svmGen.t2Time) > 1000)
    {
    	t1 = ((s32)FocCtrlVar.svmGen.t1Time * 1000)/((s32)FocCtrlVar.svmGen.t1Time + (s32)FocCtrlVar.svmGen.t2Time);
    	t2 = ((s32)FocCtrlVar.svmGen.t2Time * 1000)/((s32)FocCtrlVar.svmGen.t1Time + (s32)FocCtrlVar.svmGen.t2Time);
    	FocCtrlVar.svmGen.t1Time = t1;
    	FocCtrlVar.svmGen.t2Time = t2;
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
			FocCtrlVar.svmGen.cm1Time = Tb;
			FocCtrlVar.svmGen.cm2Time = Ta;
			FocCtrlVar.svmGen.cm3Time = Tc;
		break;
		case 2:
			FocCtrlVar.svmGen.cm1Time = Ta;
			FocCtrlVar.svmGen.cm2Time = Tc;
			FocCtrlVar.svmGen.cm3Time = Tb;
		break;
		case 3:
			FocCtrlVar.svmGen.cm1Time = Ta;
			FocCtrlVar.svmGen.cm2Time = Tb;
			FocCtrlVar.svmGen.cm3Time = Tc;
		break;
		case 4:
			FocCtrlVar.svmGen.cm1Time = Tc;
			FocCtrlVar.svmGen.cm2Time = Tb;
			FocCtrlVar.svmGen.cm3Time = Ta;
		break;
		case 5:
			FocCtrlVar.svmGen.cm1Time = Tc;
			FocCtrlVar.svmGen.cm2Time = Ta;
			FocCtrlVar.svmGen.cm3Time = Tb;
		break;	
		default://6
			FocCtrlVar.svmGen.cm1Time = Tb;
			FocCtrlVar.svmGen.cm2Time = Tc;
			FocCtrlVar.svmGen.cm3Time = Ta;
		break;
	}	 

}


u8 Mc_AngleSpeedCal(u16 angle, u16 angleLast, s16* speedPtr, u32* sum, u16* cnt)
{
	u8 caled = 0;
	if( (angle < 2000) && (angleLast > 63000))
	{
		*speedPtr = (*sum)/(*cnt);
		*sum = 0;
		*cnt = 0;
		caled = 1;
	}
	else
	{
		*sum += angle - angleLast;
		(*cnt)++;
	}
	return caled;
}

#if 0
u16 CalAngle = 0;
u32 FluxAmp = 0;
void Mc_FluxAngleCal(s16 ualpha, s16 ubeta, s16 curalpha, s16 curbeta)
{
	//fluxa = inteUsa-inteRia-Lsia
	//fluxb = inteUsb-inteRib-Lsib
	FocCtrlVar.lsiaQ16 = ((s32)Mc_StatorInductor * (s32)curalpha*65536)/1000;
	FocCtrlVar.lsibQ16 = ((s32)Mc_StatorInductor * (s32)curbeta*65536)/1000;
	FocCtrlVar.rsiaQ16 = ((s32)Mc_StatorResistor * (s32)curalpha*65536)/1000;
	FocCtrlVar.rsibQ16 = ((s32)Mc_StatorResistor * (s32)curbeta*65536)/1000;
	FocCtrlVar.fluxAlphaQ16 = Mc_LowPassFilter(&Mc_inte_Vsa, ((s32)ualpha*65536)/10 - FocCtrlVar.rsiaQ16) - FocCtrlVar.lsiaQ16;
	FocCtrlVar.fluxBetaQ16 = Mc_LowPassFilter(&Mc_inte_Vsb, ((s32)ubeta*65536)/10 - FocCtrlVar.rsibQ16) - FocCtrlVar.lsibQ16;
	FocCtrlVar.fluxCalAngleLast = FocCtrlVar.fluxCalAngle;
	FocCtrlVar.fluxCalAngle = Math_ArcTanCal(FocCtrlVar.fluxAlphaQ16,FocCtrlVar.fluxBetaQ16,&FocCtrlVar.fluxAmpQ16);

}
void Mc_AnglePll(void)
{
	s32 deltaAngle = 0;
	s32 omega = 0;	
	deltaAngle = (s32)FocCtrlVar.fluxEst.Angle - (s32)FocCtrlVar.anglePll.angle;
	(void)Mc_AngleSpeedCal(
		(s32)FocCtrlVar.anglePll.angle, 
		FocCtrlVar.anglePll.angleLast, 
		&FocCtrlVar.anglePll.speed , 
		&FocCtrlVar.anglePll.sum, 
		&FocCtrlVar.anglePll.cnt);
	omega = (s32)deltaAngle  + (s32)FocCtrlVar.anglePll.speed;
	FocCtrlVar.anglePll.angleLast = FocCtrlVar.anglePll.angle;
	FocCtrlVar.anglePll.angle += ((s32)omega * (s32)FocCtrlVar.anglePll.pllKp)/100;	
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
	Mc_Svpwm_TsubCal(FocCtrlVar.svmGen.xTime,FocCtrlVar.svmGen.yTime, FocCtrlVar.svmGen.zTime, FocCtrlVar.svmGen.n);
	Mc_Svpwm_TcmCal(FocCtrlVar.svmGen.n,FocCtrlVar.svmGen.t1Time, FocCtrlVar.svmGen.t2Time);
	if(OpenFlag > 0)
	{
		PwmTim1_BridgeSet(PWM_PWM,PWM_PWM,PWM_PWM,PWM_PWM,PWM_PWM,PWM_PWM);
		PwmTim1_DutySet(FocCtrlVar.svmGen.cm1Time, FocCtrlVar.svmGen.cm2Time, FocCtrlVar.svmGen.cm3Time);
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

	Mc_AnglePll();

	(void)Mc_AngleSpeedCal(FocCtrlVar.fluxCalAngle, FocCtrlVar.fluxCalAngleLast, &FocCtrlVar.actSpeed, &speedSum, &speedCnt);
	
	if(closeLoopFlag > 0)
	{
		Mc_Electric_Angle = FocCtrlVar.fluxAnglePll + AngleDelta + FocCtrlVar.angleSpeedPll;
	}
	else
	{
		Mc_Electric_Angle += Mc_Electric_Speed;
	}
	
	
	
}
#endif
///////////////////////////////////////////////////////////////////////////////////////////////////
void Mc_VoltageCal(u16 dcLink)
{
	FocCtrlVar.voltage.A = (FocCtrlVar.svmGen.dutyA * dcLink / 10);
	FocCtrlVar.voltage.B = (FocCtrlVar.svmGen.dutyB * dcLink / 10);
}

void Mc_CurrentCal(void)
{
	s16 currentA = 0;
	s16 currentC = 0;
	
	currentA = (s16)Mc_ShuntCurrent_Raw_A - (s16)Mc_ShuntCurrent_Zero_A;
	currentC = (s16)Mc_ShuntCurrent_Raw_C - (s16)Mc_ShuntCurrent_Zero_C;

	FocCtrlVar.current.a = (s32)currentA*3223/100;
	FocCtrlVar.current.c = (s32)currentC*3223/100;
	FocCtrlVar.current.b = -FocCtrlVar.current.a - FocCtrlVar.current.c;
	
	Math_Clack(
		FocCtrlVar.current.a
	  , FocCtrlVar.current.b
	  , FocCtrlVar.current.c
	  , &FocCtrlVar.current.A
	  , &FocCtrlVar.current.A);

	FocCtrlVar.current.filA = Mc_LowPassFilter(&FocCtrlVar.current.lpA,FocCtrlVar.current.A);
	FocCtrlVar.current.filB = Mc_LowPassFilter(&FocCtrlVar.current.lpB,FocCtrlVar.current.B);
}
void Mc_FluxEst(void)
{
	//fluxa = inteUsa-inteRia-Lsia
	//fluxb = inteUsb-inteRib-Lsib
	FocCtrlVar.fluxEst.lsiaQ16 = ((s32)FocCtrlVar.mPara.ind * (s32)FocCtrlVar.current.filA*65536)/1000;
	FocCtrlVar.fluxEst.lsibQ16 = ((s32)FocCtrlVar.mPara.ind * (s32)FocCtrlVar.current.filB*65536)/1000;
	FocCtrlVar.fluxEst.rsiaQ16 = ((s32)FocCtrlVar.mPara.res * (s32)FocCtrlVar.current.filA*65536)/1000;
	FocCtrlVar.fluxEst.rsibQ16 = ((s32)FocCtrlVar.mPara.res * (s32)FocCtrlVar.current.filB*65536)/1000;
	FocCtrlVar.fluxEst.AQ16 = Mc_LowPassFilter(&FocCtrlVar.fluxEst.inteA, 
		((s32)FocCtrlVar.voltage.A*65536)/10 - FocCtrlVar.fluxEst.rsiaQ16) - FocCtrlVar.fluxEst.lsiaQ16;
	FocCtrlVar.fluxEst.BQ16 = Mc_LowPassFilter(&FocCtrlVar.fluxEst.inteB, 
		((s32)FocCtrlVar.voltage.B*65536)/10 - FocCtrlVar.fluxEst.rsibQ16) - FocCtrlVar.fluxEst.lsibQ16;
	FocCtrlVar.fluxEst.angleLast = FocCtrlVar.fluxEst.angle;
	FocCtrlVar.fluxEst.angle = Math_ArcTanCal(
							FocCtrlVar.fluxEst.AQ16,
							FocCtrlVar.fluxEst.BQ16,
							&FocCtrlVar.fluxEst.ampQ16);
}
void Mc_AnglePll(void)
{
	s32 deltaAngle = 0;
	s32 omega = 0;	
	deltaAngle = (s32)FocCtrlVar.fluxEst.angle - (s32)FocCtrlVar.anglePll.angle;
	(void)Mc_AngleSpeedCal(
		(s32)FocCtrlVar.anglePll.angle, 
		FocCtrlVar.anglePll.angleLast, 
		&FocCtrlVar.anglePll.speed, 
		&FocCtrlVar.anglePll.sum, 
		&FocCtrlVar.anglePll.cnt);
	omega = (s32)deltaAngle  + (s32)FocCtrlVar.anglePll.speed;
	FocCtrlVar.anglePll.angleLast = FocCtrlVar.anglePll.angle;
	FocCtrlVar.anglePll.angle += ((s32)omega * (s32)FocCtrlVar.anglePll.pllKp)/100;	
}

void Mc_SvmGen(void)
{
	u16 angle_1500;
	angle_1500 = (1500 * FocCtrlVar.svmGen.angle) >> 16;
	FocCtrlVar.svmGen.dutyA = ((s32)FocCtrlVar.svmGen.duty * Math_Cos(angle_1500)) >> 15;
	FocCtrlVar.svmGen.dutyB = ((s32)FocCtrlVar.svmGen.duty * Math_Sin(angle_1500)) >> 15;
	Mc_Svpwm_NSectorCal(FocCtrlVar.svmGen.dutyA,FocCtrlVar.svmGen.dutyB);
	Mc_Svpwm_XYZTimeCal(FocCtrlVar.svmGen.dutyA,FocCtrlVar.svmGen.dutyB);
	Mc_Svpwm_TsubCal(FocCtrlVar.svmGen.xTime,FocCtrlVar.svmGen.yTime, FocCtrlVar.svmGen.zTime, FocCtrlVar.svmGen.n);
	Mc_Svpwm_TcmCal(FocCtrlVar.svmGen.n,FocCtrlVar.svmGen.t1Time, FocCtrlVar.svmGen.t2Time);
	PwmTim1_DutySet(FocCtrlVar.svmGen.cm1Time, FocCtrlVar.svmGen.cm2Time, FocCtrlVar.svmGen.cm3Time);
}
void Mc_FocMainFunc(void)
{
	//voltage
	Mc_VoltageCal(PAR_DcLinkVol);
	//current
	Mc_CurrentCal();
	//fluxcal
	Mc_FluxEst();
	//anglepll
	Mc_AnglePll();
	//svm
	Mc_SvmGen();
}




#endif

