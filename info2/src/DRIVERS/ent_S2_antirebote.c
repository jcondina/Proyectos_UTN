/*
 * ent_S2_antirebote.c
 *
 *  Created on: 25/10/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

uint8_t est_actual2;
uint8_t est_anterior2;
extern uint8_t est_valido_S2;

//Hago la lectura del sensor 2 y chequeo que no haya sido ruido lo que lo activo para eso me fijo que el mismo valor se mantenga 20 veces

void ent_S2_antirebote(void)
{
	static int cont_S2=0;
	est_actual2 = GetPIN(IN1,0);

	if (est_actual2 == est_anterior2)
	{


		if (cont_S2 >= 20)
		{
			est_valido_S2 = est_actual2;
		}

		else
		{
			cont_S2++;
		}
	}
	else
	{

	cont_S2	= 0;
	est_anterior2 =est_actual2;

	}

	est_anterior2 =est_actual2;

}
