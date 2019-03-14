/*
 * FuncionesUart0.c
 *
 *  Created on: 7/11/2015
 *      Author: Juli f
 */


#include "../HEADERS/Aplicacion.h"

#define FLAG_TX0     U0LSR & 0x20
#define REG_SAL_TX0  U0THR

extern uint8_t TxStart;
unsigned char buf_rx0[TAM_BUF_RX],  buf_tx0[TAM_BUF_TX];
int out_tx0 = 0, in_tx0 = 0, in_rx0 = 0, out_rx0 = 0;
extern unsigned char num_tarjeta[];
extern int est_tarjeta;

//------------------------------RECEPCION---------------------------//

void Push0_Rx(uint8_t dato)
{
	buf_rx0[in_rx0]=dato;
	in_rx0++;
	in_rx0 %= TAM_BUF_RX;
}

int Pop0_Rx(void)
{
	int aux=-1;
	if(out_rx0 != in_rx0)
	{
		aux = buf_rx0[out_rx0];
		out_rx0++;
		out_rx0 %= TAM_BUF_RX;
	}
	return aux;
}

void Get_Mensaje0( void )
{
   	int dato;
 	static char estado = HEADER;

   	dato=Pop0_Rx();// Llego un dato por puerto serie?:

   	if(dato != -1)
   	{
   		switch(estado)
   		{
   			case HEADER:
   				if(dato == 0x02)
   				{
   					estado= COMANDO;
   				}
   				break;

   			case COMANDO:
   				if(dato == 'K')
   				{
   					est_tarjeta=1;

   					estado= HEADER;
   				}

   				if(dato == 'N')
   				 {
   				   	est_tarjeta=0;

   				   	estado= HEADER;
   				 }
   				break;
   			default:
   				estado= HEADER;
   				break;
   		}
   	}
}

//-----------------------------TRANSMISION---------------------------//

void MandarDato( unsigned char *msg )
{
	int i;

	push_TX0(STX);

	for ( i = 0 ; msg[i] < 12 ; i ++ )
	{
		push_TX0( msg[i]);
	}

	push_TX0(ETX);
}

void push_TX0(unsigned char dato)
{
	buf_tx0 [in_tx0] = dato;
	in_tx0++;
	in_tx0 %= TAM_BUF_TX;
	if (TxStart==0) // Si esta vacio el THR incio transmisión
		  {
			TxStart=1;
			dato=pop_TX0();
			REG_SAL_TX0 = dato; // REGISTRO DE SALIDA
		  }
}

int pop_TX0(void)
{
	int aux=-1;
	if(in_tx0 != out_tx0)
	{
		aux=buf_tx0[out_tx0];
		out_tx0++;
		out_tx0 %=TAM_BUF_TX;
	}
	return aux;
}
