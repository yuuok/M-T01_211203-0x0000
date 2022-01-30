#ifndef _RCC_C_
#define _RCC_C_

#include "rcc.h"






#if RCC_Desired_PllInput == HSE
 #if RCC_Desired_PLLINPUTDIV == DIV1
  #define RCC_MUL_CALDIV 1
  #define RCC_PLLSOURCE_AND_DIV RCC_PLLSource_HSE_Div1 
 #else
  #define RCC_MUL_CALDIV 2
  #define RCC_PLLSOURCE_AND_DIV RCC_PLLSource_HSE_Div2 
 #endif
 #define RCC_PLLCLK_MUl (((uint32)RCC_Desired_PLLCLK/(RCC_SYS_HSECLK/RCC_MUL_CALDIV))-2)<<18
#else
 #define RCC_MUL_CALDIV 2
 #define RCC_PLLSOURCE_AND_DIV RCC_PLLSource_HSI_Div2 
 #define RCC_PLLCLK_MUl (((uint32)RCC_Desired_PLLCLK/(RCC_SYS_HSECLK/RCC_MUL_CALDIV))-2)<<18
#endif


#define RCC_SYSCLKSource_CHECK_PLLCLK       (RCC_SYSCLKSource_PLLCLK << 2)
#define RCC_IsSysClkToPLL() 	while(!((uint8)RCC_SYSCLKSource_CHECK_PLLCLK  == RCC_GetSYSCLKSource()))


void Rcc_Init(void)
{
	uint32 ahb_clk = 1;
	uint32 apb1_clk = 1;
	uint32 apb2_clk = 1;
	/////////////////////////////////////////////////////////////////////////////////////////////////
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_ON);//enable HSE
	while(!RCC_WaitForHSEStartUp());//wait for HSE stable
	RCC_PLLConfig(RCC_PLLSOURCE_AND_DIV,RCC_PLLCLK_MUl);//HSE = 8MHz, PLLMul = 9, PLLCLK = 72MHz
	RCC_PLLCmd(ENABLE);//enable PLL
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//use pllclk as sysclk

	RCC_IsSysClkToPLL();//wait for sysclk set to sysclk
	/////////////////////////////////////////////////////////////////////////////////////////////////
	
	RCC_HCLKConfig(RCC_SYSCLK_Div1);//set HCLK(AHB) to 72MHz
	RCC_PCLK1Config(RCC_HCLK_Div2);//set APB1 to 36MHz
	RCC_PCLK2Config(RCC_HCLK_Div1);//set APB2 to 72MHz

	/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////AHB CLK SET//////////////////////////////////////
#if RCC_AHBPERIPH_CLK_ENABLE
//CLK SELECT

#if RCC_AHBPeriph_ENABLE_DMA2
	ahb_clk |= RCC_AHBPeriph_DMA2;
#endif

#if RCC_AHBPeriph_ENABLE_SRAM
	ahb_clk |= RCC_AHBPeriph_SRAM;
#endif

#if  RCC_AHBPeriph_ENABLE_FLITF
	ahb_clk |= RCC_AHBPeriph_FLITF;
#endif

#if  RCC_AHBPeriph_ENABLE_CRC
	ahb_clk |= RCC_AHBPeriph_CRC;
#endif

#ifndef STM32F10X_CL
 #if RCC_AHBPeriph_ENABLE_FSMC
 	ahb_clk |= RCC_AHBPeriph_FSMC;
 #endif
 
 #if RCC_AHBPeriph_ENABLE_SDIO
 	ahb_clk |= RCC_AHBPeriph_SDIO;
 #endif
 
#else
 #if RCC_AHBPeriph_ENABLE_OTG_FS
 	ahb_clk |= RCC_AHBPeriph_OTG_FS;
 #endif
 
 #if RCC_AHBPeriph_ENABLE_ETH_MAC
 	ahb_clk |= RCC_AHBPeriph_ETH_MAC;
 #endif
 
 #if RCC_AHBPeriph_ENABLE_ETH_MAC_Tx
 	ahb_clk |= RCC_AHBPeriph_ETH_MAC_Tx;
 #endif
 
 #if RCC_AHBPeriph_ENABLE_ETH_MAC_Rx
 	ahb_clk |= RCC_AHBPeriph_ETH_MAC_Rx;
 #endif
 
#endif /* STM32F10X_CL */

#if !RCC_AHBPeriph_ENABLE_DMA1
	ahb_clk &= ~RCC_AHBPeriph_DMA1;
#endif

	RCC_AHBPeriphClockCmd(ahb_clk, RCC_AHBPERIPH_CLK_ENABLE);

#endif
//////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////APB1 CLK SET/////////////////////////////////////
#if RCC_APB1PERIPH_CLK_ENABLE	
//CLK SELECT

#if RCC_APB1Periph_ENABLE_TIM3  
	apb1_clk |= RCC_APB1Periph_TIM3;
#endif

#if RCC_APB1Periph_ENABLE_TIM4  
	apb1_clk |= RCC_APB1Periph_TIM4;
#endif

#if RCC_APB1Periph_ENABLE_TIM5 
	apb1_clk |= RCC_APB1Periph_TIM5;
#endif

#if RCC_APB1Periph_ENABLE_TIM6 
	apb1_clk |= RCC_APB1Periph_TIM6;
#endif

#if RCC_APB1Periph_ENABLE_TIM7   
	apb1_clk |= RCC_APB1Periph_TIM7;
#endif

#if RCC_APB1Periph_ENABLE_TIM12 
	apb1_clk |= RCC_APB1Periph_TIM12;
#endif

#if RCC_APB1Periph_ENABLE_TIM13  
	apb1_clk |= RCC_APB1Periph_TIM13;
#endif

#if RCC_APB1Periph_ENABLE_TIM14  
	apb1_clk |= RCC_APB1Periph_TIM14;
#endif

#if RCC_APB1Periph_ENABLE_WWDG 
	apb1_clk |= RCC_APB1Periph_WWDG;
#endif

#if RCC_APB1Periph_ENABLE_SPI2  
	apb1_clk |= RCC_APB1Periph_SPI2;
#endif

#if RCC_APB1Periph_ENABLE_SPI3
	apb1_clk |= RCC_APB1Periph_SPI3;
#endif

#if RCC_APB1Periph_ENABLE_USART2  
	apb1_clk |= RCC_APB1Periph_USART2;
#endif

#if RCC_APB1Periph_ENABLE_USART3
	apb1_clk |= RCC_APB1Periph_USART3;
#endif

#if RCC_APB1Periph_ENABLE_UART4    
	apb1_clk |= RCC_APB1Periph_UART4;
#endif

#if RCC_APB1Periph_ENABLE_UART5 
	apb1_clk |= RCC_APB1Periph_UART5;
#endif

#if RCC_APB1Periph_ENABLE_I2C1  
	apb1_clk |= RCC_APB1Periph_I2C1;
#endif

#if RCC_APB1Periph_ENABLE_I2C2 
	apb1_clk |= RCC_APB1Periph_I2C2;
#endif

#if RCC_APB1Periph_ENABLE_USB  
	apb1_clk |= RCC_APB1Periph_USB;
#endif

#if RCC_APB1Periph_ENABLE_CAN1 
	apb1_clk |= RCC_APB1Periph_CAN1;
#endif

#if RCC_APB1Periph_ENABLE_CAN2 
	apb1_clk |= RCC_APB1Periph_CAN2;
#endif

#if RCC_APB1Periph_ENABLE_BKP 
	apb1_clk |= RCC_APB1Periph_BKP;
#endif

#if RCC_APB1Periph_ENABLE_PWR    
	apb1_clk |= RCC_APB1Periph_PWR;
#endif

#if RCC_APB1Periph_ENABLE_DAC   
	apb1_clk |= RCC_APB1Periph_DAC;
#endif

#if RCC_APB1Periph_ENABLE_CEC  
	apb1_clk |= RCC_APB1Periph_CEC;
#endif

#if !RCC_APB1Periph_ENABLE_TIM2 
	apb1_clk &= ~RCC_APB1Periph_TIM2; 
#endif

	RCC_APB1PeriphClockCmd(apb1_clk, RCC_APB1PERIPH_CLK_ENABLE);

#endif
//////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////APB2 CLK SET/////////////////////////////////////
#if RCC_APB2PERIPH_CLK_ENABLE
//CLK SELECT

#if RCC_APB2Periph_ENABLE_GPIOA
	apb2_clk |= RCC_APB2Periph_GPIOA;
#endif

#if RCC_APB2Periph_ENABLE_GPIOB  
	apb2_clk |= RCC_APB2Periph_GPIOB;
#endif

#if RCC_APB2Periph_ENABLE_GPIOC 
	apb2_clk |= RCC_APB2Periph_GPIOC;
#endif

#if RCC_APB2Periph_ENABLE_GPIOD 
	apb2_clk |= RCC_APB2Periph_GPIOD;
#endif

#if RCC_APB2Periph_ENABLE_GPIOE
	apb2_clk |= RCC_APB2Periph_GPIOE;
#endif

#if RCC_APB2Periph_ENABLE_GPIOF 
	apb2_clk |= RCC_APB2Periph_GPIOF;
#endif

#if RCC_APB2Periph_ENABLE_GPIOG
	apb2_clk |= RCC_APB2Periph_GPIOG;
#endif

#if RCC_APB2Periph_ENABLE_ADC1  
	apb2_clk |= RCC_APB2Periph_ADC1;
#endif

#if RCC_APB2Periph_ENABLE_ADC2 
	apb2_clk |= RCC_APB2Periph_ADC2;
#endif

#if RCC_APB2Periph_ENABLE_TIM1     
	apb2_clk |= RCC_APB2Periph_TIM1;
#endif

#if RCC_APB2Periph_ENABLE_SPI1  
	apb2_clk |= RCC_APB2Periph_SPI1;
#endif

#if RCC_APB2Periph_ENABLE_TIM8   
	apb2_clk |= RCC_APB2Periph_TIM8;
#endif

#if RCC_APB2Periph_ENABLE_USART1     
	apb2_clk |= RCC_APB2Periph_USART1;
#endif

#if RCC_APB2Periph_ENABLE_ADC3 
	apb2_clk |= RCC_APB2Periph_ADC3;
#endif

#if RCC_APB2Periph_ENABLE_TIM15   
	apb2_clk |= RCC_APB2Periph_TIM15;
#endif

#if RCC_APB2Periph_ENABLE_TIM16
	apb2_clk |= RCC_APB2Periph_TIM16;
#endif

#if RCC_APB2Periph_ENABLE_TIM17  
	apb2_clk |= RCC_APB2Periph_TIM17;
#endif

#if RCC_APB2Periph_ENABLE_TIM9    
	apb2_clk |= RCC_APB2Periph_TIM9;
#endif

#if RCC_APB2Periph_ENABLE_TIM10  
	apb2_clk |= RCC_APB2Periph_TIM10;
#endif

#if RCC_APB2Periph_ENABLE_TIM11
	apb2_clk |= RCC_APB2Periph_TIM11;
#endif

#if !RCC_APB2Periph_ENABLE_AFIO  
	apb2_clk &= ~RCC_APB2Periph_AFIO;  
#endif

	RCC_APB2PeriphClockCmd(apb2_clk, RCC_APB2PERIPH_CLK_ENABLE);

#endif
//////////////////////////////////////////////////////////////////////////////////////////

	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOB,ENABLE);//GPIO E/B CLK enable
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//GPIO B CLK enable	

}



#endif

