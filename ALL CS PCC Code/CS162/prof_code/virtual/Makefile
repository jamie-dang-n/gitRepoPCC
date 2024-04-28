#CS162 PCC, Makefile for virtual inheritance

all: program

program: Rect.o Box.o main.o
	g++ -Wall -g Rect.o Box.o main.o -o program

Rect.o: Rect.cpp
	g++ -Wall -g -c Rect.cpp

Box.o: Box.cpp
	g++ -Wall -g -c Box.cpp

main.o: main.cpp
	g++ -Wall -g -c main.cpp

clean:
	rm Rect.o Box.o main.o
