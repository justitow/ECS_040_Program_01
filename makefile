CC = gcc
CFLAGS = -Wall -g
INCLUDES = -I./
LFLAGS=
LIBS=

SRCS = main.c decoder.c registers.c reader.c instruction.c

OBJS = $(SRCS:.c=.o)

MAIN = CPU.out

.PHONY: depend clean

all:	$(MAIN)
	@echo  Simple compiler named CPU.out has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<   -o  $@

clean:
	$(RM) *.o *~ $(MAIN)

depend:  $(SRCS)
	makedepend $(INCLUDES) $^

#  DO NOT DELETE THIS LINE
