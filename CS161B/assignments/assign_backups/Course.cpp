//The implementation file for Course.h
//It loads students from a text file.
#include <iostream>
#include <cstring>

#include "Course.h"
#include "Student.h"
using namespace std;

//initiaizes a course variable and returns it. The array is empty
//and the number of students is set to 0.
Course initCourse() {
	Course course;
	course.numStudents = 0;
	return course;
}

//reads a student from the file and calls AddStudent
void readStudent(ifstream &inFile, Course &course)
{

       	/*Add code here to read from the file and call addStudent to add each student to the roster.*/ 
	Student student;
	inFile.get(student.first, 100, ';');
	while(!inFile.eof()) {
		inFile.ignore(100, ';');
		inFile.get(student.last, 100, ';');
		inFile.ignore(100, ';');
		inFile >> student.gpa;
		inFile.ignore(100, '\n');
		addStudent(student, course);
		inFile.get(student.first, 100, ';');
	}
	inFile.close();
}


//adds a student to the roster, and increment count
//modify this function to add the student sorted by name
//do not use any sorting functions.
//See this example in zyBooks Section 14.7 [https://learn.zybooks.com/zybook/PCCCS161BSpring23/chapter/14/section/7]
void addStudent(Student student, Course &course) {
	int i = 0;
	if (course.numStudents == 0) {
		course.roster[0].gpa = student.gpa;
		strcpy(course.roster[0].last, student.last);
		strcpy(course.roster[0].first, student.first);
	} else {
		for(i = 0; i < course.numStudents; i++) {
			if (!(strcmp(course.roster[i].last, student.last) < 0)) { 
				break;	
			}
		}	
		for (int j = course.numStudents; j > i; j--) {
			course.roster[j] = course.roster[j - 1];
		}
		course.roster[i] = student;
	}
	course.numStudents++; // Increment Size
}




//prints a whole Course roster calling student print.
//use a for loop and print all the students
//must call the printStd function in Student.h
void printRoster(Course course)
{
	for (int i = 0; i < course.numStudents; i++) {
  		printStd(course.roster[i]);
	}
	cout << endl; // blank line
}

/*add code and function comments for the below 2 functions. */

// Name:   dropStudent()
// Desc:   Removes a student from the course roster if found.
// Input:  char lastname by pointer, Course course by reference
// Output: None
// Return: None
void dropStudent(char *lastname, Course &course) {
	int pos = -1;
	for (int i = 0; i < course.numStudents; i++) {
		if (strcmp(lastname, course.roster[i].last) == 0) {
			pos = i;
			break;
		}

	}
	if (pos != -1) {
	
		for (int j = pos; j < course.numStudents - 1; j++) {
			course.roster[j] = course.roster[j + 1];
		}
		course.numStudents--;
	}
}

// Name:   findStudentHighestGPA()
// Desc:   Finds and returns the student with the highest gpa
// Input:  Course course
// Output: None
// Return: Student maxStudent
Student findStudentHighestGPA(Course course) {
	Student maxStudent = course.roster[0];
	double maxGpa = course.roster[0].gpa;
	int i = 0;
	for (i = 0; i < course.numStudents; i++) {
		if (course.roster[i].gpa > maxGpa) {
			maxGpa = course.roster[i].gpa;
			maxStudent = course.roster[i];
		}
	}
	return maxStudent;
}
