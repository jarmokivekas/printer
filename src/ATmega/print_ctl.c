#include <avr/io.h>
#include "print_ctl.h"

// initialize printing hardware
void print_hardware_init(void){
	DDRD = 0xff;		// set all PORTD pins as outputs
}

// output appropriate signals for print head actuators
void print_begin(char columnData){
	PORTD = columnData;
}

// stop all print heads
void print_end(void){
	PORTD = 0x00;
}