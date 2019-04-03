/*
 * sensores.c
 *
 * Created: 27/03/2019 12:21:07 p. m.
 * Author : sgtbr_000
 */ 

#include <avr/io.h>
#include "MOTORs.h"
#include "PORTs.h"
#include "SENSING.h"

int main(void)
{
	init_ports();
	init_timer1();
    /* Replace with your application code */
    while (1) 
    {
		read_sensor();
    }
}

