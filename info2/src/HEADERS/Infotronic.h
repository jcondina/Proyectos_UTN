#ifndef INFOTRONIC_H_
#define INFOTRONIC_H_

#define		__R					volatile const
#define		__W					volatile
#define		__RW				volatile

typedef 	unsigned int 		uint32_t;
typedef 	unsigned short 		uint16_t;
typedef 	unsigned char 		uint8_t;


#define 		TRUE 			1
#define 		FALSE 			0

#define		ENTRADA				0
#define		SALIDA				1

#define		BAJO				0
#define		ALTO				1


#define 	HEADER 			    0
#define 	COMANDO     		1
#define		ESPERANDO_ETX		2

#define		ON					1
#define		OFF					0
#define		BLINK				2

#define		TX1					PORT0,15
#define		RX1					PORT0,16

#define		TX0					PORT0,2
#define		RX0					PORT0,3
#define 	REG_SAL_TX0			U0THR

#define		CONFIRMADO			60000

#define 	TAM_BUF_RX			20
#define 	TAM_BUF_TX			20

#define		UART0				0
#define		UART1				1

#define 	PinSensor			PORT0,4
#define 	CiclosMax			400

//Entradas digitales:
	#define		IN0			PORT2,8	 //Sensor 1
	#define		IN1			PORT2,12 //Sensor 2
	#define		IN2 		PORT2,7 //finales de carrera
	#define		IN3			PORT1,29
//Salidas digitales:
	#define     OUT0       	PORT3,26 //Abrir barrera
	#define		OUT1		PORT1,25 // Cerrar barrera

//Led RGB:
	#define		RGBR		PORT2,2			//GPIO2
	#define		RGBG		PORT2,3			//GPIO2
	#define		RGBB		PORT2,1			//GPIO2

//RELAY:
	#define		RLY2		PORT2,0 		//GPIO2 (LED1)
	#define		RLY1		PORT0,21		//GPIO0 (LED2)
	#define		RLY4		PORT0,23		//GPIO0 (LED3)
	#define		RLY3		PORT0,27		//GPIO0 (LED4)
//SW :
	#define 	SW1			PORT2,10
	#define 	SW2			PORT0,18
	#define 	SW3			PORT0,11
	#define 	SW4			PORT2,13
	#define 	SW5			PORT1,26
//Entradas analógicas:
#define		EA0			1,31		// PRESET P1
#define		EA1			0,24		// NTC
#define		EA2			0,25		// BORNERA BR9


//salida analogica:
#define 	DAC			0,26

#define		CLK					PORT0,6 //hay timer2 en ese pin
#define		DATA				PORT0,7 // hacer esto dentro de timer2 int
#define		RETORNO				PORT0,8 // cada pin tiene interrup buscar para este y configurar

#define		D0					PORT2,0 // cargar los datos en el puerto durant int de timer2
#define		D1					PORT2,1
#define		D2					PORT2,2
#define		D3					PORT2,3
#define		D4					PORT2,4
#define		D5					PORT2,5
#define		D6					PORT2,6

//LCD:
#define		LCD_RST				PORT2,6
#define		LCD_ENB				PORT0,4
#define		LCD_D4				PORT0,5
#define		LCD_D5				PORT0,10
#define		LCD_D6				PORT2,4
#define		LCD_D7				PORT2,5

#define		NVIC_EINT1			19

//--------------------------------- PROTOTIPOS----------------------------------------------------------

//......Inicializaciones.....
void Inicializacion (void);
void Inic_SysTick(uint32_t);
void Inic_UART0(void);
void Inic_UART1(void);
void Inic_GPIOs(void);
void InitDisplay(void);
void Inic_Timer0(void);
void Inic_Timer1(void);
void Inic_LCD(void);
void Inic_ADC(void);
void Inic_DAC(void);
void Inic_EINT1(void);

//....... UART0......
void UART0_Rx(void);
void Push0_Rx(unsigned char);
int Pop0_Rx(void);



int pop_TX0(void);
void push_TX0( char);
void UART0_Tx(void);

void MandarDato ( unsigned char *, uint32_t);

void Get_Mensaje0(void);

//....UART1.....
void UART1_Rx(void);
void Push1_Rx(unsigned char);
int Pop1_Rx(void);
void Get_Mensaje1(void);

int pop_TX1(void);
void push_TX1(unsigned char);

//......ADC.....
void ADC_promedio(uint32_t);


//......LCD......

void LCD_write(uint8_t , uint8_t );
void LCD_ESCRIBIR_TEXTO ( uint8_t , uint8_t * );
void LCD_write_Init(uint8_t, uint8_t);


//....RESTO......
void AbrirBarrera(void);
void CerrarBarrera(void);
void maq_principal(void);
void maq_LUZ(void);
void maq_audio(int);
void ent_S1_antirebote(void);
void ent_S2_antirebote(void);
void ent_FC_antirebote(void);
void ent_FC2_antirebote(void);

#endif /* INFOTRONIC_H_ */
