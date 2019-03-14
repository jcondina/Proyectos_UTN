/*
 * Inic_DAC.c
 *
 *  Created on: 7/8/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"




void Inic_DAC (void)
{
	SetPINSEL(DAC,FUNCION_2);
	DACCTRL = 0;
	DACR = 0;

}
