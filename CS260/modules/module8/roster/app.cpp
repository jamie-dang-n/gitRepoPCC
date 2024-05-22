#include <iostream>
using namespace std;
#include "student.h"
#include "table.h"

int main()
{
	Table	cs260;
	char	fileName[] = "roster.txt";

	cs260.loadFromFile(fileName);
	cout << cs260 << endl;

	cs260.saveToFile(fileName);
	return 0;
}
