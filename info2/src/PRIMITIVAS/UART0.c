/*
 * UART0.c
 *
 *  Created on: 21/8/2016
 *      Author: Usuario
 */
#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

unsigned char buf_rx0[TAM_BUF_RX];
unsigned char buf_tx0[TAM_BUF_TX];

int in_rx0, out_rx0;
int in_tx0, out_tx0;

extern int est_tarjeta;
extern int TxStart;

//---------------------RECEPCION-----------------

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
   				if(dato == 'K')
   				{
   					est_tarjeta=1;

   					estado= HEADER;
   				}

   				if(dato == 'N')
   				 {
   				   	est_tarjeta=2;

   				   	estado= HEADER;
   				 }


   				if(dato=='Q')
   				{
   					est_tarjeta=3;
   					estado=HEADER;
   				}

   				break;
   			default:
   				estado= HEADER;
   				break;



   		}
   	}
}


//----------------------------TRANSMICION----------------


void MandarDato(unsigned char *msg, uint32_t tam)
{
	int i=0;

	push_TX0(0x02);

	for(i=0 ; i<tam ; i++)
	{
		push_TX0(msg[i]);
	}

	push_TX0(0x03);


}



void push_TX0( char dato)
{
	buf_tx0[in_tx0]=dato;
	in_tx0++;
	in_tx0 %= TAM_BUF_TX;

	if (TxStart == 0)
	{
		TxStart = 1;
		dato = pop_TX0();
		REG_SAL_TX0 = dato;
	}
}

int pop_TX0(void)
{
	int aux = -1;

	if(in_tx0 != out_tx0)
	{
		aux=buf_tx0[out_tx0];
		out_tx0++;
		out_tx0 %= TAM_BUF_TX;
	}
	return aux;
}

