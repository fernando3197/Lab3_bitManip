/*	Author: fgonz059
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab # 2 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char count = 0x00;
	unsigned char i = 0;
	while (1) {
		tempA = PINA;
		tempB = PINB;
		count = 0;
		for (i = 0; i < 8; i = i + 1){
			if (tempA & (0x01 << i ) ){
				count = count + 1;	
			}

			if (tempB & (0x01 << i ) ){
				count = count + 1;
			}
		}
		PORTC = count;		
	}
    return 1;
}
