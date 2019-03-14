/*
 * ent_antirebote_FC.c
 *
 *  Created on: 12/11/2016
 *      Author: Usuario
 */



#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

uint8_t est_actual3;
uint8_t est_anterior3;
extern uint8_t est_valido_FC;
//Hago la lectura del final de carrera 1 y chequeo que no haya sido ruido lo que lo activo para eso me fijo que el mismo valor se mantenga 20 veces
void ent_FC_antirebote(void)
{
	static int cont_FC=0;
	est_actual3 = GetPIN(IN2,1);

	if (est_actual3 == est_anterior3)
	{



		if (cont_FC >= 20)
		{
			est_valido_FC = est_actual3;
		}

		else
		{
			cont_FC++;
		}
	}
	else
	{

	cont_FC	= 0;
	est_anterior3 =est_actual3;

	}

	est_anterior3 =est_actual3;

}
