
#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

//------------------------------RECEPCION---------------------------
unsigned char buf_rx1[TAM_BUF_RX];
int in_rx1, out_rx1;

extern int est_dato;
extern unsigned char num_tarjeta[];


void Push1_Rx(unsigned char dato)
{
	buf_rx1[in_rx1]=dato;
	in_rx1++;
	in_rx1 %= TAM_BUF_RX;

}


int Pop1_Rx(void)
{
	int aux=-1;
   if(out_rx1 != in_rx1)
   {
	   aux = buf_rx1[out_rx1];
	   out_rx1++;
	   out_rx1 %= TAM_BUF_RX;

   }
   return aux;

}

void Get_Mensaje1( void )
{
   	int dato=0;
   	static unsigned int i=0;

 	static char estado = HEADER;

   	dato=Pop1_Rx();// Llego un dato por puerto serie?:

   	if(dato != -1)
   	{

   	switch(estado)
   		{
   			case HEADER:
   				 if(dato == 0x02)
   				 {
   					estado=COMANDO;
   					i=0;
   					est_dato=0;
   				 }


   				 break;
   			case COMANDO:
   						if(dato != 0x03)
   							{

   								num_tarjeta[i]=dato;
   								i++;
   								if(i >= 12)
   								{
   									estado=ESPERANDO_ETX;
   								}

   							}
   						break;

   			case ESPERANDO_ETX:
   						if (dato != 0x03)
   						{
   							estado=HEADER;

   						}

   						else
   						{
   							estado= HEADER;
   							est_dato=1;
   							SetPIN(RGBB,ON);
   						}

   						break;




   				}

   			}

}

