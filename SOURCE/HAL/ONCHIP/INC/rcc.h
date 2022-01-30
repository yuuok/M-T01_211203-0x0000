#ifndef _RCC_H_
#define _RCC_H_

#include "common.h"
#include "stm32f10x_rcc.h"

#define HSE 0
#define HSI 1// 8MHz // div 2

#define DIV1 0
#define DIV2 1

//////////////////////////////WARNING////////////////////////
#define ENABLE                                  1
#define DISABLE                                 0
/////////////////////////////////////////////////////////////


#define FreMhz(num) 							(uint8)(num)

#define RCC_Desired_PllInput 					HSE
#define RCC_SYS_HSECLK 							FreMhz(8)
#define RCC_Desired_PLLCLK 						FreMhz(72)

#define RCC_Desired_PLLINPUTDIV 				DIV1

#define RCC_SYSCLK_FRE							72    


#define RCC_CLKFRE_HCLK							FreMhz(72)
#define RCC_CLKFRE_PCLK1						FreMhz(36)
#define RCC_CLKFRE_PCLK2						FreMhz(72)



///////////////////////AHB_CLK/////////////////////////
#define RCC_AHBPERIPH_CLK_ENABLE				ENABLE
//CLK SELECT
#define RCC_AHBPeriph_ENABLE_DMA1               ENABLE
#define RCC_AHBPeriph_ENABLE_DMA2               DISABLE
#define RCC_AHBPeriph_ENABLE_SRAM               DISABLE
#define RCC_AHBPeriph_ENABLE_FLITF              DISABLE
#define RCC_AHBPeriph_ENABLE_CRC                DISABLE
#ifndef STM32F10X_CL
 #define RCC_AHBPeriph_ENABLE_FSMC              DISABLE
 #define RCC_AHBPeriph_ENABLE_SDIO              DISABLE
#else
 #define RCC_AHBPeriph_ENABLE_OTG_FS            DISABLE
 #define RCC_AHBPeriph_ENABLE_ETH_MAC           DISABLE
 #define RCC_AHBPeriph_ENABLE_ETH_MAC_Tx        DISABLE
 #define RCC_AHBPeriph_ENABLE_ETH_MAC_Rx        DISABLE
#endif /* STM32F10X_CL */


////////////////////////////////////////////////////////



///////////////////////ABP1_CLK/////////////////////////
#define RCC_APB1PERIPH_CLK_ENABLE				ENABLE
//CLK SELECT
#define RCC_APB1Periph_ENABLE_TIM2              ENABLE
#define RCC_APB1Periph_ENABLE_TIM3              ENABLE
#define RCC_APB1Periph_ENABLE_TIM4              DISABLE
#define RCC_APB1Periph_ENABLE_TIM5              DISABLE
#define RCC_APB1Periph_ENABLE_TIM6              DISABLE
#define RCC_APB1Periph_ENABLE_TIM7              DISABLE
#define RCC_APB1Periph_ENABLE_TIM12             DISABLE
#define RCC_APB1Periph_ENABLE_TIM13             DISABLE
#define RCC_APB1Periph_ENABLE_TIM14             DISABLE
#define RCC_APB1Periph_ENABLE_WWDG              DISABLE
#define RCC_APB1Periph_ENABLE_SPI2              DISABLE
#define RCC_APB1Periph_ENABLE_SPI3              DISABLE
#define RCC_APB1Periph_ENABLE_USART2            DISABLE
#define RCC_APB1Periph_ENABLE_USART3            DISABLE
#define RCC_APB1Periph_ENABLE_UART4             DISABLE
#define RCC_APB1Periph_ENABLE_UART5             DISABLE
#define RCC_APB1Periph_ENABLE_I2C1              DISABLE
#define RCC_APB1Periph_ENABLE_I2C2              DISABLE
#define RCC_APB1Periph_ENABLE_USB               DISABLE
#define RCC_APB1Periph_ENABLE_CAN1              DISABLE
#define RCC_APB1Periph_ENABLE_CAN2              DISABLE
#define RCC_APB1Periph_ENABLE_BKP               DISABLE
#define RCC_APB1Periph_ENABLE_PWR               DISABLE
#define RCC_APB1Periph_ENABLE_DAC               DISABLE
#define RCC_APB1Periph_ENABLE_CEC               DISABLE

////////////////////////////////////////////////////////


///////////////////////ABP2_CLK/////////////////////////
#define RCC_APB2PERIPH_CLK_ENABLE				ENABLE
//CLK SELECT
#define RCC_APB2Periph_ENABLE_AFIO              ENABLE
#define RCC_APB2Periph_ENABLE_GPIOA             ENABLE
#define RCC_APB2Periph_ENABLE_GPIOB             ENABLE
#define RCC_APB2Periph_ENABLE_GPIOC             ENABLE
#define RCC_APB2Periph_ENABLE_GPIOD             DISABLE
#define RCC_APB2Periph_ENABLE_GPIOE             DISABLE
#define RCC_APB2Periph_ENABLE_GPIOF             DISABLE
#define RCC_APB2Periph_ENABLE_GPIOG            	DISABLE
#define RCC_APB2Periph_ENABLE_ADC1             	ENABLE
#define RCC_APB2Periph_ENABLE_ADC2             	ENABLE
#define RCC_APB2Periph_ENABLE_TIM1             	ENABLE
#define RCC_APB2Periph_ENABLE_SPI1             	DISABLE
#define RCC_APB2Periph_ENABLE_TIM8             	DISABLE
#define RCC_APB2Periph_ENABLE_USART1           	DISABLE
#define RCC_APB2Periph_ENABLE_ADC3             	DISABLE
#define RCC_APB2Periph_ENABLE_TIM15            	DISABLE
#define RCC_APB2Periph_ENABLE_TIM16            	DISABLE
#define RCC_APB2Periph_ENABLE_TIM17            	DISABLE
#define RCC_APB2Periph_ENABLE_TIM9             	DISABLE
#define RCC_APB2Periph_ENABLE_TIM10            	DISABLE
#define RCC_APB2Periph_ENABLE_TIM11            	DISABLE
////////////////////////////////////////////////////////




void Rcc_Init(void);


#endif

