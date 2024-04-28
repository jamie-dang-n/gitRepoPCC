/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Assignment 1
# Date:             7/1/23
# Description:      This program is used to manage a list of tasks to be done
# 		    on a space station, keeping track of the task name,
#		    the employee's name, the day the task should be done,
#		    the duration (in hours) of the task, and the task type.
# Input:            text file tasks.txt and Task structs (+ data members) 
#		    input by the user.
# Output:           menu, input prompts, error messages, etc.
# Sources:          ZyBooks, some help from embedded tutor + an instructor 
#		    (Cody and Professor GD Iyer)
#******************************************************************************/
#include "main.h"

// Main Function
int main() {
	// Variables
	int count = 0;
	Task tasks[CAP];
	
	// Load in data + Open Data File
	loadData(tasks, count);

	// Welcome Message
	welcome();
	cout << endl; // blank line

	// Start Menu Loop
	exeMenu(tasks, count);
	
	// Thank you Message	
	cout << endl; // blank line
	cout << "Tasks written to file! Thank you for using my program!!" << endl;
	return 0;
}


//Name:   welcome()
//Desc:   This function displays the welcome message for the user.
//input:  none
//output: welcome message
//return: none
void welcome() {
	cout << "Welcome!" << endl;
	cout << "This program will help you manage your tasks for this Space Station." << endl;
}

//Name:   displayMenu()
//Desc:   This function displays the menu for the user's options.
//input:  none
//output: the options menu
//return: none
void displayMenu() {
	cout << "Pick an option from below:\n" << endl;
	cout << "(a)Add a new task" << endl;
	cout << "(b)List tasks by name" << endl;
	cout << "(c)Remove tasks by index" << endl;
	cout << "(d)Find task by name" << endl;
	cout << "(e)List tasks by type" << endl;
	cout << "(q)Quit" << endl;
	cout << endl; // blank line
}

//Name:   getOption()
//Desc:	  This function receives char input from the user and validates it
//input:  char userInput
//output: error message, calls to displayMenu()
//return: char userInput
char getOption() {
	char userInput;
	cin >> userInput;
	userInput = tolower(userInput);
	while(!validOption(userInput) || !cin || cin.peek() != '\n') {
		cout << endl; // blank line
		cout << "Invalid option!! Please try again!!" << endl;
		cout << endl; // blank line
		displayMenu();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> userInput;
		userInput = tolower(userInput);
	}
	return userInput;
}

//Name:   validOption()
//Desc:   This function validates the user's option choices based on the menu
//input:  char option
//output: none
//return: bool isValid
bool validOption(char option) {
	bool isValid = false;
	if (option != 'a' && option != 'b' && option != 'c' && option != 'q' && option != 'd' && option != 'e') {
		isValid = false;
	} else {
		isValid =  true;
	}
	return isValid;
}

//Name:   getInt()
//Desc:   This function receives an integer from the user and validates it.
//input:  int identifier, char prompt[], char error[], int num
//output: char prompt[], char error[]
//return: int num
int getInt(int identifier, char prompt[], char error[]) {
	int num = 0;
	
	cout << prompt;
	cin >> num;
	while (!cin || cin.peek() != '\n' || (checkInt(num, identifier) == false)) {
		cout << error << endl;
		cout << prompt;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');		
		cin >> num;
	}
	return num;
}

//Name:   checkInt() 
//Desc:   This function receives a number and based on the identifier 
//input:  const int num, const int identifier 
//output: none
//return: bool isValid
bool checkInt(const int num, const int identifier) {
	bool isValid = false;
	if (identifier == VERIFY_DAY) { // Verify Day of Task
		if (num >= 1 && num <= 30) {
			isValid =  true;
		} else {
			isValid =  false;
		}
	} else if (identifier == VERIFY_HOUR) { // Verify number of hours for Task
		if (num >= 1 && num <= 10) {
			isValid =  true;
		} else {
			isValid =  false;
		}
	} else if (identifier == VERIFY_TYPE) { // verifying task type ID
		if (num < 0 || num > 4) {
			isValid = false;
		} else {
			isValid =  true;
		}
	}
	return isValid;
}

//Name:   makeLower()
//Desc:   This function changes a phrase parameter into all lowercase characters
//input:  char phrase[]
//output: none
//return: none
void makeLower(char phrase[]) {
	int length = strlen(phrase);
	for (int i = 0; i < length; i++) {
		phrase[i] = tolower(phrase[i]);
	}
}

//Name:   exeMenu()
//Desc:   This function executes the menu loop-- displaying the menu and 
//	  asking the user for their option in the menu.
//input:  Task tasks[], int &count 
//output: calls to displayMenu()
//return: none
void exeMenu(Task tasks[], int &count) {
	char userOption;
	do {
		displayMenu();
		userOption = getOption();
		switch (userOption) {
			case 'a':
				addNewTask(tasks, count);
				break;
			case 'b':
				outputTasks(tasks, count);
				break;
			case 'c':
				removeTasks(tasks, count);
				break;
			case 'd':
				findTask(tasks, count);
				break;
			case 'e':
				listByType(tasks,count);
				break;
			case 'q':
				outputTasks(tasks, count, "tasks.txt");
				break;
			default:
				cout << "Error: Invalid Option chosen!" << endl;
				break;
		}
	} while (userOption != 'q');
}
