#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

#include "C:\Users\Usuario\Desktop\Info2\TPO2016\src\HEADERS\Aplicacion.h"

extern uint32_t valorADC;

void SysTick_Handler(void)
{
	ADC_promedio(valorADC);
	ent_S1_antirebote();
	ent_S2_antirebote();
	ent_FC_antirebote();
	ent_FC2_antirebote();
	Get_Mensaje1();
	Get_Mensaje0();
}

