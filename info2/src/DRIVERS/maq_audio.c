/*
 * maq_audio.c
 *
 *  Created on: 19/10/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

extern uint8_t audio_flag;


//segun el audio que quiera reproducir activo un flag y activo el timer
void maq_audio(int sel_audio)
{
	switch (sel_audio)
	{
	case 0:
		audio_flag = 0;
		T0TCR |= (    1 << CE ) ;
		break;
	case 1:
		audio_flag = 1;
		T0TCR |= (    1 << CE ) ;
		break;
	case 2:
		audio_flag = 2;
		T0TCR |= (    1 << CE ) ;
		break;
	case 3:
		audio_flag = 3;
		T0TCR |= (    1 << CE ) ;
		break;

	default:
		break;

	}
}
