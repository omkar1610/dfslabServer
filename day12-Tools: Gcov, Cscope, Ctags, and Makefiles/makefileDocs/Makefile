CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lm
OBJECTS=main.o add.o mean.o
default: prog
all: prog
prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog $(LDFLAGS)
main.o: main.c add.h mean.h
	$(CC) $(CFLAGS) main.c -o main.o
mean.o: mean.c mean.h
	$(CC) $(CFLAGS) mean.c -o mean.o
add.o: add.c add.h
	$(CC) $(CFLAGS) add.c -o add.o
clean:
	rm -f $(OBJECTS)
