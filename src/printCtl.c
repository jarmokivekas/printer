#include <avr/io.h>
#include "printCtl.h"

// initialize printing hardware
void printHWinit(void){
	DDRD = 0xff;		// set all PORTD pins as outputs
}

// output appropriate signals for print head actuators
void printBegin(char columnData){
	PORTD = columnData;
}

// stop all print heads
void printEnd(void){
	PORTD = 0x00;
}