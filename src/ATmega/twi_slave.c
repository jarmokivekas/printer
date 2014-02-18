#include <util/twi.h>
#include <avr/interrupt.h>
#include <avr/io.h>

void twi_slave_init(unsigned char slave_addr_gcall_flag){
	// enable interrupts
	sei();
	// ensure TWI is enabled in power reduction register
	PRR &= ~(1<<PRTWI);
	// TWAR 7 MSB are the 7-bit i2c slave address
	// set TWAR LSB (TWGCE) to enable general call addressing
	TWAR = (slave_addr_gcall_flag);
	// start monitoring the bus
	TWI_MONITOR();
}

volatile unsigned char receive_buffer[TWI_RX_BUF_LEN];
volatile unsigned int receive_pointer = 0x00; 

// Interrupts are issued after all bus events, service them.
// Write and read data through TWDR (TWI Data Redgister).
// Call TWI_MONITOR() to have the interface continue monitoring.

ISR(TWI_vect){

	switch(TW_STATUS){

		case TW_SR_SLA_ACK:
		case TW_SR_GCALL_ACK:
			receive_pointer = 0x00;
			PORTC |= LED_RX_OK;
			TWI_MONITOR();
			break;
		case TW_SR_DATA_ACK:
		case TW_SR_GCALL_DATA_ACK:
			if (receive_pointer < TWI_RX_BUF_LEN){
				receive_buffer[receive_pointer] = TWDR;
				receive_pointer++;
				PORTC |= LED_RX_OK;
				TWI_MONITOR();
			}
			else{
				PORTC |= LED_RX_BUF_OVF;
				TWI_PAUSE();
			}				
			break;
		case TW_SR_STOP:
			PORTC |= LED_RX_DONE;
			TWI_MONITOR();
			break;

		// Bus conditions that should not occur, default to error.
		// TWI_MONITOR() needs to be called to resume.
		// case TW_SR_ARB_LOST_SLA_ACK:
		// case TW_SR_ARB_LOST_GCALL_ACK:
		// case TW_SR_DATA_NACK:
		// case TW_SR_GCALL_DATA_NACK:
		// case TW_ST_SLA_ACK:
		// case TW_ST_ARB_LOST_SLA_ACK:
		// case TW_ST_DATA_ACK:
		// case TW_ST_DATA_NACK:
		// case TW_ST_LAST_DATA:
		// case TW_NO_INFO:
		// case TW_BUS_ERROR:
		default :
			PORTC |= LED_RX_ERR;
			TWI_PAUSE();
	}
}
