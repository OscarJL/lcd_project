/*
 * display_project.c
 *
 * Created: 2015-08-31 20:51:04
 *  Author: Oscar
 */ 
#define F_CPU (8000000UL)

#include <avr/io.h>
#include <util/delay.h>
#include "hd44780.h"


int main(void)
{
	
	DDRD = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	
	lcd_init();
	lcd_clrscr();
	lcd_puts("Hello World");
	
	
    while(1)
    {
        _delay_ms(50);
		PORTD += 1;
    }
}