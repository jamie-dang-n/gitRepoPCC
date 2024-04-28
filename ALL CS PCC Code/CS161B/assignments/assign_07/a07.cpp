//*****************************************************************************
// Author:           Jamie Dang
// Assignment:       Assignment 7
// Date:             6/1/2023
// Description:      This program reads in 2 integers from the user, then 
// 		     swaps the integers, divides the first by the second, and 
// 		     raises the first to the power of the second variable. All 
// 		     information is saved via pointers.
// Input:            ints num1, num2
// Output:           ints num1, num2 OR int * num1ptr, num2ptr
// Sources:          a07 Specifications + Zybooks
//*****************************************************************************
#include <iostream>
#include <limits> // for cin.ignore

using namespace std;

// Constants
const int MAXCHAR = 20;

// Function Prototypes
int getInput(char prompt[]);
void swapArgs (int *ptr1, int *ptr2);
void divideArgs(int *ptr1, int *ptr2);
void powerArgs(int *ptr1, int *ptr2);

// Main
int main(){
	// Variables
	int num1 = 0, num2 = 0;
	int *num1ptr = NULL; 
	int *num2ptr = NULL;
	char prompt1[MAXCHAR] = "Enter Integer 1: ";
	char prompt2[MAXCHAR] = "Enter Integer 2: ";

	// Getting Input + Validating It
	num1 = getInput(prompt1);
	num2 = getInput(prompt2);	
	cout << endl; // blank line

	if (num1 == 0 && num2 == 0) {
		cout << "No operations performed!" << endl;
	} else {
		// Setting Pointers
		num1ptr = &num1;
		num2ptr = &num2;

		// Conversions and Output
		cout << "Before call to swapArgs a: " << num1 << " b: " << num2 << endl;

		// swapArgs()
		swapArgs(num1ptr, num2ptr);
		cout << "After call to swapArgs a: " << num1 << " b: " << num2 << endl;

		// divideArgs()
		divideArgs(num1ptr, num2ptr);
		cout << "After call to divideArgs a: " << num1 << " b: " << num2 << endl;

		// powerArgs()
		powerArgs(num1ptr, num2ptr);
		cout << "After call to powerArgs a: " << num1 << " b: " << num2 << endl;

		// Final Goodbye
		cout << endl; // blank line
		cout << "Goodbye!" << endl;
	}

	return 0;
}




// Function Definitions
//Name:   getInput()
//Desc:   This function receives integer input from the user and validates it.
//input:  char prompt[]
//output: char prompt[] and an error message
//return: int num
int getInput(char prompt[]) {
	int num = 0;
	cout << prompt;
	cin >> num;
	while (!cin || cin.peek() != '\n') {	
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please enter a valid integer." << endl;
		cout << prompt;
		cin >> num;
	}	
	return num;
}

//Name:   swapArgs()
//Desc:   This function swaps the values of ptr1 and ptr2.
//input:  int *ptr1, int *ptr2
//output: none
//return: none
void swapArgs (int *ptr1, int *ptr2) {
	int temp = 0;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}


//Name:   divideArgs()
//Desc:   This function divides the value of ptr1 by the value of ptr2.
//input:  int *ptr1, int *ptr2
//output: Error message (division by 0)
//return: none
void divideArgs(int *ptr1, int *ptr2) {
	int temp1 = *ptr1;
	int temp2 = *ptr2;
	if (temp2 == 0) {
		cout << "Error: Division by 0. No divison operation executed." << endl;
	} else {
		*ptr1 = temp1/temp2;
		*ptr2 = temp1 % temp2;
	}
}


//Name:   powerArgs()
//Desc:   This function raises the value of ptr1 by the value of ptr2.
//input:  int *ptr1, int *ptr2
//output: none 
//return: none
void powerArgs(int *ptr1, int *ptr2) {
	if (*ptr2 != 0) {
		for (int i = 1; i < *ptr2; ++i) {
			*ptr1 = *ptr1 * *ptr1;
		}
	} else {
		*ptr1 = 1;
	}

}

