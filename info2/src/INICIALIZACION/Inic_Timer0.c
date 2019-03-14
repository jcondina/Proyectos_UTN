/*
 * Inic_Timer0.c
 *
 *  Created on: 7/8/2016
 *      Author: Usuario
 */


#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"
void Inic_Timer0(void)
{
	PCONP |= 1 << 1 ;
	PCLKSEL0 |= 0 << 2 ;

	T0MR0 = 3125;//valor para el match


	T0MCR  = ( ( 1 << MR0I ) | ( 1 << MR0R ) | ( 0 << MR0S ) ) ;//interrumpe y resetea.

	T0TCR &= ( ~( 1 << CE ) ) ;
	T0TCR |= (    1 << CR ) ;

	T0TCR &= ( ~( 1 << CR ) ) ;
	//T0TCR |= (    1 << CE ) ;


	ISER0 |= ( 1 << NVIC_TIMER0 ) ;
}
