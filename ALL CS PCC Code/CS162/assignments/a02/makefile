CC = g++
CPPFLAGS = -std=c++17 -g -Wall
OBJS = task.o tasklist.o  main.o

main: ${OBJS}

tasklist.o: task.h

main.o: tasklist.h task.h

clean:
	rm main *.o
