#ifndef LIBTX
#define LIBTX
#include <util/delay.h>
#include <avr/io.h>


#define BAUDRATE 19200
#define TXPIN 1

//Write a single byte of data
void libtx_write(char data);

//Write a NULL-terminated string
void libtx_write_string(char* string);

//Setup the pin
void setup();
#endif
