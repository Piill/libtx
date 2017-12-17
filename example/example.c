#include "../src/libtx.h"


int main() {
	libtx_setup();
	for(;;) {
		libtx_write_string("Hello world!\n\r");
		_delay_ms(100);
	}
}
