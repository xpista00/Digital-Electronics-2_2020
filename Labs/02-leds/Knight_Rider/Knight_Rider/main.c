/***********************************************************************
 * 
 * Alternately toggle two LEDs when a push button is pressed.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/

#define LED_RED1    PB1		// AVR pin where green LED is connected
#define LED_RED2    PB2
#define LED_RED3    PB3
#define LED_RED4    PB4
#define LED_RED5    PB5
#define BTN		    PD0
#define BLINK_DELAY 250
#ifndef F_CPU
#define F_CPU 16000000      // CPU frequency in Hz required for delay
#endif


/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions

/* Functions ---------------------------------------------------------*/
/**
 * Main function where the program execution begins. Toggle two LEDs 
 * when a push button is pressed.
 */
int main(void)
{
	unsigned int a=0; // number that help in condition
	/* LED 0 */
    // Set pin as output in Data Direction Register...
	DDRB = DDRB | (1<<LED_RED1);
	DDRB = DDRB | (1<<LED_RED2);
	DDRB = DDRB | (1<<LED_RED3);
	DDRB = DDRB | (1<<LED_RED4);
	DDRB = DDRB | (1<<LED_RED5);
    // ...and turn LED off in Data Register
	
	//Button
	DDRD = DDRD & ~(1<<BTN);
	PORTD = PORTD | (1<<BTN);
	
    /* LED 1 */
    // WRITE YOUR CODE HERE	
	PORTB = PORTB & ~(1<<LED_RED1);
	
	// LED 2
	PORTB = PORTB & ~(1<<LED_RED2);
	
	// LED 3
	PORTB = PORTB & ~(1<<LED_RED3);
		
	// LED 4
	PORTB = PORTB & ~(1<<LED_RED4);
	
	// LED 5
	PORTB = PORTB & ~(1<<LED_RED5);
	
	
	
    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
       // _delay_ms(BLINK_DELAY);
		// WRITE YOUR CODE HERE
		
				
		
		
		
		if (bit_is_clear(PIND,BTN) && a==0 )
		{
				
			PORTB = PORTB ^ (1<<LED_RED1);	// LED 1 on 
			_delay_ms(BLINK_DELAY);
			PORTB = PORTB ^ (1<<LED_RED1);	// LED 1 off
			a=a+1;
		}
		
		else if (bit_is_clear(PIND,BTN) && a==1 )
		{			
			PORTB = PORTB ^ (1<<LED_RED2);	// LED 2 on
			_delay_ms(BLINK_DELAY);
			PORTB = PORTB ^ (1<<LED_RED2);	// LED 2 off
			a=a+1;
			
		}
		else if (bit_is_clear(PIND,BTN) && a==2 )
		{
			PORTB = PORTB ^ (1<<LED_RED3);	// LED 3 on
			_delay_ms(BLINK_DELAY);
			PORTB = PORTB ^ (1<<LED_RED3);	// LED 3 off
			a=a+1;
		}
		else if (bit_is_clear(PIND,BTN) && a==3 )
		{
			PORTB = PORTB ^ (1<<LED_RED4);	// LED 4 on
			_delay_ms(BLINK_DELAY);
			PORTB = PORTB ^ (1<<LED_RED4);	// LED 4 off
			a=a+1;
		}
		else if (bit_is_clear(PIND,BTN) && a==4 )
		{								
			PORTB = PORTB ^ (1<<LED_RED5);	// LED 5 on
			_delay_ms(BLINK_DELAY);
			PORTB = PORTB ^ (1<<LED_RED5);	// LED 5 off
			a=a+1;
		}
		else if (bit_is_clear(PIND,BTN) && a==5 )
		{
			PORTB = PORTB ^ (1<<LED_RED4);	// LED 4 on
			_delay_ms(BLINK_DELAY);
			PORTB = PORTB ^ (1<<LED_RED4);	// LED 4 off
			a=a+1;
		}
		else if (bit_is_clear(PIND,BTN) && a==6 )
		{
			PORTB = PORTB ^ (1<<LED_RED3);	// LED 3 on
			_delay_ms(BLINK_DELAY);
			PORTB = PORTB ^ (1<<LED_RED3);	// LED 3 off
			a=a+1;
		}
		else if (bit_is_clear(PIND,BTN) && a==7 )
		{
			PORTB = PORTB ^ (1<<LED_RED2);	// LED 2 on
			_delay_ms(BLINK_DELAY);
			PORTB = PORTB ^ (1<<LED_RED2);	// LED 2 off
			a=0;
		}
	
    }

    // Will never reach this
    return 0;
}


