#include "../src/libtx.h"


int main() {
	setup();
	for(;;) {
		libtx_write_string("Hello world!\n\r");
		_delay_ms(100);
	}
}
