#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;
#include <cstring>

class Student
{
public:
	Student();
	Student(const char * name);
	Student(const char * name, float gpa);
	Student(const Student& aStudent);
	~Student();

	float getGpa() const;
	const char * getName() const;
	void setGpa(float gpa);
	void setName(const char * name);
	const Student& operator= (const Student& aStudent);
	friend ostream& operator<< (ostream& out, const Student& aStudent);	

private:
	char *	name;
	float	gpa;

	void init(const char * name, float gpa);
};
bool operator< (const Student& student1, const Student& student2);

#endif
