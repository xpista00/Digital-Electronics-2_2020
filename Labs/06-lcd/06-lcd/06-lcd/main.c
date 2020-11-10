  
/***********************************************************************
 * 
 * Stopwatch with LCD display output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2017-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "lcd.h"            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for conversion function


/* Function definitions ----------------------------------------------*/

uint8_t customChar[] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000, // |
	0b11000,
	0b11000,
	0b11000,
	0b11000,
	0b11000,
	0b11000,
	0b11000,
	0b11000, // ||
	0b11100,
	0b11100,
	0b11100,
	0b11100,
	0b11100,
	0b11100,
	0b11100,
	0b11100, // |||
	0b11110,
	0b11110,
	0b11110,
	0b11110,
	0b11110,
	0b11110,
	0b11110,
	0b11110, // ||||
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
};


/**
 * Main function where the program execution begins. Update stopwatch
 * value on LCD display when 8-bit Timer/Counter2 overflows.
 */
int main(void)
{
    // Initialize LCD display
    lcd_init(LCD_DISP_ON);
	
	// Char1
	
	// Set pointer to beginning of CGRAM memory
	lcd_command(1 << LCD_CGRAM);
	for (uint8_t i = 0; i < 8*6; i++)
	{
		// Store all new chars to memory line by line
		lcd_data(customChar[i]);
	}
	// Set DDRAM address
	lcd_command(1 << LCD_DDRAM);
	    
	// Display first custom character
	//lcd_putc(0);
	
	
	// Display first custom character
	/*
	lcd_gotoxy(5, 1);
	lcd_putc(1);			// 1 carka
	lcd_gotoxy(6, 1);
	lcd_putc(2);			// 2 carky 
	lcd_gotoxy(7, 1);
	lcd_putc(3);			// 3 
	lcd_gotoxy(8, 1);
	lcd_putc(4);			// 4
	lcd_gotoxy(9, 1);
	lcd_putc(0);			// prazdne
	lcd_gotoxy(10, 1);
	lcd_putc(5);			// plne
	*/
		

    // Put string(s) at LCD display
	/*
    lcd_gotoxy(1, 0);
    lcd_puts("LCD Test");
    lcd_putc('!');
	lcd_clrscr()
	*/
	
	lcd_gotoxy(1, 0);
	lcd_puts("00:00.0");
	
	lcd_gotoxy(11, 0);
	lcd_putc('a');
	
	lcd_gotoxy(1, 1);
	lcd_putc('b');
	
	lcd_gotoxy(11, 1);
	lcd_putc('c');
	

    // Configure 8-bit Timer/Counter2 for Stopwatch
    // Set prescaler and enable overflow interrupt every 16 ms
	TIM2_overflow_16384us();
	TIM2_overflow_interrupt_enable();
	
	TIM0_overflow_16384us();
	TIM0_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**
 * ISR starts when Timer/Counter2 overflows. Update the stopwatch on
 * LCD display every sixth overflow, ie approximately every 100 ms
 * (6 x 16 ms = 100 ms).
 */
ISR(TIMER2_OVF_vect)
{
    static uint8_t number_of_overflows = 0;
    static uint8_t tens = 0;        // Tenths of a second
    static uint8_t secs = 0;        // Seconds
	static uint8_t decsecs = 0;        // decimal Seconds
	static uint8_t min = 0;        // minits
	static uint8_t decmin = 0;        // decimal minits
	static uint16_t suma = 0;
	
	
    char lcd_string[2] = "  ";      // String for converting numbers by itoa()

    number_of_overflows++;
    if (number_of_overflows >= 6)
    {
        // Do this every 6 x 16 ms = 100 ms
        number_of_overflows = 0;

        // WRITE YOUR CODE HERE
		tens++;
		if(tens > 9)
		{
			tens = 0;
			secs++;
			if(secs > 9)
			{
				secs = 0;
				decsecs++;
				if(decsecs > 5)
				{	
					
					suma= 0 ;
					itoa(suma, lcd_string, 10);
					lcd_gotoxy(11,0);
					lcd_puts("    ");
					
					decsecs=0;
					min++;
					if(min>9)
					{
						min=0;
						decmin++;
						if(decmin>5)
						{
							decmin=0;
						}
						itoa(decmin, lcd_string, 10);
						lcd_gotoxy(1,0);
						lcd_puts(lcd_string);
					}
					itoa(min, lcd_string, 10);
					lcd_gotoxy(2,0);
					lcd_puts(lcd_string);
				}
				itoa(decsecs, lcd_string, 10);
				lcd_gotoxy(4,0);
				lcd_puts(lcd_string);
				
				
			}
			itoa(secs, lcd_string, 10);
			lcd_gotoxy(5,0);
			lcd_puts(lcd_string);
			
			suma= (10*decsecs+secs)*(10*decsecs+secs);    // suma == a ; a= seconds^2
			itoa(suma, lcd_string, 10);
			lcd_gotoxy(11,0);
			lcd_puts(lcd_string);
			
		}
		
		itoa(tens, lcd_string, 10);
		lcd_gotoxy(7,0);
		lcd_puts(lcd_string);

    }
}


ISR(TIMER0_OVF_vect)
{

	static uint8_t mysymbols = 0;
	static uint8_t position = 0;
		
		
	mysymbols++;
	
	if(mysymbols > 5)
	{
		mysymbols = 0;
		position++;
		if(position > 10)
		{
			position=1;
			lcd_gotoxy(1,1);
			lcd_puts("          ");
		}
	}
	lcd_gotoxy(position,1);
	lcd_putc(mysymbols);
	
	
	
}