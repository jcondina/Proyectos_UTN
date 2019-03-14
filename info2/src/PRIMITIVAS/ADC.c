/*
 * ADC.c
 *
 *  Created on: 30/8/2016
 *      Author: Usuario
 */
#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

uint32_t valor_acumulador;
uint8_t contador;
extern uint32_t valor_promedio_luz;


//sumo 100 valores del ADC y hago el promedio...Ese valor es el que guardo y compraro en la maq_LUZ
void ADC_promedio(uint32_t valor)
{
	valor_acumulador += valor;
	contador++;

	if(contador>=100)
	{
		contador=0;
		valor_promedio_luz= valor_acumulador/100;
		valor_acumulador=0;


	}

}

