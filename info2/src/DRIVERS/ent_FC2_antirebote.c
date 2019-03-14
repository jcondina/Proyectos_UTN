/*
 * ent_FC2_antirebote.c
 *
 *  Created on: 15/11/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

uint8_t est_actual4;
uint8_t est_anterior4;
extern uint8_t est_valido_FC2;

//Hago la lectura del final de carrera 2 y chequeo que no haya sido ruido lo que lo activo para eso me fijo que el mismo valor se mantenga 20 veces

void ent_FC2_antirebote(void)
{
	static int cont_FC2=0;

	est_actual4 = GetPIN(IN3,1);

	if (est_actual4 == est_anterior4)
	{


		if (cont_FC2 >= 20)
		{
			est_valido_FC2 = est_actual4;
		}

		else
		{
			cont_FC2++;
		}
	}
	else
	{

	cont_FC2	= 0;
	est_anterior4 =est_actual4;

	}

	est_anterior4 =est_actual4;

}
