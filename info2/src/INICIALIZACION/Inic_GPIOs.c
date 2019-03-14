/*
 * Inic_GPIOs.c
 *
 *  Created on: 7/8/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

void Inic_GPIOs()
{
	//Entradas digitales SENSORES :
		//IN0 :
		SetPINSEL(IN0,FUNCION_GPIO);
		SetDIR(IN0,ENTRADA);

		//IN1 :
		SetPINSEL(IN1,FUNCION_GPIO);
		SetDIR(IN1,ENTRADA);

		//IN2:
		SetPINSEL(IN2,FUNCION_GPIO);
		SetDIR(IN2,ENTRADA);
		SetPINMODE(IN2,3);


		//IN3:
		SetPINSEL(IN3,FUNCION_GPIO);
		SetDIR(IN3,ENTRADA);
		SetPINMODE(IN3,3);





	//Salida motor
		//OUT0:
		SetPINSEL(OUT0,FUNCION_GPIO);
		SetDIR(OUT0,SALIDA);

		//OUT1:
		SetPINSEL(OUT1,FUNCION_GPIO);
		SetDIR(OUT1,SALIDA);

	//PULSADOR:

		SetPINSEL(SW1,FUNCION_GPIO);
		SetDIR(SW1,ENTRADA);


		SetPINSEL(SW2,FUNCION_GPIO);
		SetDIR(SW2,ENTRADA);

	//RGB LEDS
		SetPINSEL(RGBB,FUNCION_GPIO);
		SetDIR(RGBB,SALIDA);

		SetPINSEL(RGBR,FUNCION_GPIO);
		SetDIR(RGBR,SALIDA);

		SetPINSEL(RGBG,FUNCION_GPIO);
		SetDIR(RGBG,SALIDA);



	//Relay

		SetPINSEL(RLY1,FUNCION_GPIO);
		SetDIR(RLY1,SALIDA);

	//FC1
		SetPINSEL(IN2,FUNCION_GPIO);
		SetDIR(IN2,ENTRADA);
	//FC2
		SetPINSEL(IN3,FUNCION_GPIO);
		SetDIR(IN3,ENTRADA);

}
