/*
 * Inic_UART1.C
 *
 *  Created on: 7/8/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"


void Inic_UART1 (void)
{

	  //1.- Registro PCONP (0x400FC0C4) - bit 4 en 1 prende la UART:
		       PCONP |= 0x00000010;  //Pag 63

	//2.- Registro PCLKSEL0 (0x400FC1A8) - selecciono el clk de la UART (recordar que cclk = 100MHz)

		//2.- Registro PCLKSEL0 (0x400FC1A8) - bits 8 y 9 en 0 seleccionan que el clk de la UART1 sea 25MHz--> DIVIDE POR 4:
			        PCLKSEL0 &= ~(0x03<<8); //pAG 56

	//3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, SIN paridad, sin break cond, DLAB = 1:

			//3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
				    U1LCR =0x00000083; //pAG 326 U1LCR =0x00000083;
				    //EJERCICIO 1 U1LCR =0x0000009B EJERCICIO 2 U1LCR =0x00000087; EJERCICIO 3

	//4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004):
				//4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004) en 0xA2:
					U1DLM = 0x00;   // es el resultado de 25Mhz/(9600*16)---> 162
					U1DLL = 0xA3;	// lo cargo en ambos registros pAG 320

					 U1FCR |=(0x01);     //  habilita la FIFO de TX RX                             Pag 325

	//5.- Registros PINSEL0 (0x4002C000) y PINSEL1 (0x4002C004) - habilitan las funciones especiales de los pines:
	//TX1D : P0[15] Hay colocar un 1 en el bit 30 y un cERO en el bit 31

					SetPINSEL (TX1,FUNCION_1);



	//RX1D : P0[16]  Hay que colocar un 1 en el bit 0 y un 0 en el bit 1                         Pag 108

					SetPINSEL (RX1,FUNCION_1);


	//6. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)

					 // hay que poner el DLAB=0 para habilitar las interrupciones por TX RX;
					 U1LCR &= ~(0x01<<7);// pongo en cero el bit 7 DLAB=0                          Pag 326
					 U1IER |= 0X03 ; // bit 0 y 1 del registro U1Ier Habilia int por TX y RX       Pag 322

					 ISER0 |= (0x01<< 6);//  Habilita Interrupcion por UART1 del NVIC  Pag77



	/**************** DE ESTAR BIEN CONFIGURADO EL 232 CONFIGURO EL 485 *********************/
	//7. Configuro RS485, de estar activo:
	#ifdef RS485_MASTER
	//PINSEL PARA QUE RTS tenga la funcionalidad deseada

	//7.1. U1RS485DLY Delay entre fin de tx y fin de rts:

	//7.2. U1RS485CTRL: Control de la UART en modo 485: Modo MASTER, con Automatic Direction Control via RTS:

	//7.3. U1LCR: Line Control: 8 bits, con paridad (siempre en 1), 1 bit de stop

	#else
	#ifdef RS485_SLAVE
	//Configuro el pin RTS como un GPIO, como salida digital, que este en 0 (recepcion)

	//7.1. Direccion del dispositivo (U1RS4845ADR)

	//7.2. U1RS485CTRL: Control de la UART en modo 485: Modo SLAVE, con Automatic Address Detection:

	//7.3. U1LCR: Line Control: 8 bits, con paridad (siempre en 0), 1 bit de stop
	#endif
	#endif

}


