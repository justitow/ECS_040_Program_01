CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c decoder.c functions.c reader.c registers.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=CPU.out

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $
	(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm edit $(OBJECTS)