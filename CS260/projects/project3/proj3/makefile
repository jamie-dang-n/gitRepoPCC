CC = g++
CPPFLAGS = -std=c++17 -g -Wall
OBJS = main.o website.o table.o

main: $(OBJS)

main.o: main.h table.h

table.o: website.h table.h

website.o: website.h

clean:
	rm main *.o
