#ifndef _GPIO_C_
#define _GPIO_C_

#include "gpio.h"


#define GPIO_FUN_ON  1
#define GPIO_FUN_OFF 0

#define GPIO_BOARD_LED0_PB5 GPIO_FUN_ON
#define GPIO_BOARD_LED1_PE5 GPIO_FUN_ON

void Gpio_SetPort(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, BitAction action)
{
	GPIO_WriteBit(GPIOx, GPIO_Pin, action);
}

uint8 Gpio_GetPort(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, gpio_direction direction)
{
	if(direction == INPUT)
	{
		return GPIO_ReadInputDataBit(GPIOx, GPIO_Pin);
	}else
	{
		return GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin);
	}	
}

void Gpio_Init(GPIO_TypeDef* port, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed)
{
	GPIO_InitTypeDef Gpio_Config_Structure;	 
	Gpio_Config_Structure.GPIO_Pin   = pin;
	Gpio_Config_Structure.GPIO_Mode  = mode;
	Gpio_Config_Structure.GPIO_Speed = speed;
	GPIO_Init(port,&Gpio_Config_Structure);	
}



#endif
