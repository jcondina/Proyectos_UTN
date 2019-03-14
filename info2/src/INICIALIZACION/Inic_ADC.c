/*
 * Inic_ADC.c
 *
 *  Created on: 7/8/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

void Inic_ADC (void)
{
	PCONP |= (1<<12);

	//seteo pines como ADC
	SetPINSEL(EA2,FUNCION_1); //cambiar y poner entrada del sensor de luz

	// Div/8
	PCLKSEL0|= (3<<24);

	// Habilitamos interrupcion por ADC
	ISER0 |=(1<<22);

	//Selecciono canal, enciendo modulo PDN, y lo pongo en modo disparo
	AD0CR |= ((1<<2) | (1<<21) | (1<<24));


}
