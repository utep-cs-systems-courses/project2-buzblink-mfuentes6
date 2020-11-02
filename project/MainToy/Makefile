COMMON_OBJECTS =
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/pot/ti/msp430_gcc/include


CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: main.elf


main.elf: ${COMMON_OBJECTS} P2_Interupt_Handler.o WD_Interupt.o buzzer.o led.o switches.o main.o
	../lib/libTimer.a ${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

buzzer.o: buzzer.c buzzer.h

switches.o: switches.c switches.h

main.o: main.c

WD_Interupt.o: state_machine.h buzzer.h

P2_Interupt_Handler.o: P2_Interupt_Handler.c switches.h
