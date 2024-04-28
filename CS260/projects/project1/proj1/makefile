CC = g++
CPPFLAGS = -std=c++17 -g -Wall
OBJS = song.o songlist.o main.o

main: $(OBJS)

songlist.o: song.h

main.o: songlist.h song.h

clean:
	rm main *.o
