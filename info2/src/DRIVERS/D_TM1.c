/*
 * D_TM1.c
 *
 *  Created on: 25/10/2016
 *      Author: Usuario
 */


#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

void TIMER1_IRQHandler(void)
{
	if(T1IR & 1)
		{

		//apago abertura y cerradura

		SetPIN(OUT0,OFF);
		SetPIN(OUT1,OFF);

		T1TCR |= (~( 1 << CE) );

		T1IR |= (1 << 0);

		}
}
