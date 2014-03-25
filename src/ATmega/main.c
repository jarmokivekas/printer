#include <avr/io.h>
#include <util/delay.h>
#include "main.h"
#include "twi_slave.h"
#include "print_ctl.h"
#include "font.h"

int main(){
	
	// Status LEDs are on PORTC pins 0,1,2,3: set as ouputs.
	DDRC |= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3);
	print_hardware_init();
	twi_slave_init((1 << 1));
	return 0;
}