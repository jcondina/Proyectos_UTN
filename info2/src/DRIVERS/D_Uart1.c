#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

void  UART1_IRQHandler(void)
{

	unsigned char temp;



	do
	{
		temp = U1IIR;

		switch((temp>>1)&(0x03))
		{
			case 2:
					UART1_Rx();
					break;

			case 1:

					break;
			case 3:
					//ERROR
					break;
			default:
					break;
		}

		if(temp&1)
			return;
	}while( 1);
}

void UART1_Rx(void)
{
	uint8_t dato = U1RBR;
	Push1_Rx(dato);
}

