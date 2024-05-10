#include "main.h"

int main() {
	Table aTable;
	aTable.loadFromFile("data.txt");
	
	Table table2(aTable);
	
	table2.display();
	table2.monitor();
	
	return 0;
}
