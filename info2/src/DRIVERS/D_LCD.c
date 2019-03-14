/*
 * D_LCD.c
 *
 *  Created on: 6/9/2016
 *      Author: Usuario
 */

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"



int i;
void LCD_write(uint8_t control, uint8_t dato)
{
	SetPIN(LCD_RST,control);
	SetPIN(LCD_ENB,1);


	SetPIN(LCD_D7,dato&(1<<7));
	SetPIN(LCD_D6,dato&(1<<6));
	SetPIN(LCD_D5,dato&(1<<5));
	SetPIN(LCD_D4,dato&(1<<4));

	//demora
	for(i=0; i<=999;i++);
	SetPIN(LCD_ENB,0);
	for(i=0; i<=999;i++);



	//demora
	SetPIN(LCD_ENB,1);


	SetPIN(LCD_D7,dato&(1<<3));
	SetPIN(LCD_D6,dato&(1<<2));
	SetPIN(LCD_D5,dato&(1<<1));
	SetPIN(LCD_D4,dato&1);

	//demora
	for(i=0; i<=9999;i++);
	SetPIN(LCD_ENB,0);


}

void LCD_write_Init(uint8_t control, uint8_t dato)
{
	SetPIN(LCD_RST,control);
	SetPIN(LCD_ENB,1);

	SetPIN(LCD_D7,dato&(1<<3));
	SetPIN(LCD_D6,dato&(1<<2));
	SetPIN(LCD_D5,dato&(1<<1));
	SetPIN(LCD_D4,dato&1);

	//demora
	for(i=0; i<=9999;i++);
	SetPIN(LCD_ENB,0);
}

void Demora(uint32_t tiempo)
{
	uint32_t i;

	for(i = 0 ; i < tiempo ; i++);
}


void LCD_ESCRIBIR_TEXTO ( uint8_t direccion, uint8_t *texto)
{
	int i;
	LCD_write( 0 , direccion | (1<<7) );

	for( i=0 ;texto [i] !='\0' ; i++)
	{
		LCD_write(1,texto[i]);
	}

}
