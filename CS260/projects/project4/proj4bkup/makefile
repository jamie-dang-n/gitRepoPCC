CC = g++
CPPFLAGS = -std=c++17 -g -Wall
OBJS = main.o website.o bst.o

main: $(OBJS)

main.o: main.h bst.h

bst.o: website.h bst.h

website.o: website.h

clean:
	rm main *.o
