#ifndef _COMMON_H_
#define _COMMON_H_

#include "stm32f10x.h"


typedef unsigned short uint16;
typedef unsigned char  uint8;
typedef unsigned int   uint32;

typedef signed short   sint16;
typedef signed char    sint8;
typedef signed int     sint32;


typedef enum{
	false = 0,
	true
} bool;


typedef struct{
	uint8 	startFlag_ms:1;
	uint8 	doneFlag_ms:1;
	uint8 	count_1ms:6;
}common_delay_struct;
extern volatile common_delay_struct Common_Delay_Struct;

extern void delay_dead_ms(uint16 ms);


#endif
