CC = gcc
LD = ld

CFLAGS = -fno-builtin -fno-stack-protector -nostdlib -nostdinc

clean :
	-rm *.o

boot.o : boot.S include/multiboot.h
	$(CC) -c $< -o $@

main.o : main.c include/monitor.h include/common.h include/multiboot.h
	$(CC) -c $< -o $@ $(CFLAGS)

common.o : common.c include/common.h
	$(CC) -c $< -o $@  $(CFLAGS)

monitor.o : monitor.c include/common.h include/monitor.h
	$(CC) -c $< $(CFLAGS) -o $@

kernel : boot.o main.o monitor.o common.o
	$(LD) -T linker.ld boot.o main.o monitor.o common.o -o $@

