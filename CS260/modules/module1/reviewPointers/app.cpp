#include <iostream>
using namespace std;
#include <cstring>

struct Student
{
	char * 	name;
	float	gpa;
};

void reviewBasicOperators();
void reviewCommonCrashes();

int main()
{
	//reviewBasicOpeartors();
	reviewCommonCrashes();

	return 0;
}

void reviewCommonCrashes()
{
	Student * aStudent;
	aStudent = new Student;
	aStudent->gpa = 4.0;

	char 	name[]	= "mike";
	aStudent->name = new char[strlen(name)+1];
	strcpy(aStudent->name, name);
	cout << "Student A: " << aStudent->name << '\t' << aStudent->gpa << endl;

	Student	*	bStudent = aStudent;
	cout << "Student B: " << bStudent->name << '\t' << bStudent->gpa << endl;
	delete [] aStudent->name;
	delete aStudent;
}

void reviewBasicOperators()
{
	int		number = 10;
	int *	intPtr = nullptr;

	intPtr = &number;
	*intPtr = 20;
 
	int **	ptr = &intPtr;

	intPtr = new int[number];
	*(intPtr+2) = 5;
	intPtr[4] = 10;

	delete [] intPtr;
	intPtr = &number;
}



	
