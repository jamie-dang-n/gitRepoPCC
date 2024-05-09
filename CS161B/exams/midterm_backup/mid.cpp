/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Midterm
# Date:             5/7/2023
# Description:      This program implements the "pop" function of a stack using
# 		    an array data structure. The user can choose from a menu to
#		    pop, print, or quit the program.
# Input:            char userOption, int userInt
# Output:           error messages, individual values in the stack, the stack
#		    itself.
# Sources:          Midterm Specifications
#******************************************************************************/
#include <iostream>
#include <limits> // for cin.ignore
#include <cctype> // for tolower()

using namespace std;

// Function Prototypes
int pop(int stack[], int &size, int val);
void printStack(int stack[], int size);
int getInt();

// Constants
const int MAX = 3; // maximum size of stack
const int MENU_SIZE = 30;

// Main
int main() {
	// Variables
	int stack[MAX] = {8, -2, 3}; // integer array for stack
	int size = 3;   // contains number of elements in stack

	// Add your code here
	char userOption = '\0';
	int userInt = 0, popResult = 0;
	char menu[MENU_SIZE] = "Enter option (r, p, q): ";
	

	// Welcome Message
	cout << "Welcome to the LIFO Stack Program!" << endl;
	cout << endl; // blank line

	// User Input/Menu Options
	while (userOption != 'q') {
		cout << menu;
		cin >> userOption;
		userOption = tolower(userOption);	
		switch(userOption) {
			case 'r':
				userInt = getInt();
				popResult = pop(stack, size, userInt);
				if (popResult == 1) {
					cout << "Stack is empty, no values to pop." << endl;
				} else if (popResult == 2) {
					cout << userInt << " is not in the stack." << endl;
				}
				printStack(stack, size);
				cout << endl; // blank line
				break;
			case 'p':
				printStack(stack, size);
				cout << endl; // blank line
				break;
			case 'q':
				cout << endl; // blank line
				cout << "Goodbye!" << endl;
				break;
			default:
				cout << "Invalid Option." << endl;
				cout << endl; // blank line
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
		}
	}
	return 0;
}

//Function Definitions

//Name:   pop()
//Desc:   This function "pops" the values in the stack,
//	  starting from the first occurrance of the value
//	  and removing to the end of the stack.
//input:  None
//output: info about if a value is in the stack or if 
//	  an option is invalid, the stack itself
//return: int popResult
int pop(int stack[], int &size, int val){
	int popResult = 0, i = 0, j = 0, pos = 0;
	if (size == 0) {
		popResult = 1;
	} else {
		for(i = 0; i < size; i++) {
			if (stack[i] == val) {
				pos = i;
				break;
			}
		}

		if (i == size) {
			popResult = 2;	
		} else {
			for (j = pos; j < size; j++) {
				stack[j] = 0;
			}
			size = pos;
		}
	}
	return popResult;
}

// Name:   getInt()
// Desc:   This function gets and validates integer input.
// Input:  int val
// Output: error message, prompt for integer value
// Return: int val 
int getInt() {
	int val = 0;
	cout << "Integer: ";
	cin >> val;
	while (!cin || cin.peek() != '\n') {
		cout << "Error: Invalid Integer. Please try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Integer: ";
		cin >> val;
	}
	return val;
}

// Name:   printStack()
// Desc:   Call this function to print the stack.
// Input:  none
// Output: prints each value of the stack
// Return: none 
void printStack(int stack[], int size){
	cout << "[";
	for (int i = 0; i < size; i++){
		cout << stack[i];

		if (i != size - 1)
			cout << ", " ;
	}
	cout << "]" << endl;
}


