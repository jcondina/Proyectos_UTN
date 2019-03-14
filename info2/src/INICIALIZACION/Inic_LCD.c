/*
 * Inic_LCD.c
 *
 *  Created on: 7/8/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"
int i;

void Inic_LCD ( void )
{
	SetPINSEL(LCD_RST,FUNCION_GPIO);
	SetDIR(LCD_RST,SALIDA);
	SetPIN(LCD_RST,OFF);

	SetPINSEL(LCD_ENB,FUNCION_GPIO);
	SetDIR(LCD_ENB,SALIDA);
	SetPIN(LCD_ENB,OFF);

	SetPINSEL(LCD_D4,FUNCION_GPIO);
	SetDIR(LCD_D4,SALIDA);
	SetPIN(LCD_D4,OFF);

	SetPINSEL(LCD_D5,FUNCION_GPIO);
	SetDIR(LCD_D5,SALIDA);
	SetPIN(LCD_D5,OFF);

	SetPINSEL(LCD_D6,FUNCION_GPIO);
	SetDIR(LCD_D6,SALIDA);
	SetPIN(LCD_D6,OFF);

	SetPINSEL(LCD_D7,FUNCION_GPIO);
	SetDIR(LCD_D7,SALIDA);
	SetPIN(LCD_D7,OFF);
//configuro LCD
	LCD_write_Init(0,3);
	LCD_write_Init(0,3);
	LCD_write_Init(0,3);

//configur 4 bits 1 renglon 5x8
	LCD_write(0,0x28);
// configuro limpio display
	LCD_write(0,0x01);
//return home
	LCD_write(0,0x02);
}
