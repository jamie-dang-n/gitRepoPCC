CC = g++
CPPFLAGS = -std=c++17 -g -Wall
OBJS = dlist.o supplied.o main.o

main: $(OBJS)

dlist.o: dlist.h supplied.o

main.o: dlist.h supplied.o

clean:
	rm dlist.o main.o main
