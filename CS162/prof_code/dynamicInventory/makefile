all: program

program: main.o inventory.o item.o
	g++ -g -std=c++17 main.o inventory.o item.o -o program

ain.o: main.cpp
	g++ -g -c -std=c++17 main.cpp -o main.o

inventory.o: inventory.cpp
	g++ -g -c -std=c++17 inventory.cpp -o inventory.o

item.o: item.cpp
	g++ -g -c -std=c++17 item.cpp -o item.o
clean:
	rm *.o
