#ifndef _GPIO_H_
#define _GPIO_H_

#include "common.h"
#include "stm32f10x_gpio.h"

//////////////////////////////WARNING////////////////////////
#ifndef ENABLE
#define ENABLE                                  1
#define DISABLE                                 0
#endif
/////////////////////////////////////////////////////////////

#define GPIO_SPEED_DEFAULT              0
#define GPIO_EXTI_LINE_SOURCE_NON       0x07

///////////////////////Config EXTI Line Source//////////////////////////////
#define GPIO_EXTI_LINE_SOURCE_0_ENABLE  DISABLE
#define GPIO_EXTI_LINE_SOURCE_0_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_1_ENABLE  DISABLE
#define GPIO_EXTI_LINE_SOURCE_1_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_2_ENABLE  DISABLE
#define GPIO_EXTI_LINE_SOURCE_2_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_3_ENABLE  DISABLE
#define GPIO_EXTI_LINE_SOURCE_3_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_4_ENABLE  DISABLE
#define GPIO_EXTI_LINE_SOURCE_4_PORT	GPIO_PortSourceGPIOE

#define GPIO_EXTI_LINE_SOURCE_5_ENABLE  DISABLE
#define GPIO_EXTI_LINE_SOURCE_5_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_6_ENABLE  DISABLE
#define GPIO_EXTI_LINE_SOURCE_6_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_7_ENABLE  DISABLE
#define GPIO_EXTI_LINE_SOURCE_7_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_8_ENABLE  DISABLE
#define GPIO_EXTI_LINE_SOURCE_8_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_9_ENABLE  DISABLE
#define GPIO_EXTI_LINE_SOURCE_9_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_10_ENABLE DISABLE
#define GPIO_EXTI_LINE_SOURCE_10_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_11_ENABLE DISABLE
#define GPIO_EXTI_LINE_SOURCE_11_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_12_ENABLE DISABLE
#define GPIO_EXTI_LINE_SOURCE_12_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_13_ENABLE DISABLE
#define GPIO_EXTI_LINE_SOURCE_13_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_14_ENABLE DISABLE
#define GPIO_EXTI_LINE_SOURCE_14_PORT	GPIO_EXTI_LINE_SOURCE_NON

#define GPIO_EXTI_LINE_SOURCE_15_ENABLE DISABLE
#define GPIO_EXTI_LINE_SOURCE_15_PORT   GPIO_EXTI_LINE_SOURCE_NON
////////////////////////////////////////////////////////////////////////////

#define GPIO_PORT_A 					GPIOA
#define GPIO_PORT_B 					GPIOB
#define GPIO_PORT_C 					GPIOC
#define GPIO_PORT_D 					GPIOD
#define GPIO_PORT_E						GPIOE
#define GPIO_PORT_F 					GPIOF
#define GPIO_PORT_G 					GPIOG

#define GPIO_PIN_0   				 	GPIO_Pin_0
#define GPIO_PIN_1    					GPIO_Pin_1
#define GPIO_PIN_2    					GPIO_Pin_2
#define GPIO_PIN_3  					GPIO_Pin_3
#define GPIO_PIN_4  					GPIO_Pin_4
#define GPIO_PIN_5  					GPIO_Pin_5
#define GPIO_PIN_6 					    GPIO_Pin_6
#define GPIO_PIN_7  					GPIO_Pin_7
#define GPIO_PIN_8  					GPIO_Pin_8
#define GPIO_PIN_9    					GPIO_Pin_9
#define GPIO_PIN_10  					GPIO_Pin_10
#define GPIO_PIN_11   					GPIO_Pin_11
#define GPIO_PIN_12   					GPIO_Pin_12
#define GPIO_PIN_13   					GPIO_Pin_13
#define GPIO_PIN_14   					GPIO_Pin_14
#define GPIO_PIN_15   					GPIO_Pin_15
#define GPIO_PIN_ALL  					GPIO_Pin_All

#define GPIO_MODE_AIN					GPIO_Mode_AIN
#define GPIO_MODE_IN_FLOATING			GPIO_Mode_IN_FLOATING
#define GPIO_MODE_IPD					GPIO_Mode_IPD
#define GPIO_MODE_IPU					GPIO_Mode_IPU
#define GPIO_MODE_Out_OD				GPIO_Mode_Out_OD
#define GPIO_MODE_Out_PP				GPIO_Mode_Out_PP
#define GPIO_MODE_AF_OD					GPIO_Mode_AF_OD
#define GPIO_MODE_AF_PP					GPIO_Mode_AF_PP

#define GPIO_SPEED_2MHZ					GPIO_Speed_2MHz
#define GPIO_SPEED_10MHZ				GPIO_Speed_10MHz
#define GPIO_SPEED_50MHZ				GPIO_Speed_50MHz




#define GPIO_STATE_ON  					Bit_SET
#define GPIO_STATE_OFF 					Bit_RESET

typedef enum{
	INPUT,
	OUTPUT
}gpio_direction;


extern void Gpio_Init(GPIO_TypeDef* port, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed);
extern void Gpio_SetPort(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, BitAction action);
extern uint8 Gpio_GetPort(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, gpio_direction direction);




#endif
