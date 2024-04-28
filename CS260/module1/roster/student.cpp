#include "student.h"

Student::Student() : name(nullptr), gpa(0)
{
}

Student::Student(const char * name) : gpa(0)
{
	init(name, gpa);
}

Student::Student(const char * name, float gpa)
{
	init(name, gpa);
}

void Student::init(const char * name, float gpa)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	this->gpa = gpa;
}

Student::Student(const Student& aStudent): name(nullptr), gpa(0)
{
	*this = aStudent;
}

Student::~Student()
{
	if(this->name)
	{
		delete [] this->name;
	}
	this->name = nullptr;
}

float Student::getGpa() const
{
	return gpa;
}

const char * Student::getName() const
{
	return name;
}

void Student::setGpa(float gpa)
{
	this->gpa = gpa;
}

void Student::setName(const char * name)
{
	if(this->name)
	{
		delete [] this->name;
	}
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

const Student& Student::operator= (const Student& aStudent)
{
	if(this == &aStudent)
	{
		return *this;
	}

	setName(aStudent.name);
	setGpa(aStudent.gpa);
	return *this;
}

ostream& operator<< (ostream& out, const Student& aStudent)
{
	out << aStudent.name << '\t' << aStudent.gpa << endl;
	return out;
}

bool operator< (const Student& s1, const Student& s2)
{
	int compareResult = strcmp(s1.getName(), s2.getName());
	return compareResult < 0;
}
