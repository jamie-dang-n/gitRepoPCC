CC = g++
CPPFLAGS = -Wall -g -std=c++11

app:			app.o clist.o supplied.o

app.o:			clist.h

clist.o:		clist.h

.PHONY: clean	
clean:				# clean the directory
				$(info -- cleaning the directory --)
				rm -f clist.o app.o app
