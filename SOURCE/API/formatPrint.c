#ifndef _FORMATPRINT_C_
#define _FORMATPRINT_C_

#include "formatPrint.h"


/*
void sendbit(USART_TypeDef* USARTx,unsigned char uchar)
{
	USART_SendData(USARTx,uchar);

	while(!USART_GetFlagStatus(USARTx,USART_FLAG_TXE));
}

void senstring(USART_TypeDef* USARTx,char* string)
{
	char* str=string;
	while(*str)
	{
		sendbit(USARTx,*str);
		str++;
	}
}

int fputc(int ch,FILE *p)
{
	sendbit(USART1,(uint8_t)ch);

	return ch;

}

int fgetc(FILE *f)
{
	while(!USART_GetFlagStatus(USART1,USART_FLAG_RXNE));

	return (int)USART_ReceiveData(USART1);
}

*/

#endif

