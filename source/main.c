/*	Author: fgonz059
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab # 2 Exercise # 4
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
    
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xF6; PORTB = 0x09;

	unsigned char tempD = 0x00;
	unsigned char tempB = 0x00;
	
	while (1) {
		tempD = PIND;
		tempB = PINB & 0x01;
		if ( ((tempD & 0x23) >= 0x23)) { tempB | 0x02; } // IF WEIGHT >
		if ((( tempD & 0x03) >= 0x03) && ((tempD & 0x23) < 0x23)) { tempB = tempB & 0xFD; temp B = temp B | 0x04;}
		if ((tempD & 0x02) <= 0x02) { tempB & 0x09; }
	
		PORTD = tempD;
		PORTB = tempB;
	}
    return 1;
}
