CPU.out: main.o decoder.o instruction.o reader.o registers.o
	g++ -Wall -g -o CPU.out -ansi main.o decoder.o instruction.o reader.o registers.o

main.o: main.c main.h registers.h decoder.h reader.h instruction.h
	g++ -c -g -Wall -ansi main.c

reader.o: reader.c reader.h
	g++ -c -g -Wall -ansi reader.c

registers.o: registers.c registers.h
	g++ -c -g -Wall -ansi registers.c

decoder.o: decoder.c decoder.h
	g++ -c -g -Wall -ansi decoder.c

clean:
	rm *.o CPU.out
