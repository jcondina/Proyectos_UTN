#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"


extern const unsigned char Ingrese_audio [25000];
extern const unsigned char Bienvenido_audio [15000];
extern const unsigned char Invalida_audio [17000];
extern const unsigned char Hastaluego_audio [15000];

extern uint8_t audio_flag;

//timer que interume a la misma frequencia que la frequencia de muestreo de los audios para luego reproducirlo por el DAC

//cada vez que interumpe chequeo con un flag que audio quiero reproducir y por cada interupcion pongo en el DAC una posicion del vector que posee los audio

void TIMER0_IRQHandler(void)
{
	static uint32_t i=0;

	if(T0IR & 1)
	{
		switch(audio_flag)
		{

		case 0://"Ingrese tarjeta"

			DACR=((Ingrese_audio[i] & 0x3FF)<<8);
			i++;
			if (i>25000)
			{
				i=0;
				T0TCR &= ( ~( 1 << CE ) ) ;
			}

			T0IR |= 1<< 0;
			break;


		case 1://"Bienvenido"
			DACR=((Bienvenido_audio[i] & 0x3FF)<<8);
			i++;
			if (i>15000)
			{
				i=0;
				T0TCR &= ( ~( 1 << CE ) ) ;
			}

			T0IR |= 1 << 0;
			break;

		case 2://"Tarjeta Invalida"
			DACR=((Invalida_audio[i] & 0x3FF)<<8);
			i++;
			if (i>17000)
			{
				i=0;
				T0TCR &= ( ~( 1 << CE ) ) ;
			}

			T0IR |= 1 << 0;
			break;



		case 3://"Hasta Luego"
			DACR=((Hastaluego_audio[i] & 0x3FF)<<8);
			i++;
			if (i>15000)
			{
				i=0;
				T0TCR &= ( ~( 1 << CE ) ) ;
			}

			T0IR |= 1 << 0;
			break;


		default:
			T0IR |= 1 << 0;
			T0TCR &= ( ~( 1 << CE ) ) ;

			break;

		}

	}
}

