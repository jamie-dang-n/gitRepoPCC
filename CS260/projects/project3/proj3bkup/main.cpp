#include "main.h"

int main() {
	Table aTable;
	aTable.loadFromFile("data.txt");
	aTable.display();
	aTable.monitor();
	return 0;
}
