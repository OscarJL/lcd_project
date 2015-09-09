/*
 * display_project.c
 *
 * Created: 2015-08-31 20:51:04
 *  Author: Oscar
 */ 
#define F_CPU (8000000UL)


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "hd44780.h"

#define SET_BIT(reg, pin) (reg |= (1 << pin))
#define CLR_BIT(reg, pin) (reg &= ~(1 << pin))

typedef struct cursor_position{
	int8_t x;
	int8_t y;
}cursor_position;

// Global variables 

cursor_position cp = {.0, .0};

ISR(PCINT0_vect)
{
	
}

void init_push_buttons()
{
	
	//Set PB0-2 to inputs with pull-up resistors enabled
	CLR_BIT(DDRB, PB0);
	CLR_BIT(DDRB, PB1);
	CLR_BIT(DDRB, PB2);
	SET_BIT(PORTB, PB0);
	SET_BIT(PORTB, PB1);
	SET_BIT(PORTB, PB2);
	//Enables interrupt for PB0-2
	SET_BIT(PCICR, PCIE0);
	SET_BIT(PCMSK0, PB0);
	SET_BIT(PCMSK0, PB1);
	SET_BIT(PCMSK0, PB2);
}



int main(void)
{
	sei();
	char itoa_buffer[12];
	
	DDRD = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	
	init_push_buttons();
	lcd_init();
	lcd_clrscr();
	lcd_command(_BV(LCD_DISPLAYMODE) | _BV(LCD_DISPLAYMODE_ON) | _BV(LCD_DISPLAYMODE_BLINK));
	itoa(PB1, itoa_buffer, 10);
	lcd_puts(itoa_buffer);
	
	
    while(1)
    {
        _delay_ms(100);
		PORTD = 0;
    }
}