/*

 * maq_LUZ.c
 *
 *  Created on: 19/10/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

extern uint32_t valor_promedio_luz;
extern uint32_t luz_de_encendido;

//chequeo si el valor obtenido del adc es mayor al necesario para prender la luz.. si es asi actio el reley si no lo apago.

void maq_LUZ(void)
{
	if(valor_promedio_luz >= luz_de_encendido)
	{

		SetPIN(RLY1,ON);

	}

	else
	{
		SetPIN(RLY1,OFF);

	}

}



