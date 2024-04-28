//The implementation file for student.h
#include <iostream>
#include <cstring>

#include "Student.h"

using namespace std;

//creates a student, initializes with information and returns it.
Student initStudent(char *first, char *last, double gpa) {
	Student student;
	strcpy(student.first, first);
	strcpy(student.last, last);
	student.gpa = gpa;
	return student;
}

//returns the last name of the student in the given char array through the pointer.
void getLastName(char *studentName, Student student) {
	strcpy(studentName, student.last);
}

//returns the student's gpa
double getGPA(Student student) {
	return student.gpa;
}

//prints a single student information
void printStd(Student student)
{
	cout << student.first << ";" << student.last << ";" << student.gpa << endl;
}
