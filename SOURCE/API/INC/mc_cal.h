/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE                              
*   This software is the property of XBDZ Technologies. Any information contained in this 
*   doc should not be reproduced, or used, or disclosed without the written authorization from 
*   XBDZ Technologies.
************************************************************************************************
*   File Name       : 
************************************************************************************************
*   Project/Product : Fan Project
*   Title           : Fan Software 
*   Author          : 017
************************************************************************************************
*   Description     :  
*                     
*
************************************************************************************************
*   END_FILE_HDR*/

#ifndef MC_CAL_H
#define MC_CAL_H

#include "parameters.h"
#include "common.h"



#ifdef   MC_CAL_C
#define  MC_CAL_EXT   
#else
#define  MC_CAL_EXT  extern
#endif 

typedef struct
{
sint16 coefA;
sint16 coefB;
sint32 out;
}Mc_LpParType;

extern const uint16 Mc_sin[];
MC_CAL_EXT sint32 Math_Sin(uint16 angle);
MC_CAL_EXT sint32 Math_Cos(uint16 angle);
MC_CAL_EXT uint16 Math_ArcTanCal(sint32 a, sint32 b, uint32 *amp);
MC_CAL_EXT void Math_Clack(s16 Ua, s16 Ub, s16 Uc, s16* Ualpha, s16* Ubeta);
MC_CAL_EXT void Math_Clack_Inv(s16* Ua, s16* Ub, s16* Uc, s16 Ualpha, s16 Ubeta);
MC_CAL_EXT void Math_Park(s16 Ualpha, s16 Ubeta, u16 angleQ16, s16* Ud, s16* Uq);
MC_CAL_EXT void Math_Park_Inv(s16* Ualpha, s16* Ubeta, u16 angleQ16, s16 Ud, s16 Uq);
MC_CAL_EXT sint16 Mc_LowPassFilter(Mc_LpParType *lp, sint16 input);



#endif


