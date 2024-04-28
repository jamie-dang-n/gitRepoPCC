/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Assignment 2
# Date:             4/13/23
# Description:      This program encodes a user’s information into a file name for D2L. 
#                   The encoded file name is based on the user’s first/last name, student 
#                   ID, whether they were late or not, the time the file was submitted 
#                   (in military time) and the name of the file they are submitting to class.
# Input:            char lastName[], firstName[], userID[], userFile[];
#                   char menuChoice; int hour, min
# Output:           char encodedName[]
# Sources:          ZyBooks, GD Iyer's Code Examples
#******************************************************************************/
#include <cstring>
#include <iostream>
#include <limits> // for cin.ignore

using namespace std;

// Constants
const int MAXCHAR = 101;
const char ERROR[MAXCHAR] = "Invalid option! Please try again!!";
const char USER_INDICATOR[4] = ">> ";

// Function Prototypes
void welcome();
void goodbye();
char displayMenu();
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool& lateFlag);
void readInput(char parsedID[], char fileName[]);
void readTime(char strTime[]);
void charToLower(char charWord[]);
bool validateID(char userID[]);
bool validateNames(char charName[]);


// Main
int main(){
	// Variables
	char menuChoice;
	char fileToEncode[MAXCHAR];

	// Welcome Message
	welcome();

	// User Input/Calculations
	menuChoice = displayMenu();
	while (menuChoice != 'q') {
		encode(fileToEncode);
		cout << endl; // blank line
		cout << "Your encoded file name is: " << fileToEncode << endl;
		cout << endl; // blank line
		menuChoice = displayMenu();
	}

	// Goodbye Message
	goodbye();

	return 0;
}

// Function Definitions

//Name:   welcome()
//Desc:   This function prints a welcome message
//input:  None
//output: welcome message
//return: None
void welcome() {
	cout << "Welcome to my fileName encoding program!" << endl;
	cout << endl; // blank line
}

//Name:   goodbye()
//Desc:   This function prints the thank you/goodbye message
//input:  None
//output: goodbye message
//return: None
void goodbye() {
	cout << endl; // blank line
	cout << "Thank you for using my fileName generator!" << endl;
}

//Name:   encode()   
//Desc:   This function encodes the given file name.
//input:  char encodeFileName[]
//output: none
//return: none
void encode(char encodeFileName[]) {
	bool lateFlag;
	char lastName[MAXCHAR] = {0};
	char firstName[MAXCHAR] = {0};
	char userID[MAXCHAR] = {0};
	char userFile[MAXCHAR] = {0};
	char userTime[MAXCHAR] = {0};

	cout << "This program will ask you a few questions and generate an" 
	     << "\nencoded fileName based on your answers." << endl;
	readInput(firstName, lastName, lateFlag);
	readInput(userID, userFile);
	readTime(userTime);

	strcpy(encodeFileName, lastName);
	strcat(encodeFileName, "_");
	strcat(encodeFileName, firstName);
	strcat(encodeFileName, "_");

	if (lateFlag) {
		strcat(encodeFileName, "LATE");
		strcat(encodeFileName, "_");
	}

	strcat(encodeFileName, userID);
	strcat(encodeFileName, "_");
	strcat(encodeFileName, userTime);
	strcat(encodeFileName, "_");
	strcat(encodeFileName, userFile);


}

//Name:   displayMenu()
//Desc:   This function displays the menu and reads the user's choice
//input:  none
//output: the options menu
//return: char choice
char displayMenu() {
	char choice = 0;
	cout << "Please pick an option below: " << endl;
	cout << "(e)Encode a file name" << endl;
	cout << "(q)quit" << endl;
	cout << USER_INDICATOR;
	cin >> choice;
	choice = tolower(choice);
	while (!cin || cin.peek() != '\n' || (choice != 'q' && choice != 'e')) {
		cout << ERROR << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please pick an option below: " << endl;
		cout << "(e)Encode a file name" << endl;
		cout << "(q)quit" << endl;
		cout << USER_INDICATOR << " ";
		cin >> choice;
	}
	return choice;

}

//Name:   readInput(char fName[], lName[], bool& lateFlag) - overloaded
//Desc:   This function reads in the user's name and stores
//        a boolean indicating assignment lateness.
//input:  char yesOrNo, char lName[], char fName[]
//output: prompts for name and lateness
//return: none
void readInput(char fName[], char lName[], bool& lateFlag) {
	char yesOrNo;

	cout << endl; // blank line
	cout << "Enter your last name: ";
	cin >> lName;
	charToLower(lName);
	while (!cin || cin.peek() != '\n' || !validateNames(lName)) {
		cout << ERROR << endl;
		cout << "Enter your last name: ";
		cin >> lName;
		charToLower(lName);
	}	

	cout << endl; // blank line
	cout << "Enter your first name: ";
	cin >> fName;
	charToLower(fName);
	while (!cin || cin.peek() != '\n' || !validateNames(fName)) {
		cout << ERROR << endl;
		cout << "Enter your first name: ";
		cin >> fName;
		charToLower(fName);
	}

	cout << endl; // blank line
	cout << "Was your assignment late (y/n)?: ";
	cin >> yesOrNo;
	yesOrNo = tolower(yesOrNo);
	while (!cin || cin.peek() != '\n' || (yesOrNo != 'n' && yesOrNo != 'y')) {
		cout << ERROR << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Was your assignment late (y/n)?: ";
		cin >> yesOrNo;
		yesOrNo = tolower(yesOrNo);
	}

	cout << endl; // blank line

	if (yesOrNo == 'y') {
		lateFlag = true;
	} else {
		lateFlag = false;
	}
}

//Name:   readInput(char parsedID[], charfileName[]) - overloaded
//Desc:   This function reads in the user's student ID, parses it,
//        and stores it to parsedID[]. It also reads the user's
//        file name.
//input:  char userID[], char fileName[]
//output: prompt for ID/File name
//return: none
void readInput(char parsedID[], char fileName[]) {
	char userID[MAXCHAR] = {0};
	cout << "Enter your Student-ID (format: 222-22-2222): ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(userID, MAXCHAR);
	while (!validateID(userID) || !cin) {
		cout << ERROR << endl;
		cin.clear();
		cout << "Enter your Student-ID (format: 222-22-2222): ";
		cin.getline(userID, MAXCHAR);
	}

	cout << endl; // blank line
	strncpy(parsedID, userID + 7, 5);
	cout << "Enter the file name: ";
	cin >> fileName;
	cout << endl; // blank line
}

//Name:   readTime()
//Desc:   This function reads in the user's time of submission
//        in military time form.
//input:  int hour, min, and char formatCheck
//output: none
//return: none
void readTime(char strTime[]) {	
	int hour = 0, min = 0;
	char formatCheck;
	cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
	cin >> hour >> formatCheck >> min;
	while (!cin || cin.peek() != '\n' || formatCheck != ':' || (hour < 0 || hour > 24) || (min < 0 || min > 60)) {
		cout << ERROR << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
		cin >> hour >> formatCheck >> min;
	} 

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore remaining newlines
	strcpy(strTime, to_string(hour).c_str());
	strcat(strTime, to_string(min).c_str());
}

//Name:   charToLower()
//Desc:   This function takes a char array and converts it to lowercase
//input:  char charWord[]
//output: none
//return: none
void charToLower(char charWord[]) {
	int strLength = strlen(charWord);
	for (int i = 0; i < strLength; i++) {
		if (isalpha(charWord[i])) {
			charWord[i] = tolower(charWord[i]);
		}
	}
}

//Name:   validateNames()
//Desc:   This function takes a char array and validates it for student names
//input:  char charName[]
//output: none
//return: bool isValid
bool validateNames(char charName[]) {
	int strLength = (strlen(charName));
	int numInvalid = 0;
	bool isValid = true;
	for (int i = 0; i < strLength; i++) {
		if (!isalpha(charName[i])) {
			numInvalid++;
		}
	}
	if (numInvalid != 0) {
		isValid = false;
	}
	return isValid;
}

//Name:   validateID()
//Desc:   This function validates the user's student ID
//input:  char userID[]
//output: prompt for ID
//return: bool isValid
bool validateID(char userID[]) {
	int strLength = strlen(userID);
	bool validPunct = true;
	bool validNum = true;
	bool validLength = true;
	bool isValid = false;
	if (strLength > 11 || strLength < 11) {
		validLength = false;
	} else {
		for (int i = 0; i < strLength; ++i) {
			if (i == 3) {
				validPunct = ispunct(userID[i]); // check first dash
			} else if (i == 6 && validPunct == true) {
				//validPunct = ispunct(userID[i]); // check second dash
				validPunct = (userID[i] == '-');
			} else {
				validNum = isdigit(userID[i]);   // check all digits
			}
		}
	}  
	if (validPunct && validNum && validLength) {
		isValid = true;
	}
	return isValid;
}
