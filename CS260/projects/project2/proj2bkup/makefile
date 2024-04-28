CC = g++
CPPFLAGS = -std=c++17 -g -Wall
OBJS = main.o stack.o queue.o group.o

main: $(OBJS)

main.o: stack.h queue.h group.h

stack.o: stack.h group.h

queue.o: queue.h group.h

group.o: group.h

clean:
	rm main *.o
