#include <avr/io.h>

#ifndef PRINT_H
#define PRINT_H

void printingHWinit(){
	// set all PORTD pins as outputs
	DDRD = 0xff;
}

void printColumn(colData){
	PORTD = colData;
}
#endif