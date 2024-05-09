CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJTS = app.o student.o stack.o 

app: $(OBJTS)

app.o: student.h stack.h

student.o: student.h

stack.o: stack.h student.h

clean:
	rm app *.o

