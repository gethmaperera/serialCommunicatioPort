
#define F_CPU 1000000UL

#include <avr/io.h>
#include <stdlib.h>
#include <math.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "incousart.h"


char buffer[10];
int x=0;

int main(void)
{
	DDRD = 0b11111110;
	PORTD = 0b0011100;
	DDRB=0xFF;
	
	usart_init();
	sei();
	while(1){
		while (x==0){
			
			usart_string_receive(buffer,'`');
			x=atoi(buffer);
		}
		if(x==1){
		PORTB = 0b00000010;
		x=0;
		}
	}
}