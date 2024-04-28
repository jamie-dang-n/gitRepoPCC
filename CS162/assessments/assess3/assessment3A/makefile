all: program

program: main.o groceryList.o item.o
	g++ -g -Wall -std=c++17 main.o groceryList.o item.o -o program

main.o: main.cpp
	g++ -g -c -std=c++17 -Wall main.cpp -o main.o

groceryList.o: groceryList.cpp
	g++ -g -c -std=c++17 -Wall groceryList.cpp -o groceryList.o

item.o: item.cpp
	g++ -g -c -std=c++17 -Wall item.cpp -o item.o

clean:
	rm *.o
