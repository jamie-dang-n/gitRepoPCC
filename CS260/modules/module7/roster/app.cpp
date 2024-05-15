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

	Table	cs260B(cs260);
	cout << "A copy of cs260 table: " << endl;
	cout << cs260B << endl;

	Table	cs260C = cs260;
	cout << "Another copy of cs260 table: " << endl;
	cout << cs260C << endl;

	Student	aStudent;
	if(cs260C.remove("tom", aStudent))
	{
		cout << "Student removed: " << aStudent << endl;
	}
	cout << cs260C << endl;

	cs260C.add(aStudent);
	cs260.saveToFile(fileName);
	return 0;
}
