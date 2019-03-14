/*
 * GPIO.c
 *
 *  Created on: 7/8/2016
 *      Author: Usuario
 */
#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

void SetPINSEL( uint8_t port , uint8_t pin ,uint8_t sel )
{
	port = port * 2 + pin / 16;
	pin = ( pin % 16 ) * 2;
	PINSEL[ port ] = PINSEL[ port ] & ( ~ ( 3 << pin ) );
	PINSEL[ port ] = PINSEL[ port ] | ( sel << pin );
}


void SetPINMODE( uint8_t port , uint8_t pin ,uint8_t modo)
{
	port = port * 2 + pin / 16;
	pin = ( pin % 16 ) * 2;
	PINMODE[ port ] = PINMODE[ port ] & ( ~ ( 3 << pin ) );
	PINMODE[ port ] = PINMODE[ port ] | ( modo << pin );
}


void SetDIR(  uint8_t port  ,  uint8_t pin  ,  uint8_t dir  )
{
	port = port * 8;

	GPIO[ port ] = GPIO[ port ] & ( ~ (  1 << pin  ) );
	GPIO[ port ] = GPIO[ port ] | (  dir << pin  );
}

void SetPIN( uint8_t port , uint8_t pin , uint8_t estado )
{
	port = port * 8 + 5;

	GPIO[ port ] = GPIO[ port ] & ( ~ ( 1 << pin ) );
	GPIO[ port ] = GPIO[ port ] | ( estado << pin );
}


uint8_t GetPIN( uint8_t port , uint8_t pin , uint8_t actividad )
{
	port = port * 8 + 5;

	return ( ( ( GPIO[ port ] >> pin ) & 1 ) == actividad ) ? 1 : 0;

}
