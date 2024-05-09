#include <iostream>
using namespace std;
#include "student.h"
#include "list.h"

int main()
{
	List	cs260;
	char	fileName[] = "roster.txt";

	cs260.loadFromFile(fileName);
	cout << cs260 << endl;

	List	cs260B(cs260);
	cout << "A copy of the list ..." << endl;
	cout << cs260B << endl;

	cout << "Retrieving the 3rd student in the list ..." << endl;
	Student	aStudent;
	cs260.get(2, aStudent); 
	cout << aStudent << endl;

	cout << "Insert before the 3rd student ..." << endl;
	Student	bStudent("mike", 3.0);
	cs260.insert(2, bStudent);	
	cout << cs260 << endl;

	//test boundary cases too
	return 0;
}
