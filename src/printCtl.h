#include <avr/io.h>

#ifndef PRINTCTL_H
#define PRINTCTL_H

// initialize printing hardware
void printingHWinit(){
	DDRD = 0xff;		// set all PORTD pins as outputs
}

// output appropriate signals for print head actuators
void beginPrint(colData){
	PORTD = colData;
}

// stop all print heads
void endPrint(){
	PORTD = 0x00;
}

#endif