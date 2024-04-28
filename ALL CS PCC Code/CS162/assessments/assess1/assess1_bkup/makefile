all: program

program: main.o carLot.o car.o
	g++ -g -Wall -std=c++17 main.o carLot.o car.o -o program

main.o: main.cpp
	g++ -g -c -std=c++17 -Wall main.cpp -o main.o

carLot.o: carLot.cpp
	g++ -g -c -std=c++17 -Wall carLot.cpp -o carLot.o

car.o: car.cpp
	g++ -g -c -std=c++17 -Wall car.cpp -o car.o

clean:
	rm *.o
