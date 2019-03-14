
#ifndef LPC1769_H_
#define LPC1769_H_

typedef 	__RW uint32_t 		registro_t;

#define		PORT0				0
#define		PORT1				1
#define		PORT2				2
#define		PORT3				3
#define		PORT4				4

	//!< GPIO - PORT0
	/*	*						*
		*************************
		*		FIODIR			*	0x2009C000
		*************************
		*		RESERVED		*	0x2009C004
		*************************
		*		RESERVED		*	0x2009C008
		*************************
		*		RESERVED		*	0x2009C00C
		*************************
		*		FIOMASK			*	0x2009C010
		*************************
		*		FIOPIN			*	0x2009C014
		*************************
		*		FIOSET			*	0x2009C018
		*************************
		*		FIOCLR			*	0x2009C01C
		*************************
		*						*
		*						*
	*/
#define			GPIO				( ( __RW uint32_t * ) 0x2009C000UL )

//!< ////////////////Registros PINSEL//////////////////////////////
//!< 00	GPIO (reset value)		01	funcion 1
//!< 11	funcion 3				10	funcion 2
#define			PINSEL				( ( __RW uint32_t * ) 0x4002C000UL )

//!< //////////////////Registros PINMODE ///////////////////////////
#define			PINMODE				( ( __RW uint32_t * ) 0x4002C040UL )

#define			PINMODE0			PINMODE[0]
#define			PINMODE1			PINMODE[1]
#define			PINMODE2			PINMODE[2]
#define			PINMODE3			PINMODE[3]
#define			PINMODE4			PINMODE[4]
#define			PINMODE5			PINMODE[5]		//!< not used
#define			PINMODE6			PINMODE[6]		//!< not used
#define			PINMODE7			PINMODE[7]
#define			PINMODE8			PINMODE[8]		//!< not used
#define			PINMODE9			PINMODE[9]

#define			PINMODE_PULLUP 		0
#define			PINMODE_REPEAT 		1
#define			PINMODE_NONE 		2
#define			PINMODE_PULLDOWN 	3

#define			PINMODE_OD			( ( __RW uint32_t * ) 0x4002C040UL )

#define			PINMODE_OD0			PINMODE_OD[0]
#define			PINMODE_OD1			PINMODE_OD[1]
#define			PINMODE_OD2			PINMODE_OD[2]
#define			PINMODE_OD3			PINMODE_OD[3]
#define			PINMODE_OD4			PINMODE_OD[4]

#define			GPIO				( ( __RW uint32_t * ) 0x2009C000UL )

#define			FIO0DIR				GPIO[0]
#define			FIO0MASK			GPIO[4]
#define			FIO0PIN				GPIO[5]
#define			FIO0SET				GPIO[6]
#define			FIO0CLR				GPIO[7]
#define			FIO1DIR				GPIO[8]
#define			FIO1MASK			GPIO[12]
#define			FIO1PIN				GPIO[13]
#define			FIO1SET				GPIO[14]
#define			FIO1CLR				GPIO[15]
#define			FIO2DIR				GPIO[16]
#define			FIO2MASK			GPIO[20]
#define			FIO2PIN				GPIO[21]
#define			FIO2SET				GPIO[22]
#define			FIO2CLR				GPIO[23]
#define			FIO3DIR				GPIO[24]
#define			FIO3MASK			GPIO[28]
#define			FIO3PIN				GPIO[29]
#define			FIO3SET				GPIO[30]
#define			FIO3CLR				GPIO[31]
#define			FIO4DIR				GPIO[32]
#define			FIO4MASK			GPIO[36]
#define			FIO4PIN				GPIO[37]
#define			FIO4SET				GPIO[39]
#define			FIO4CLR				GPIO[39]


typedef struct
{
	 __RW uint32_t 	FIODIR ;
		  uint32_t 	RESERVED[3];
	 __RW uint32_t 	FIOMASK	;
	 __RW uint32_t 	FIOPIN;
	 __RW uint32_t 	FIOSET;
	 __RW uint32_t 	FIOCLR;

} gpio_t;




//!< ----------- Estados de PINMODE
//!< 00	Pull Up resistor enable (reset value)		01	repeated mode enable
//!< 11	Pull Down resistor enable					10	ni Pull Up ni Pull DOwn
#define			PINMODE_PULLUP 		0
#define			PINMODE_REPEAT 		1
#define			PINMODE_NONE 		2
#define			PINMODE_PULLDOWN 	3

//!< ///////////////////   PCONP   //////////////////////////
//!<  Power Control for Peripherals register (PCONP - 0x400F C0C4) [pag. 62 user manual LPC1769]
//!< 0x400FC0C4UL : Direccion de inicio del registro de habilitación de dispositivos:
#define 		PCONP				(* ( ( __RW uint32_t  * ) 0x400FC0C4UL ))


//!< ///////////////////   PCLKSEL   //////////////////////////
//!< Peripheral Clock Selection registers 0 and 1 (PCLKSEL0 -0x400F C1A8 and PCLKSEL1 - 0x400F C1AC) [pag. 56 user manual]
//!< 0x400FC1A8UL : Direccion de inicio de los registros de seleccion de los CLKs de los dispositivos:
#define		PCLKSEL		( ( __RW uint32_t  * ) 0x400FC1A8UL )
//!< Registros PCLKSEL
#define		PCLKSEL0	PCLKSEL[0]
#define		PCLKSEL1	PCLKSEL[1]

//!< /////////////		SYSTICK		///////////////////////////

/*********************************************************+
 * PEGADO
 */
// 0xE000E010UL: Registro de control del SysTick:
#define 	SYSTICK		( (registro_t *) 0xE000E010UL )

#define		STCTRL		SYSTICK[ 0 ]
	#define	ENABLE			0
	#define	TICKINT			1
	#define	CLKSOURCE		2
	#define	COUNTFLAG		16
#define		STRELOAD	SYSTICK[ 1 ]
#define		STCURR		SYSTICK[ 2 ]
#define		STCALIB		SYSTICK[ 3 ]

#define TICKINT_ON    STCTRL |= 0x00000002 // pongo en 1  el bit 1 del STCTRL Hablito   interr del Systick
#define TICKINT_OFF   STCTRL &= 0xFFFFFFFD // pongo en 0  el bit 1 del STCTRL Deshablito interr del Systick



/**************************************************************************************
 * PEGADO
 */


#define		PCADC				12
#define		PCGPDMA				29

#define		ADC					( ( __RW uint32_t  * ) 0x40034000UL )
#define		AD0CR				ADC[0]
#define		AD0GDR				ADC[1]
#define		AD0INTEN			ADC[3]
	#define		ADINTEN0			0
	#define		ADINTEN1			1
	#define		ADINTEN2			2
	#define		ADINTEN3			3
	#define		ADINTEN4			4
	#define		ADINTEN5			5
	#define		ADINTEN6			6
	#define		ADINTEN7			7
	#define		ADGINTEN			8

#define		AD0DR0				ADC[4]
#define		AD0DR1				ADC[5]
#define		AD0DR2				ADC[6]
#define		AD0DR3				ADC[7]
#define		AD0DR4				ADC[8]
#define		AD0DR5				ADC[9]
#define		AD0DR6				ADC[10]
#define		AD0DR7				ADC[11]
#define		AD0STAT				ADC[12]
#define		AD0TRM				ADC[13]
/*
//0x4008C000UL : Registro de conversion del DAC:
#define		DAC0				( ( __RW uint32_t  * ) 0x4008C000UL )

#define		DACR				DAC0[0]
#define		DACCTRL				DAC0[1]
#define		DACCNTVAL 			DAC0[2]
*/
//........PEGADO.........
//Registros del DAC:
#define		DACR		DIR_DACR[0]
#define		DACCTRL		DIR_DACCTRL[0]
#define		DACCNTVAL	DIR_DACCNTVAL[0]

//0x4008C000UL : Registro de conversion del DAC:
#define		DIR_DACR	( ( uint32_t  * ) 0x4008C000UL )
//0x4008C004UL : Registro de control del DAC:
#define		DIR_DACCTRL	( ( uint32_t  * ) 0x4008C004UL )
//0x4008C008UL : Registro de contador del DAC:
#define		DIR_DACCNTVAL ( ( uint32_t  * ) 0x4008C008UL )
//................................................

// Interrupt Set-Enable Register 0 register (ISER0 - 0xE000E100)

#define		NVIC_TIMER0		1

#define		ISER 		( ( __RW uint32_t  * ) 0xE000E100UL )
#define		ISER0		ISER[0]
#define		ISER1		ISER[1]

#define		ISE_UART0	5
#define		ISE_EINT3	21
#define		ISE_ADC		22
#define		ISE_DMA		26

// Interrupt Clear-Enable Registers
#define		ICER 		( ( __RW uint32_t  * ) 0xE000E180UL )
#define		ICER0		ICER[0]
#define		ICER1		ICER[1]

#define		ICE_UART0	( 1 <<  5 )
#define		ICE_EINT3	( 1 << 21 )
#define		ICE_ADC		( 1 << 22 )
#define		ICE_DMA		( 1 << 26 )

#define		ICPR 		( ( __RW uint32_t  *  ) 0xE000E280UL )
#define		ICPR0		ICPR[0]
#define		ICPR1		ICPR[1]

#define		ICP_UART0	5
#define		ICP_EINT3	21
#define		ICP_ADC		22
#define		ICP_DMA		26

//****************************************************  UART0  UART1 UART2 **********************************************************
//		//UART0:
//		//0x4001000CUL : Registro de control de la UART0:
//		#define		DIR_U0LCR	( ( uint32_t  * ) 0x4000C00CUL )
//		//0x40010014UL : Registro de recepcion de la UART0:
//		#define		DIR_U0LSR		( ( uint32_t  * ) 0x4000C014UL )
//		//0x40010000UL : Parte baja del divisor de la UART0:
//		#define		DIR_U0DLL	( ( uint32_t  * ) 0x4000C000UL )
//		//0x40010004UL : Parte alta del divisor de la UART0:
//		#define		DIR_U0DLM	( ( uint32_t  * ) 0x4000C004UL )
//		//0x40010000UL : Registro de recepcion de la UART0:
//		#define		DIR_U0RBR		( ( uint32_t  * ) 0x4000C000UL )
//		//0x40010000UL : Registro de transmision de la UART0:
//		#define		DIR_U0THR		( ( uint32_t  * ) 0x4000C000UL )
//		//0x4000C004UL : Registro habilitacion de interrupciones de la UART0:
//		#define		DIR_U0IER	( ( uint32_t  * ) 0x4000C004UL )
//		//0x4000C008UL : Registro de identificación de la interrupción de la UART0:
//		#define		DIR_U0IIR	( ( uint32_t  * ) 0x4000C008UL )
//		//0x4000C008UL : Registro de control de la FIFO de la UART0:
//		#define		DIR_U0FCR	( ( uint32_t  * ) 0x40000C008UL )



		//UART1:
		//0x4001000CUL : Registro de control de la UART1:
		#define		DIR_U1LCR	( ( uint32_t  * ) 0x4001000CUL )
		//0x40010014UL : Registro de recepcion de la UART1:
		#define		DIR_U1LSR		( ( uint32_t  * ) 0x40010014UL )
		//0x40010000UL : Parte baja del divisor de la UART1:
		#define		DIR_U1DLL	( ( uint32_t  * ) 0x40010000UL )
		//0x40010004UL : Parte alta del divisor de la UART1:
		#define		DIR_U1DLM	( ( uint32_t  * ) 0x40010004UL )
		//0x40010000UL : Registro de recepcion de la UART1:
		#define		DIR_U1RBR	( ( uint32_t  * ) 0x40010000UL )
		//0x40010000UL : Registro de transmision de la UART1:
		#define		DIR_U1THR	( ( uint32_t  * ) 0x40010000UL )
		//0x40010004UL : Registro habilitacion de interrupciones de la UART1:
		#define		DIR_U1IER	( ( uint32_t  * ) 0x40010004UL )
		//0x40010008UL : Registro de identificación de la interrupción de la UART1:
		#define		DIR_U1IIR	( ( uint32_t  * ) 0x40010008UL )
		//0x40010008UL : Registro de control de la FIFO de la UART1:
		#define		DIR_U1FCR	( ( uint32_t  * ) 0x40010008UL )

		//UART2:
		//0x4009800CUL : Registro de control de la UART2:
		#define		DIR_U2LCR	( ( uint32_t  * ) 0x4009800CUL )
		// 0x40098014UL : Registro de recepcion de la UART2:
		#define		DIR_U2LSR		( ( uint32_t  * ) 0x40098014UL )
		// 0x40098000UL : Parte baja del divisor de la UART2:
		#define		DIR_U2DLL	( ( uint32_t  * ) 0x40098000UL )
		// 0x40098004UL : Parte alta del divisor de la UART2:
		#define		DIR_U2DLM	( ( uint32_t  * ) 0x40098004UL )
		// 0x40098000UL : Registro de recepcion de la UART2:
		#define		DIR_U2RBR	( ( uint32_t  * ) 0x40098000UL )
		// 0x40098000UL : Registro de transmision de la UART2:
		#define		DIR_U2THR	( ( uint32_t  * ) 0x40098000UL )
		//0x40098004UL : Registro habilitacion de interrupciones de la UART2:
		#define		DIR_U2IER	( ( uint32_t  * ) 0x40098004UL )
		// 0x40098008UL : Registro de identificación de la interrupción de la UART2:
		#define		DIR_U2IIR	( ( uint32_t  * ) 0x40098008UL )
		// 0x40098008UL : Registro de control de la FIFO de la UART2:
		#define		DIR_U2FCR	( ( uint32_t  * ) 0x40098008UL )


		//0x4001004CUL : Registro de control comunicacion 485:
		#define		DIR_U1RS485CTRL		( ( uint32_t  * ) 0x4001004CUL )
		//0x40010050UL : Registro de direccion 485:
		#define		DIR_U1RS485ADRMATCH	( ( uint32_t  * ) 0x40010050UL )
		//0x40010054UL : Registro de demora entre fin de transmision y fin de RTS:
		#define		DIR_U1RS485DLY	( ( uint32_t  * ) 0x40010054UL )

//		//Registros de la UART0:
//		#define		U0THR		DIR_U0THR[0]
//		#define		U0RBR		DIR_U0RBR[0]
//		#define		U0LCR		DIR_U0LCR[0]
//		#define		U0LSR		DIR_U0LSR[0]
//		#define		U0DLL		DIR_U0DLL[0]
//		#define		U0DLM		DIR_U0DLM[0]
//		#define		U0IER		DIR_U0IER[0]
//		#define		U0IIR		DIR_U0IIR[0]
//		#define		U0FCR		DIR_U0FCR[0]
//
//		#define		U0RDR		(U0LSR&0x01)
//		#define		U0THRE		((U0LSR&0x20)>>5)

//0x40010000UL : Registro de recepcion de la UART0:
#define		DIR_UART0		( ( __RW uint32_t  * ) 0x4000C000UL )

#define		U0RBR		DIR_UART0[0]
#define		U0THR		DIR_UART0[0]
#define		U0DLL		DIR_UART0[0]
#define		U0IER		DIR_UART0[1]
#define		U0DLM		DIR_UART0[1]
#define		U0IIR		DIR_UART0[2]
#define		U0LCR		DIR_UART0[3]
#define		U0LSR		DIR_UART0[5]

		//Registros de la UART1:
		#define		U1THR		DIR_U1THR[0]
		#define		U1RBR		DIR_U1RBR[0]
		#define		U1LCR		DIR_U1LCR[0]
		#define		U1LSR		DIR_U1LSR[0]
		#define		U1DLL		DIR_U1DLL[0]
		#define		U1DLM		DIR_U1DLM[0]
		#define		U1IER		DIR_U1IER[0]
		#define		U1IIR		DIR_U1IIR[0]
		#define		U1FCR		DIR_U1FCR[0]

		#define		U1RDR		(U1LSR&0x01)
		#define		U1THRE		((U1LSR&0x20)>>5)

		//Registros de la UART2:
		#define		U2THR		DIR_U2THR[0]
		#define		U2RBR		DIR_U2RBR[0]
		#define		U2LCR		DIR_U2LCR[0]
		#define		U2LSR		DIR_U2LSR[0]
		#define		U2DLL		DIR_U2DLL[0]
		#define		U2DLM		DIR_U2DLM[0]
		#define		U2IER		DIR_U2IER[0]
		#define		U2IIR		DIR_U2IIR[0]
		#define		U2FCR		DIR_U2FCR[0]

		#define		U2RDR		(U2LSR&0x01)
		#define		U2THRE		((U2LSR&0x20)>>5)


		#define		U1RS485CTRL		DIR_U1RS485CTRL[0]
		#define		U1RS485ADRMATCH	DIR_U1RS485ADRMATCH[0]
		#define		U1RS485DLY		DIR_U1RS485DLY[0]


// Timer0 Registers

#define _T0IR ((uint32_t *) 0x40004000UL)

#define T0IR _T0IR [0]
#define T0TCR _T0IR [1]
#define T0TC _T0IR [2]
#define T0PR _T0IR [3]
#define T0PC _T0IR [4]
#define T0MCR _T0IR [5]
	#define		MR0I			0
	#define		MR0R			1
	#define		MR0S			2
	#define		MR1I			3
	#define		MR1R			4
	#define		MR1S			5
	#define		MR2I			6
	#define		MR2R			7
	#define		MR2S			8
	#define		MR3I			9
	#define		MR3R			10
	#define		MR3S			11
#define T0MR0 _T0IR [6]
#define T0MR1 _T0IR [7]
#define T0MR2 _T0IR [8]
#define T0MR3 _T0IR [9]
#define T0CCR _T0IR [10]
#define T0CR0 _T0IR [11]
#define T0CR1 _T0IR [12]
#define T0EMR _T0IR [15]
#define T0CTCR _T0IR [28]
#define		CE			0
#define		CR			1

//

#define _T1IR ((uint32_t *) 0x40008000UL)

#define T1IR _T1IR [0]
#define T1TCR _T1IR [1]
#define T1TC _T1IR [2]
#define T1PR _T1IR [3]
#define T1PC _T1IR [4]
#define T1MCR _T1IR [5]
	#define		MR0I			0
	#define		MR0R			1
	#define		MR0S			2
	#define		MR1I			3
	#define		MR1R			4
	#define		MR1S			5
	#define		MR2I			6
	#define		MR2R			7
	#define		MR2S			8
	#define		MR3I			9
	#define		MR3R			10
	#define		MR3S			11
#define T1MR0 _T1IR [6]
#define T1MR1 _T1IR [7]
#define T1MR2 _T1IR [8]
#define T1MR3 _T1IR [9]
#define T1CCR _T1IR [10]
#define T1CR0 _T1IR [11]
#define T1CR1 _T1IR [12]
#define T1EMR _T1IR [15]
#define T1CTCR _T1IR [28]

//  Interrupciones Externas  ------------------------------------------------------------------------------------------------
#define		EXTINT 		( * ( ( registro_t  * ) 0x400FC140UL ) )
	#define		EINT0		0
	#define		EINT1		1
	#define		EINT2		2
	#define		EINT3		3

#define		EXTMODE 	( * ( ( registro_t  * ) 0x400FC148UL ) )
	#define		EXTMODE0	0
	#define		EXTMODE1	1
	#define		EXTMODE2	2
	#define		EXTMODE3	3
#define		EXTPOLAR 	( * ( ( registro_t  * ) 0x400FC14CUL ) )
	#define		EXTPOLAR0	0
	#define		EXTPOLAR1	1
	#define		EXTPOLAR2	2
	#define		EXTPOLAR3	3



#endif /* LPC1769_H_ */
