CC = g++
CPPFLAGS = -std=c++11 -g -Wall

main: main.o date.o item.o itemList.o

main.o: main.h date.h item.h itemList.h

itemList.o: date.h item.h itemList.h 

item.o: date.h item.h

date.o: date.h

clean: 
	rm *.o main
