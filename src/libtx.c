#include "libtx.h"


const int _delay = 1000000/BAUDRATE;

// Set TXPIN as output, and set the output to 1
// When idle, the TXPIN should always be 1, as per protocol
void libtx_setup() {
	DDRB |= _BV(TXPIN);
	PORTB |= _BV(TXPIN);
}

// Simply call the write function for each char
void libtx_write_string(char* string){
	for(int i = 0; string[i] != '\0'; i++) {
		libtx_write(string[i]);

	}
}

// The dataframe consists of:
// 1 start bit (0)
// 8 databits (LSB first)
// 1 stopbit
//
// Between each bit we use a single delay,
// calculated from the baudrate.
void libtx_write(char data) {
	//Send start bit
	PORTB &= ~_BV(TXPIN);
	_delay_us(_delay);

	//Data bits
	for(int i = 0; i < 8; i++) {
		if(data & 1) {
			PORTB |= _BV(TXPIN);
		} else {
			PORTB &= ~_BV(TXPIN);
		}
		data = data >> 1;
		_delay_us(_delay);
	}
	//Stop bit
	PORTB |= _BV(TXPIN);
	_delay_us(_delay);
	PORTB |= _BV(TXPIN);
}


