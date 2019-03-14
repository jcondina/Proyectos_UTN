/*
 * -UART0.c
 *
 *  Created on: Aug 22, 2016
 *      Author: juani
 */

#include "../HEADERS/Aplicacion.h"

void  UART0_IRQHandler(void)
{
	uint32_t temp;

	do
	{
		temp = U0IIR;

		switch((temp>>1)&(0x03))
		{
			case 2:
					UART0_Rx();
					break;

			case 1:
					UART0_Tx(temp);
					break;
			case 3:
					//ERROR
					break;
			default:
					break;
		}
	}while(~(temp & 1));
}

void UART0_Rx(void)
{
	uint8_t dato = U0RBR;
	Push0_Rx(dato);
}

void UART0_Tx(unsigned char dato)
{
	// No realiza transmision
}
