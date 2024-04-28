/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Assignment 2
# Date:             7/26/23
# Description:      This program is used to manage a list of tasks to be done
# 		    on a space station, keeping track of the task name,
#		    the employee's name, the day the task should be done,
#		    the duration (in hours) of the task, and the task type.
# Input:            text file tasks.txt and Task class objects + data members 
#		    input by the user.
# Output:           menu, input prompts, error messages, save data to tasks.txt,
#		    etc.
# Sources:          ZyBooks, some help from embedded tutor + an instructor 
#		    (Cody and Professor GD Iyer)
#******************************************************************************/
#include "main.h"

// Main Function
int main() {
	char fileName[MAXCHAR] = "tasks.txt";
	TaskList tasks(fileName);
	char option;
	do {
		getOption(option);
		exeMenu(option, tasks, fileName);
	} while (option != 'q');
	
	// Tester Code for parameterized constructor, copy constructor,
	// and assignment operator.
	testerCode();
	
	return 0;
}

//Name:   welcome() 
//Desc:   Displays a welcome message
//input:  none
//output: welcome message
//return: none
void welcome() {
	cout << "Welcome!" << endl;
	cout << "This program will help you manage your tasks for this Space Station." << endl;
}

//Name:   displayMenu() 
//Desc:   displays a menu of options
//input:  none
//output: menu
//return: none
void displayMenu() {
	cout << endl; // blank line
	cout << "Pick an option from below:\n" << endl;
	cout << "(a)Add a new task" << endl;
	cout << "(b)List tasks by name" << endl;
	cout << "(c)List tasks by Type" << endl;
	cout << "(d)Search by task name" << endl;
	cout << "(e)Remove tasks by index" << endl;
	cout << "(q)Quit" << endl;
	cout << endl; // blank line
}

//Name:   getOption() 
//Desc:   This function reads in an option from the user (for the menu)
//input:  char &option
//output: calls to displayMenu() and error messages
//return: none
void getOption(char &option) {
	displayMenu();
	cin >> option;
	option = tolower(option);
	while (!validOption(option) || !cin || cin.peek() != '\n') {
		cout << endl; // blank line
		cout << "Invalid option!! Please try again!" << endl;
		displayMenu();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> option;
	}
}


//Name:   validOption() 
//Desc:   this is a helper function that validates good menu input
//input:  char option
//output: none
//return: bool isValid
bool validOption(char option) {
	bool isValid = false;
	if (option == 'a' || option == 'b' || option == 'c' || option == 'd' || option == 'e' || option =='q') {
		isValid = true;
	}
	return isValid;
}



//Name:   exeMenu() 
//Desc:   This function executes menu options based on char option
//input:  char option, TaskList &tasks, char fileName[]
//output: none
//return: none
void exeMenu(char option, TaskList &tasks, char fileName[]) {
	switch(option){
		case 'a':
			tasks.addTask();
			break;
		case 'b':
			tasks.listTaskN();
			break;
		case'c':
			tasks.listTaskT();
			break;
		case 'd':
			tasks.searchTask();
			break;
		case 'e':
			tasks.removeTask();
			break;
		case 'q':
			cout << endl; // blank line
			cout << "Tasks written to file! Thank you for using my program!!" << endl;
			tasks.writeOut(fileName);
			break;
		default:
			cout << "Invalid option!! Please try again!" << endl;
			break;
	}
}

//Name:   testerCode()
//Desc:   This function tests the parameterized constructor, copy constructor, and 
//	  the assignment operator overload for the Task class
//Input:  none
//Output: Data from firstTask, secondTask, and thirdTask (all Task objects)
//Return: none
void testerCode() {
	char taskOne[] = "firstTask";
	char taskTwo[] = "secondTask";
	char taskThree[] = "thirdTask";

	char sampleTask[] = "Call Dad";
	char samplePerson[] = "Jamie Dang";
	int sampleDay = 3;
	int sampleDuration = 5;
	int sampleType = 2;

	cout << endl; // blank line
	// Parameterized Constructor
	cout << "Testing parameterized constructor with firstTask" << endl;
	Task firstTask(sampleTask, samplePerson, sampleDay, sampleDuration, sampleType);
	printTask(firstTask, taskOne);
	cout << endl; // blank line

	// Assignment Operator Overload
	Task secondTask;
	secondTask = firstTask;
	cout << "Set secondTask to be the same as firstTask" << endl;
	printTask(secondTask, taskTwo);
	cout << endl; // blank line

	// Copy Constructor
	Task thirdTask(secondTask);
	cout << "Initialized thirdTask with secondTask" << endl;
	printTask(thirdTask, taskThree);
	cout << endl; // blank line

}

//Name:   printTask()
//Desc:   A helper function to print out each task in testerCode()
//input:  Task &aTask, char aName[]
//output: aTask data members
//return: none
void printTask(Task &aTask, char aName[]) {
	char taskN[MAXCHAR];
	char personN[MAXCHAR];
	aTask.getTaskName(taskN);
	aTask.getPersonName(personN);
	cout << aName << " Print Data:" << endl;
	cout << "The task is: " << taskN << endl;
	cout << "The person doing the task is " << personN << endl;
	cout << "The day this is done is " << aTask.getDay() << endl;
	cout << "The duration of this task is " << aTask.getDuration() << endl;
	cout << "The type of task this is, is: ";
	switch(aTask.getType()) {
		case Operations:
			cout << "Operations" << endl;
			break;
		case Maintenance:
			cout << "Maintenance" << endl;
			break;
		case Inventory:
			cout << "Inventory" << endl;
			break;
		case Communications:
			cout << "Communications" << endl;
			break;
		case Others:
			cout << "Others" << endl;
			break;
	}

}

