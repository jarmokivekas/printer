#ifndef MAIN_H
#define MAIN_H

// Status LED states. Write to PORTC.
#define LED_RX_OK 0x00				// data rx is ongoing, ok
#define LED_RX_DONE	0x01			// data rx is done, ok
#define LED_RX_BUF_OVF 0x02			// rx buffer is full, rx interrupted
#define LED_RX_ERR 0x03				// unknown rx error, rx interrupted


#endif