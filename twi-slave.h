#include <util/twi.h>
#include <avr/io.h>
#ifndef TWI_SLAVE_H
#define TWI_SLAVE_H

// clear INTerrupt flag, Enable Ack, ENable interface, Enable Interrupts.
// call to start monitoring the TWI bus
// call in ISR to continue monitoring after interrupt has been serviced
#define TWI_MONITOR() {TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN)|(1<<TWIE);}

// stop the TWI interface
#define TWI_DISABLE() {TWCR = 0x00;}

// same as TWI_MONITOR, except Enable Ack is not set (won't send ACK to bus).
// HW is still monitoring, use for temporary isolation from bus.
#define TWI_PAUSE()   {TWCR = (1<<TWINT)|(0<<TWEA)|(1<<TWEN)|(1<<TWIE);}

// 7 MSB are the 7-bit i2c slave address
// set LSB (TWGCE) to enable general call addressing
void twi_slave_init(unsigned char address, bool enable_general_call){
	sei()
	TWAR = (address << 1);
	if (enable_general_call) TWAR |= (1 << TWGCE);
	TWI_MONITOR();
}

// Interrupts are issued after all bus events, service them
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

		case TW_START:

		case TW_REP_START:

		// ---- Misc conditions ----
		case TW_NO_INFO:

		case TW_BUS_ERROR:

		default :
			TWI_MONITOR();
	}
}

#endif
