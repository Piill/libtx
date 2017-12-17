#include "libtx.h"


const int _delay = 1000000/BAUDRATE;
void setup() {
	DDRB |= _BV(TXPIN);
	PORTB |= _BV(TXPIN);
}

void libtx_write_string(char* string){
	for(int i = 0; string[i] != '\0'; i++) {
		libtx_write(string[i]);

	}
}
void libtx_write(char data) {
	//Send start bit
	PORTB &= ~_BV(TXPIN);
	_delay_us(_delay);

	//Data bits
	for(int i = 0; i < 8; i++) {
		if((data & 1) != 0) {
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


