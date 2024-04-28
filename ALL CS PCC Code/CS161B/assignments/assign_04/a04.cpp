//*****************************************************************************
// Author:           Jamie Dang
// Assignment:       Assignment 4
// Date:             04/28/2023
// Description:      This program takes user input to populate 2 lists,
// 		     then compares each list to each other to remove the 
// 		     duplicate values in set1[]. 
// Input:            int num in readInput()
// Output:           int set1[], int set2[]
// Sources:          ZyBooks
//*****************************************************************************
#include <limits> // for cin.ignore()
#include <iostream>

using namespace std;

// Constants
const int CAP = 20;

// Function Prototypes
void welcome();
void goodbye();
void readInput(int list[]);
void validateNum(int &num, const char prompt[]);
void insertNum(int list[], int pos, int &count, int num);
void findIntersect(int set1[], int set2[]);
void deleteNum(int list[], int value);
void printList(const int list[]);

// Main
int main(){
	int set1[CAP] = {0};
	int set2[CAP] = {0};

	// Welcome Message
	welcome();

	// Get Input - set1
	cout << "Enter numbers for set 1 on separate lines (-1 to end):" << endl;
	readInput(set1);
	cout << endl; // blank line

	cout << "Your set 1 with " << set1[0] - 1 << " numbers ordered:" << endl;
	printList(set1);
	cout << endl; // blank line

	// Get Input - set2
	cout << "Enter numbers for set 2 on separate lines (-1 to end):" << endl;
	readInput(set2);
	cout << endl; // blank line

	cout << "Your set 2 with " << set2[0] - 1 << " numbers ordered:" << endl;
	printList(set2);
	cout << endl; // blank line

	// Find Intersects and Delete Them
	findIntersect(set1, set2);	

	// Final Output
	cout << "The new sets are:" << endl;
	cout << endl; // blank line
	cout << "Set 1: ";
	printList(set1);
	cout << "Set 2: ";
	printList(set2);
	
	goodbye();
	
	return 0;
}

// Function Definitions

//Name:   welcome()
//Desc:   This function prints the welcome message.
//input:  none
//output: the welcome message
//return: none
void welcome() {
	cout << "Welcome to my Set of Numbers program!!" << endl;
	cout << endl; // blank line
}

// Name:  goodbye()
// Desc:  This function prints the goodbye message.
// input: none
// output: the goodbye message
// return: none
void goodbye() {
	cout << endl; // blank line
	cout << "Thank you for checking our my Set of Numbers program!" << endl; 
}

//Name:   printList()
//Desc:   This function prints the array passed to it.
//input:  const int list[]
//output: each list element
//return: none
void printList(const int list[]) {
	for (int i = 1; i < (list[0]); i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

//Name:   readInput()
//Desc:   This function reads input in from the user, 
//	  populating one array.
//input:  int list[]
//output: input prompt
//return: none
void readInput(int list[]) {
	char prompt[4] = ">> ";
	int num = 0;
	int currPos = 1;
	int insertPos = 0;
	while (num != -1 && currPos < CAP) {
		cout << prompt;
		cin >> num;
		validateNum(num, prompt);
		if (num != -1) {
			insertPos = 0;
			while(list[insertPos] < num && insertPos < currPos) {
				insertPos++;
			}
			insertNum(list, insertPos, currPos, num);
		}
	}
	list[0] = currPos;
}

//Name:   validateNum()
//Desc:   This function validates user input. It checks for 
//	  cin's state and whether num is in the right range.
//input:  int num by reference, const char prompt[]
//output: error message, input prompt
//return: none
void validateNum(int &num, const char prompt[]) {
	while (!cin || cin.peek() != '\n' || (num < 0 && num != -1)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid number! Please try again!" << endl;
		cout << prompt;
		cin >> num;
	}
}

//Name:   insertNum()
//Desc:   This function finds the correct (ascending) position for the 
//	  number the user enters to the list.
//input:  int list[], int pos, int num, int count by reference
//output: none
//return: none
void insertNum(int list[], int pos, int &count, int num) {
	if (count < CAP) {
		for (int i = count; i > pos; i--) {
			list[i] = list[i - 1];
		}
		list[pos] = num;
		count++;
	}
}

//Name:   findIntersect()
//Desc:   This function finds duplicate values in set1 and set2, 
//	  then calls deleteNum() to remove them.
//input:  int set1[], int set2[]
//output: none
//return: none
void findIntersect(int set1[], int set2[]) {
	for (int i = 1; i < set1[0]; i++) {
		for (int j = 1; j < set2[0]; j++) {
			while (set1[i] == set2[j]) {
				deleteNum(set1, i);
			}
		}
	}
}

//Name:   deleteNum()
//Desc:   This function shifts list elements to the left, removing 
//	  a single value.
//input:  int list[], int value
//output: none
//return: none
void deleteNum(int list[], int value) {
	for (int i = value; i < (list[0] - 1); i++) {
		list[i] = list[i + 1];
	}	
	list[0] = list[0] - 1;
	list[list[0]] = 0;
}

