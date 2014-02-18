#include <util/twi.h>
#include <avr/interrupt.h>
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

#define TWI_RX_BUF_LEN

void twi_slave_init(unsigned char slave_addr_gcall_flag);

#endif
