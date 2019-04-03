/*
 * SENSING.c
 *
 * Created: 27/03/2019 12:32:56 p. m.
 *  Author: sgtbr_000
 */
#define F_CPU 16000000 
#include <avr/io.h>
#include <avr/delay.h>
#include "MOTORs.h"
//		   S1 |   S2    S3      S4   |S5
//        PD7 |  PD6	PD5	    PD4	 |PD3	
//		e_left|	left  middle  right  |e_right
//Los sensores mandan un nivel bajo cuando se activan, por consiguiente en el registro PIND todos los sensores apagados se visualizarían de esta forma:	 
// PIND == D7  D6	D5	D4	D3	|D2	D1	D0
//		   1   1	1	1	1	|0	0	0  ----> Los 5 bits más significativos corresponden a los sensores. D2, D1 D0 no fueron habilitados por lo tanto
//permanecerán en cero siempre


void read_sensor(void)
{	
	PORTB = PIND;
	if (PIND == 0b11011000)//el sensor central está activado, debemos avanzar en linea recta.
	{
		for (int i=0;i<=2;i=i+1)//ciclo for para dar vuelta pronunciada.
		{
			
			motor_right(MOTOR_FORWARD,50);
			motor_left(MOTOR_FORWARD,50);
		}
	}
			
	if (PIND == 0b11101000)//el sensor derecho está activado, debemos girar a la derecha, y para ello, el motor izquierdo avanza y el derecho retrocede.
	{
		motor_left(MOTOR_FORWARD,70);
		motor_right(MOTOR_BACKWARD,20);
	}
	
	if (PIND == 0b10111000)//el sensor izquierdo está activado, debemos girar a la izquierda y para ello el motor derecho avanza y el izquierdo retrocede.
	{
		motor_right(MOTOR_FORWARD,70);
		motor_left(MOTOR_BACKWARD,20);
	}
	
	if (PIND == 0b00111000)//sensores del hemisferio izquierdo on, debe de haber una curva de 90 grados, hay que dar una vuelta brusca a la izquierda. 
	{
		for (int b=0;b<=500;b=b+1)//el ciclo for se asegura de que los motores frenen por mayor tiempo y el robot pueda maniobrar mejor después.
		{
			motor_right(MOTOR_STOP,0);
			motor_left(MOTOR_STOP,0);
		}
		for (int i=0;i<=1250;i=i+1)//este ciclo for se asegura que el robot se ocupe un mayor tiempo en dar la vuelta brusca.
		{	
			
			motor_right(MOTOR_FORWARD,255);
			motor_left(MOTOR_BACKWARD,255);
		}
		motor_right(MOTOR_FORWARD,255);
		motor_left(MOTOR_BACKWARD,255);
		
	}
	
	if (PIND == 0b00011000)//sensores del hemisferio izquierdo y el sensor central estan encendidos, debe de seguir existiendo una curva de 90 grados
	{
		for (int b=0;b<=500;b=b+1)//el ciclo for se asegura de que los motores frenen por mayor tiempo y el robot pueda maniobrar mejor después.
		{
			motor_right(MOTOR_STOP,0);
			motor_left(MOTOR_STOP,0);
		}
		for (int i=0;i<=1250;i=i+1)//este ciclo for se asegura que el robot se ocupe un mayor tiempo en dar la vuelta brusca.
		{
			
			motor_right(MOTOR_FORWARD,255);
			motor_left(MOTOR_BACKWARD,255);
		}
		motor_right(MOTOR_FORWARD,255);
		motor_left(MOTOR_BACKWARD,255);
		
	}
	
	if (PIND == 0b00001000)//sensores del hemisferio izquierdo, central y un sensor derecho están encendidos, debe de seguir existiendo una curva de 90gra
	{
		for (int b=0;b<=500;b=b+1)//el ciclo for se asegura de que los motores frenen por mayor tiempo y el robot pueda maniobrar mejor después.
		{
			motor_right(MOTOR_STOP,0);
			motor_left(MOTOR_STOP,0);
		}
		for (int i=0;i<=1250;i=i+1)//este ciclo for se asegura que el robot se ocupe un mayor tiempo en dar la vuelta brusca.
		{
			
			motor_right(MOTOR_FORWARD,255);
			motor_left(MOTOR_BACKWARD,255);
		}
		motor_right(MOTOR_FORWARD,255);
		motor_left(MOTOR_BACKWARD,255);	
	}
	
	if (PIND == 0b01011000)//sensor del extremo izquierdo y central on, debe de existir una curva a menos de 45grados, la vuelta debe ser muy cerrada
	{
		for (int b=0;b<=500;b=b+1)//el ciclo for se asegura de que los motores frenen por mayor tiempo y el robot pueda maniobrar mejor después.
		{
			motor_right(MOTOR_STOP,0);
			motor_left(MOTOR_STOP,0);
		}
		for (int i=0;i<=1250;i=i+1)//este ciclo for se asegura que el robot se ocupe un mayor tiempo en dar la vuelta brusca.
		{
			
			motor_right(MOTOR_FORWARD,255);
			motor_left(MOTOR_BACKWARD,255);
		}
		for (int i=0;i<=1000;i=i+1)//este ciclo for se asegura que el robot se ocupe un mayor tiempo en dar la vuelta brusca.
		{
			
			motor_right(MOTOR_FORWARD,255);
			motor_left(MOTOR_BACKWARD,255);
		}
		
	}
	
	if (PIND == 0b11100000)//sensores del hemisferio derecho on, debe de haber una curva de 90 grados, hay que dar una vuelta brusca a la derecha.
	{
		for (int a=0;a<=500;a=a+1)//ciclo for para frenar y maniobrar mejor después.
		{
			motor_right(MOTOR_STOP,0);
			motor_left(MOTOR_STOP,0);
		}
		
		for (int j=0;j<=1250;j=j+1)//ciclo for para dar una vuelta brusca.
		{
			
			motor_left(MOTOR_FORWARD,255);
			motor_right(MOTOR_BACKWARD,255);
		}
		motor_left(MOTOR_FORWARD,255);
		motor_right(MOTOR_BACKWARD,255);
	}
	
	if (PIND == 0b11000000)//sensores del hemisferio derecho y central on, debe seguir existiendo una curva de 90 grados
	{
		for (int a=0;a<=500;a=a+1)//ciclo for para frenar y maniobrar mejor después.
		{
			motor_right(MOTOR_STOP,0);
			motor_left(MOTOR_STOP,0);
		}
		
		for (int j=0;j<=1250;j=j+1)//ciclo for para dar una vuelta brusca.
		{
			
			motor_left(MOTOR_FORWARD,255);
			motor_right(MOTOR_BACKWARD,255);
		}
		motor_left(MOTOR_FORWARD,255);
		motor_right(MOTOR_BACKWARD,255);
	}
	
	if (PIND == 0b10000000)//sensores del hemisferio derecho, central y uno izquierdo on, debe seguir existiendo una curva de 90 grados
	{
		for (int a=0;a<=500;a=a+1)//ciclo for para frenar y maniobrar mejor después.
		{
			motor_right(MOTOR_STOP,0);
			motor_left(MOTOR_STOP,0);
		}
		
		for (int j=0;j<=1250;j=j+1)//ciclo for para dar una vuelta brusca.
		{
			
			motor_left(MOTOR_FORWARD,255);
			motor_right(MOTOR_BACKWARD,255);
		}
		motor_left(MOTOR_FORWARD,255);
		motor_right(MOTOR_BACKWARD,255);
	}
	
	if (PIND == 0b11010000)//sensor del extremo derecho y central on, debe de haber una curva menor a 45grados, vuelta cerrada a la derecha
	{
		for (int a=0;a<=500;a=a+1)//ciclo for para frenar y maniobrar mejor después.
		{
			motor_right(MOTOR_STOP,0);
			motor_left(MOTOR_STOP,0);
		}
		
		for (int j=0;j<=1250;j=j+1)//ciclo for para dar una vuelta brusca.
		{
			
			motor_left(MOTOR_FORWARD,255);
			motor_right(MOTOR_BACKWARD,255);
		}
		for (int j=0;j<=1000;j=j+1)//ciclo for para dar una vuelta brusca.
		{
			
			motor_left(MOTOR_FORWARD,255);
			motor_right(MOTOR_BACKWARD,255);
		}
	}
	
	if (PIND == 0b01111000)//sensor del extremo izquierdo on, debemos dar una vuelta pronunciada a la izquierda.
	{
			for (int i=0;i<=2;i=i+1)//ciclo for para dar vuelta pronunciada.
			{
				
				motor_right(MOTOR_FORWARD,255);
				motor_left(MOTOR_BACKWARD,255);
			}
	}
	
	if (PIND == 0b11110000)//sensor del extremo derecho on, debemos dar una vuelta pronunciada a la derecha.
	{
			for (int j=0;j<=2;j=j+1)//ciclo for para vuelta pronunciada.
			{
				
				motor_left(MOTOR_FORWARD,255);
				motor_right(MOTOR_BACKWARD,255);
			}
	}
	
	if (PIND == 0b00100000)//todos los sensores están activados, hemos terminado el circuito.
	{
		motor_left(MOTOR_STOP,0);
		motor_right(MOTOR_STOP,0);
	}else{							//Si ninguno de los casos anteriores se diera, hay que seguir avanzando en línea recta y ver con qué nos encontramos.
			for (int i=0;i<=2;i=i+1)//ciclo for para dar vuelta pronunciada.
			{
				
				motor_right(MOTOR_FORWARD,50);
				motor_left(MOTOR_FORWARD,50);
			}
			}
}