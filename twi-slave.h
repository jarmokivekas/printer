#include <util/twi.h>
#include <avr/io.h>
#ifndef TWI_SLAVE_H
#define TWI_SLAVE_H

// clear INTerrupt flag, Enable Ack, ENable interface, Enable Interrupts.
// call to start monitoring the TWI bus
// call in ISR to continue monitoring after interrupt has been serviced
#define TWI_MONITOR() TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN)|(1<<TWIE);

// stop the TWI interface
#define TWI_DISABLE() TWCR = 0x00;

// Same as TWI_MONITOR, except Enable Ack is not set (won't send ACK to bus).
// HW is still monitoring and interrupts are still generated.
// Use for temporary isolation from bus.
#define TWI_PAUSE()   TWCR = (1<<TWINT)|(0<<TWEA)|(1<<TWEN)|(1<<TWIE);

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

// Interrupts are issued after all bus events, service them.
// Write and read data through TWDR (TWI Data Redgister).
// Call TWI_MONITOR() to have the interface continue monitoring.
ISR(TWI_vect){

	switch(TW_STATUS){

		// ---- Slave Receive Conditions ---- 
		case TW_SR_SLA_ACK:

		case TW_SR_ARB_LOST_SLA_ACK:

		case TW_SR_GCALL_ACK:

		case TW_SR_ARB_LOST_GCALL_ACK:

		case TW_SR_DATA_ACK:

		case TW_SR_DATA_NACK:

		case TW_SR_GCALL_DATA_ACK:

		case TW_SR_GCALL_DATA_NACK:

		case TW_SR_STOP:

		// ---- Slave Transmit Conditions ---- 
		case TW_ST_SLA_ACK:

		case TW_ST_ARB_LOST_SLA_ACK:

		case TW_ST_DATA_ACK:

		case TW_ST_DATA_NACK:

		case TW_ST_LAST_DATA:

		// ---- Misc conditions ----
		case TW_NO_INFO:

		case TW_BUS_ERROR:

		default :
			TWI_MONITOR();
	}
}

#endif
