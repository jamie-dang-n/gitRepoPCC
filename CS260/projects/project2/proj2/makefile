CC = g++
CPPFLAGS = -std=c++17 -g -Wall
OBJS = main.o stack.o queue.o group.o entry.o

main: $(OBJS)

main.o: main.h stack.h queue.h group.h entry.h

stack.o: stack.h group.h entry.h

queue.o: queue.h group.h

group.o: group.h

clean:
	rm main *.o
