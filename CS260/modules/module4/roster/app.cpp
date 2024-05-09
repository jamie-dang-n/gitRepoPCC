#include <iostream>
using namespace std;
#include "student.h"
#include "stack.h"

int main()
{
	Stack 	cs260;
	char	fileName[] = "roster.txt";

	cs260.loadFromFile(fileName);
	cout << cs260 << endl;

	Stack	cs260B(cs260);
	cout << "A copy of cs260 stack: " << endl;
	cout << cs260B << endl;

	Stack	cs260C = cs260;
	cout << "Another copy of cs260 stack: " << endl;
	cout << cs260C << endl;
	Student	aStudent;
	while(cs260C.pop(aStudent))
	{
		cout << "Pop a student: " << aStudent << endl;
		cout << cs260C << endl;
	}

	return 0;
}
