/*	Author: fgonz059
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab # 2 Exercise # 3
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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tempA = 0x00;
	unsigned char tempC = 0x00;
	
	while (1) {
		tempA = PINA & 0x0F;
		tempC = 0x00;
		if (      (tempA == 1) || (tempA == 2)) { tempC = tempC | 0x20; /* PC5 */ }
		else if ( (tempA == 3) || (tempA == 4)) { tempC = tempC | 0x30;/* PC5 PC4 */ }
		else if ( (tempA == 5) || (tempA == 6)) { tempC = tempC | 0x38;/* PC5 PC4 PC3 */ }
		else if ( (tempA >= 7) && (tempA <= 9)) { tempC = tempC | 0x3C;/* PC5 PC4 PC3 PC2 */ }
		else if ( (tempA >= 10) &&(tempA <=12)) { tempC = tempC | 0x3E;/* PC5 PC4 PC3 PC2 PC1 */ }
		else if ( (tempA >= 13) &&(tempA <=15)) { tempC = tempC | 0x3F;/* PC5 PC4 PC3 PC2 PC1 PC0 */ }
		
		if ( tempA <= 4 ) { tempC = tempC | 0x40; /* PC6 */ } // Low fuel
	
		// Part 2
		tempA = PINA;
		if ( (tempA & 0x70 ) == 0x30 ) { tempC = tempC | 0x80; } 		
	
		PORTC = tempC;			
	}
    return 1;
}
