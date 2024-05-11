#include "main.h"

int main() {
	Table aTable;
	char * keyWord = "computer";
	Website matches[101];
	int numFound = 0;
	bool success = false;

	aTable.loadFromFile("data.txt");
	
	Table table2(aTable);
	//table2.display();

	success = table2.retrieve(keyWord, matches, numFound);
	
	if (success) {
		for (int i = 0; i < numFound; i++) {
			cout << matches[i];
		}
	} else {
		cout << "no matches found" << endl;
	}

	return 0;
}
