CC = g++
CPPFLAGS = -std=c++17 -g -Wall
OBJS = table.o supplied.o main.o

main: $(OBJS)

dlist.o: table.h supplied.o

main.o: table.h supplied.o

clean:
	rm table.o main.o main
