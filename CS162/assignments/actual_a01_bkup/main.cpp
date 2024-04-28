/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Assignment 1
# Date:             7/6/23
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
