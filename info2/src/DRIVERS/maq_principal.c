/*
 * maq_principal.c
 *
 *  Created on: 25/10/2016
 *      Author: Usuario
 */


#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

extern uint8_t est_valido_S2;
extern uint8_t est_valido_S1;

extern int est_tarjeta;
extern int est_dato;
extern unsigned char num_tarjeta [12];

extern uint8_t estado_principal;

enum{E_INICIAL,E_ITARJETA,E_VERIFPC,E_OPENBARRERA,E_AUTOMEDIO,E_AUTOENTRANDO,E_AUTOSALIENDO};

long int demora;
uint8_t vector[]="IN";
uint8_t vector1[]="OU";
void maq_principal(void)
{
	static int enable_audio=1;

	switch(estado_principal)
	{
		case E_INICIAL:
			SetPIN(RGBB,OFF);
			SetPIN(RGBG,ON);

			if(((est_valido_S1==OFF))||(est_valido_S2==ON))//Pregunto si hay auto
			{
				est_tarjeta=0;
				estado_principal=E_ITARJETA;
			}

			if(est_dato==1)//pregunto si se ingreso una tarjeta
			{
				MandarDato(num_tarjeta,12);//mando el numero de tarjeta al programa visual para regitrar un nuevo ususario
				est_dato=0;
				SetPIN(RGBG,OFF);
			}

			break;


		case E_ITARJETA:
			if(enable_audio==1)//Por favor ingrese la tarjeta
			{

				maq_audio(0);
				enable_audio=0;
			}

			SetPIN(RGBG,OFF);

			if((est_valido_S1==ON)&&(est_valido_S2==OFF))//si el auto se retira vuelvo al estado esperando auto(estado inicial)
			{
				estado_principal=E_INICIAL;
				enable_audio=1;
			}


			if(est_dato==1)//si se ingreso una tarjeta la mando al programa visual  y paso al estado donde espero la confirmacion
			{

				MandarDato(num_tarjeta,12);
				enable_audio=1;
				est_dato=0;
				SetPIN(RGBB,OFF);
				estado_principal=E_VERIFPC;

			}
			break;

		case E_VERIFPC:
			if(est_tarjeta == 2) // tarjeta falsa vuelvo al estado inicial
			{
				est_tarjeta=0;
				if(enable_audio==1)
				{
					maq_audio(2);//tarjeta invalida

					for(demora=0;demora<=10000000;demora ++);
					for(demora=0;demora<=10000000;demora ++);
					enable_audio=1;
				}


				estado_principal=E_INICIAL;

			}

			if(est_tarjeta == TRUE) //tarjeta valida paso a abrir barrera
			{
				estado_principal=E_OPENBARRERA;
				est_tarjeta=0;

				//Chau
				if((est_valido_S1==OFF))//consulto si esta del lado de afuera
				{

					maq_audio(3);
					 AbrirBarrera();

				}
				//Bienvenido
				if(est_valido_S2==ON)//consulto si esta del lado de adentro
				{
					maq_audio(1);
					AbrirBarrera();
				}
			}
			break;

		case E_OPENBARRERA:
			if((est_valido_S1==OFF)&&(est_valido_S2==ON))//consulto posicion del auto en esta caso me fijo si esta en el medio(cortando ambos sensores)
			{
				estado_principal=E_AUTOMEDIO;
			}
			if((est_valido_S1==ON)&&(est_valido_S2==OFF))//consulto si el auto se arrepintio y se fue
			{
				estado_principal=E_INICIAL;
				 CerrarBarrera();
			}
			break;

		case E_AUTOMEDIO:
			if((est_valido_S1==ON)&&(est_valido_S2==ON))//consulto si el auto salio
			{
				estado_principal=E_AUTOSALIENDO;
				MandarDato(vector1,2);
			}
			if((est_valido_S1==OFF)&&(est_valido_S2==OFF))//consulto si el auto entro
			{
				estado_principal=E_AUTOENTRANDO;
				MandarDato(vector,2);
			}
			break;

		case E_AUTOENTRANDO:
			if((est_valido_S1==OFF)&&(est_valido_S2==ON))//me fijo si el auto se arrepintio y volvio a cortar ambos sensores
			{
				estado_principal=E_AUTOMEDIO;
			}
			if((est_valido_S1==ON)&&(est_valido_S2==OFF))//me fijo si el auto ya entro
			{
				CerrarBarrera();

				estado_principal=E_INICIAL;

			}
			break;

		case E_AUTOSALIENDO:
			if((est_valido_S1==OFF)&&(est_valido_S2==ON))//me fijo si el auto se arrepintio y volvio a cortar ambos sensores
			{
				estado_principal=E_AUTOMEDIO;
			}
			if((est_valido_S1==ON)&&(est_valido_S2==OFF))//me fijo si el auto ya entro
			{
				estado_principal=E_INICIAL;
				CerrarBarrera();

			}
			break;

		default:
			break;


	}

}
