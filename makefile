CC = g++
CFLAGS =-c -g -Wall -ansi

CPU.out: main.o decoder.o reader.o registers.o
	$(CC) main.o decoder.o reader.o registers.o -o CPU.out 
main.o: main.c main.h registers.h decoder.h reader.h instruction.h
	$(CC) main.c
decoder.o: decoder.c decoder.h registers.h main.h
	$(CC) decoder.c 
reader.o: reader.c reader.h
	$(CC) reader.c
registers.o: registers.c registers.h
	$(CC) registers.c
clean:
	rm *.o CPU.out
