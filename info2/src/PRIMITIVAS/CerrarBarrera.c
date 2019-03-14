/*
 * CerrarBarrera.c
 *
 *  Created on: 26/10/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

extern uint8_t est_valido_FC;
void CerrarBarrera(void)
{
	do{
	SetPIN(OUT0,OFF);
	SetPIN(OUT1,ON);

	}while(est_valido_FC==0);

	SetPIN(OUT1,OFF);
	SetPIN(OUT0,OFF);

	//T1TCR |= ( 1 << CE );

}
