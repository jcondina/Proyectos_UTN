/*
 * Uart0.c
 *
 *  Created on: 21/8/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

extern int TxStart;

void  UART0_IRQHandler(void)
{

	uint32_t temp;

	do
	{

		temp = U0IIR;//igualo una variable temporal al regitro que me indica porq interrumpio la UART

		switch((temp>>1)&(0x03))//me fijo porq motivo interumpio la UART
		{
			case 2://interupcion por recepcion
					UART0_Rx();
					break;

			case 1://interupcion por trasmicion
					UART0_Tx();
					break;
			case 3:
					//ERROR

					break;
			default:

					break;
		}

		if(temp&1)
			return;

	}while(1);
}

void UART0_Rx( void)
{
	uint8_t dato = U0RBR;//igualo una variable al registro que posee el valor que me llego por uart
	Push0_Rx(dato); //cargo ese valor en un vector
}

void UART0_Tx(void)
{
	int envio;
	envio=pop_TX0();//levanto el valor que quiero enviar por uart y lo pongo en la variable envio..envio se carga con -1 cuando no hay dato para enviar
	if(envio != -1)//pregunto si hay valor para enviar
	{
		REG_SAL_TX0=envio; //cargo el valor a enviar al registro de salida
	}
	else
	{
		TxStart =0; //si no hay dato pongo un flag en 0
	}
}


