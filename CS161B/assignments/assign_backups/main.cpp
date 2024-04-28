/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Assignment 6
# Date:             5/27/2023
# Description:      This program reads in data from the students.txt file to save 
#                   into a Course struct variable.  This program also allows the 
#  		    user to drop a student from a course, then reprints the 
# 		    course list. The students are inserted sorted by last name.
# Input:            student.txt file
# Output:           The students in the course list.
# Sources:          Zybooks, Assignment 6 Specifications
#******************************************************************************/
//The client file or the driver file
//This file has the main() function
//Add header comments here.
#include <iostream>
#include <cstring>

#include "Student.h"
#include "Course.h"

using namespace std;

int main() {
	Course course = initCourse();
	ifstream inFile;
	cout << "Welcome to my Course Roster Program\n" << endl;
	inFile.open("students.txt");
	if(!inFile)
	{
		cout << "File did not open! Program Exiting!!" << endl;
		return 0;
	}
	//calls readStudent to read from the file
	readStudent(inFile, course);
	//calls printRoster to print the roster
	cout << "Here is the course roster: " << endl;
	printRoster(course);

	//calls dropStudent to drop a student from the roster.
	//read a last name into a char array and pass to function.
	char lastName[100];
	cout << "Enter the last name of the student to drop: ";
	cin.getline(lastName, 100);
	dropStudent(lastName, course);


	//calls printRoster to print the roster after the student drop.
	cout << "\nHere is the course roster: " << endl;
	printRoster(course);

	//calls findStudentHighestGPA to get Student with highest GPA
	cout << "The student with the highest GPA:" << endl;
	Student maxStudent;
	maxStudent = findStudentHighestGPA(course);

	//calls printStd to print the student with the highest GPA
	printStd(maxStudent);
	cout << endl; //blank line

	cout << "Thank you for using my Student Roster program!!" << endl;
	return 0;
}
