/*	Author: fgonz059
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab # 2 Exercise # 4
 *	Exercise Description: If weight >= 70, then PB1 = 1. If weight > 5 and weight < 70, PB1 = 0 and PB2 = 1. If weight <= 5, then B1 = 0 and B2 = 0
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xF6; PORTB = 0x09;

	unsigned char tempD = 0x00;
	unsigned char tempB = 0x00;
	// 0000 0000 0
	while (1) {
		tempD = PIND;
		tempB = PINB & 0x01;
		if ( (tempD >= 0x23)) { tempB = tempB | 0x02; } // IF WEIGHT >= 70
		if ( tempD >= 0x03) { tempB = tempB & 0xFD; 
				      tempB = tempB | 0x04;}
		if (tempD < 0x03) { tempB = tempB & 0xF9; } // weight <= 5, then B2B1 = 00

		PORTB = tempB;
	}
    return 1;
}
