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

descriptor.o : descriptor.c include/descriptor.h
	$(CC) -c $< $(CFLAGS) -o $@

descriptorS.o : descriptor.S
	$(CC) -c $< -o $@

kernel : boot.o main.o monitor.o common.o descriptor.o descriptorS.o
	$(LD) -T linker.ld boot.o main.o descriptor.o monitor.o common.o descriptorS.o -o $@

