/*
 * UART1.c
 *
 *  Created on: Aug 22, 2016
 *      Author: juani
 */

#include "../HEADERS/Aplicacion.h"

void  UART1_IRQHandler(void)
{
	unsigned char temp;

	do
	{
		temp = U1IIR;

		switch((temp>>1)&(0x03))
		{
			case 2:
					UART1_Rx(temp);
					break;

			case 1:
					UART1_Tx(temp);
					break;
			case 3:
					//ERROR
					break;
			default:
					break;
		}
	}while(~(temp & 1));
}

void UART1_Rx(unsigned char dato)
{
	Push1_Rx(dato);
}

 void UART1_Tx(unsigned char dato)
{
	// No realiza transmision
}

