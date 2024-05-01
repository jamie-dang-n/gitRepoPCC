CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJTS = app.o student.o table.o 

app: $(OBJTS)

app.o: student.h table.h

student.o: student.h

table.o: table.h student.h

clean:
	rm app *.o

