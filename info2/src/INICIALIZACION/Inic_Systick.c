/*
 * Inic_Systick.c
 *
 *  Created on: 7/8/2016
 *      Author: Usuario
 */
#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

	void Inic_SysTick ( uint32_t ticks )
	{

		STRELOAD = ( ticks - 1);	// Recarga cada 2.5 ms
		STCURR = 0;	// Cargando con cero limpio y provoco el disparo de una intrrupcion
		//SYSTICK[ENABLE] = 1;// Habilito el conteo
		//SYSTICK[TICKINT] = 1;// Habilito interrupcion
		//SYSTICK[CLKSOURCE] = 1 ;// Utilizamos Pclk
		STCTRL |=  ( ( 1 << ENABLE ) | ( 1 << TICKINT ) | ( 1 << CLKSOURCE ) );
	}

