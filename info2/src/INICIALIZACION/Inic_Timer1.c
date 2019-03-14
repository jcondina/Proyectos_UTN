/*
 * Inic_Timer1.c
 *
 *  Created on: 25/10/2016
 *      Author: Usuario
 */



#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

void Inic_Timer1(void)
{
	PCONP |= 1 << 2 ;
	PCLKSEL0 |= 0 << 4 ;

	T1MR0 = 0x2faf080;//valor para el match


	T1MCR  = ( ( 1 << MR0I ) | ( 1 << MR0R ) | ( 0 << MR0S ) ) ;//interrumpe y resetea.

	T1TCR &= ( ~( 1 << CE ) ) ;
	T1TCR |= (    1 << CR ) ;

	T1TCR &= ( ~( 1 << CR ) ) ;
	//T1TCR |= (    1 << CE ) ;


	ISER0 |= ( 1 << 2 ) ;
}
