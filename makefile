CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: sierpinski

simplecanvas.o: simplecanvas/simplecanvas.h simplecanvas/simplecanvas.cpp
	$(CC) $(CFLAGS) -c simplecanvas/simplecanvas.cpp

sierpinski: sierpinski.cpp simplecanvas.o
	$(CC) $(CFLAGS) -o sierpinski simplecanvas.o sierpinski.cpp

clean:
	rm *.o sierpinski