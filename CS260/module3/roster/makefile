CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJTS = app.o student.o list.o

app: $(OBJTS)

app.o: student.h list.h

student.o: student.h

list.o: list.h student.h

clean:
	rm app *.o

