CPU.out: main.o decoder.o instruction.o reader.o registers.o
	g++ -g -Wall -ansi -o CPU.out main.o decoder.o instruction.o reader.o registers.o
main.o: main.c main.h registers.h decoder.h reader.h instruction.h
	g++ -g -Wall -ansi main.c
decoder.o: decoder.c decoder.h registers.h main.h
	g++ -g -Wall -ansi decoder.c
reader.o: reader.c reader.h
	g++ -g -Wall -ansi reader.c
registers.o: reagisters.c registers.h
	g++ -g -Wall -ansi registers.c
intruction.o: instruction.c intruction.h
	g++ -g -Wall -ansi instruction.c

