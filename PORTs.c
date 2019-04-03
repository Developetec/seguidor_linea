#include <avr/io.h>

/****************************************
* Definición de los recursos Atmega328
*****************************************/


void init_ports(void)
{
	/*****************************************************************
	* Definición de puertos hacia el puente H y de éste a los motores
	******************************************************************
	* MPU		H BRIDGE
	* --------------
	* PB0		IN1 -
	* PB1		ENA	 |--> RIGHT MOTOR
	* PB4		IN2 -
	* --------------
	* PB2		ENB -
	* PC0		IN3	 |--> LEFT MOTOR
	* PC1		IN4 -
	* --------------
	*/
	//Salidas para PWM
	DDRB |= (1<<PB1); //OC1A Control de velocidad para motor Derecho
	DDRB |= (1<<PB2); //OC1B Control de velocidad para motor izquierdo
	
	//Salidas para dirección
	DDRB |= (1 << PB0); //Control de avance motor derecho
	DDRB |= (1 << PB4); //Control de reversa motor derecho
	DDRC |= (1 << PC0); //Control de avanza motor izquierdo
	DDRC |= (1 << PC1); //Control de reversa motor izquierdo
	DDRB |=(1<<PORTB5); //Led de sensado
	
	//Puertos de entrada para los Sensores (solo 3)

	DDRD = 0x07;	//Habilita PD3-PD7 como entradas
	//PORTD |= 0x07;      //Activa su resistencia PULL-UP para cada una de las entradas establecidas (Sensores)
}