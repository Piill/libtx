NAME := libtx
HEX := $(NAME).hex
ELF := $(NAME).elf
OUT := $(NAME).out
MAP := $(NAME).map
SOURCES := $(wildcard *.c)
HEADERS := $(wildcard *.h)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

MCU := attiny85
MCU_AVRDUDE := t85
PARTNO := usbasp 
DEVICE := usb
BITCLOCK := 200000Hz
AVRDUDE_FLAGS := -V -v  -U lfuse:w:0xE2:m 
FREQ := 8000000UL

CC := avr-gcc
OBJCOPY := avr-objcopy
SIZE := avr-size -A

CFLAGS := -Wall -pedantic -mmcu=$(MCU) -std=c99 -ggdb -Os -DF_CPU=$(FREQ)

all: $(HEX)

clean:
	rm -f $(HEX) $(OUT) $(MAP) $(OBJECTS)

debug: 
	avarice -w -g -P attiny85 :4242

flash: $(HEX)
	avrdude $(AVRDUDE_FLAGS)  -B $(BITCLOCK) -c $(PARTNO) -p $(MCU_AVRDUDE) -P $(DEVICE)  -U flash:w:$(HEX)

$(HEX): $(OUT)
	$(OBJCOPY) -R .eeprom -O ihex $< $@

$(OUT): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ -Wl,-Map,$(MAP) $^
	@echo
	@$(SIZE) $@
	@echo

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

%.pp: %.c
	$(CC) $(CFLAGS) -E -o $@ $<

%.ppo: %.c
	$(CC) $(CFLAGS) -E $<
