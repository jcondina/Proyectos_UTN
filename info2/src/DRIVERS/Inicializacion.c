/*
 * Inicializacion.c
 *
 *  Created on: 7/8/2016
 *      Author: Usuario
 */
#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

//-----------------------FUNCION INICIALIZACION-------------------------------


void Inicializacion (void)
{
	Inic_PLL();
	Inic_SysTick(100000);
	Inic_GPIOs();
	Inic_DAC();
	Inic_Timer0();
	Inic_Timer1();
	Inic_UART0();
	Inic_UART1();
	Inic_ADC();
	Inic_LCD();
	SetPIN(RGBB,OFF);
	SetPIN(RGBR,OFF);
	SetPIN(RGBG,OFF);
	CerrarBarrera();


}

