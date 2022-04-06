CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: sierpinski koch

simplecanvas.o: simplecanvas/simplecanvas.h simplecanvas/simplecanvas.cpp
	$(CC) $(CFLAGS) -c simplecanvas/simplecanvas.cpp

shape.o: simplecanvas.o shape.h shape.cpp
	$(CC) $(CFLAGS) -c shape.cpp

fractal.o: simplecanvas.o fractal.cpp
	$(CC) $(CFLAGS) -c fractal.cpp

sierpinski: sierpinski.cpp simplecanvas.o shape.o fractal.o
	$(CC) $(CFLAGS) -o sierpinski simplecanvas.o shape.o fractal.o sierpinski.cpp

koch: koch.cpp simplecanvas.o shape.o fractal.o
	$(CC) $(CFLAGS) -o koch simplecanvas.o shape.o fractal.o koch.cpp

clean:
	rm *.o sierpinski koch