/*
 * D_ADC.c
 *
 *  Created on: 30/8/2016
 *      Author: Usuario
 */
#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

extern uint32_t valorADC;

//cuando interumpe es que se genero una convercion del adc el valor lo guardo en valorADC.

void ADC_IRQHandler(void)
{
	valorADC = ((AD0GDR>>4)&(0xfff)); // lectura desplazo y recorto porq lo unico que me sirve es del 15-4
	AD0CR |= (1<<24); //disparo convercion

}
