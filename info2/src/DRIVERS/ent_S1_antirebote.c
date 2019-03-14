/*
 * ent_S1_antirebote.c
 *
 *  Created on: 25/10/2016
 *      Author: Usuario
 */
#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"


uint8_t est_actual;
uint8_t est_anterior;
extern uint8_t est_valido_S1;


//Hago la lectura del sensor 1 y chequeo que no haya sido ruido lo que lo activo para eso me fijo que el mismo valor se mantenga 20 veces

void ent_S1_antirebote(void)
{

	static int cont_S1=0;
	est_actual = GetPIN(IN0,1);

	if (est_actual == est_anterior)
	{


		if (cont_S1 >= 20)
		{
			est_valido_S1 = est_actual;
			cont_S1 =0;
		}

		else
		{
			cont_S1++;
		}
	}
	else
	{

	cont_S1	= 0;
	est_anterior =est_actual;
	}

	est_anterior =est_actual;

}
