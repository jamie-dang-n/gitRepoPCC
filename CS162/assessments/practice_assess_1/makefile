CC = g++
CPPFLAGS = -std=c++11 -g -Wall

main: main.o item.o itemList.o

main.o: main.h item.h itemList.h

itemList.o: item.h itemList.h

item.o: item.h

clean: 
	rm *.o main
