CC = g++
CPPFLAGS = -Wall -g -std=c++11 -m32 
LDFLAGS = -m32

app:			app.o linkedlist.o randomarray.o

app.o:		linkedlist.h

linkedlist.o:		linkedlist.h

.PHONY:	clean
clean:				# clean the directory
				$(info -- cleaning the directory --)
				rm -f app.o linkedlist.o
