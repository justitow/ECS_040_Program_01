CC = g++
CFLAGS = -g -Wall -ansi -I.

CPU.out: main.o decoder.o reader.o registers.o
	$(CC) -o CPU.out main.o decoder.o reader.o registers.o 
main.o: main.c main.h registers.h decoder.h reader.h instruction.h
	$(CC) main.c
decoder.o: decoder.c decoder.h
	$(CC) decoder.c 
reader.o: reader.c reader.h
	$(CC) reader.c
registers.o: registers.c registers.h
	$(CC) registers.c
clean:
	rm *.o CPU.out
