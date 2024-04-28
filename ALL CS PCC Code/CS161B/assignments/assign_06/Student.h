//The student struct
#ifndef STUDENT_H_
#define STUDENT_H_

struct Student {
	char first[20];
	char last[20];
	double gpa;
};

//Function Prototypes
Student initStudent(char *first, char *last, double gpa);
void getLastName(char *studentName, Student student);
double getGPA(Student student);
void printStd(Student student);

#endif
