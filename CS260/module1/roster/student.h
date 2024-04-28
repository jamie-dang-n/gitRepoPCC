#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;
#include <cstring>

class Student
{
public:
	Student(); // default constructor
	Student(const char * name); // paramterized constructor for name
	Student(const char * name, float gpa); // parameterized constructor for name and GPA
	Student(const Student& aStudent); // copy constructor
	~Student(); // destructor, use it to delete dynamically allocated data

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
