// This is the implementation file for tools.h
#include "tools.h"
#include "GameData.h"


//Name:   welcome()
//Desc:   this function displays the welcome message
//input:  none
//output: welcome message
//return: none
void welcome() {
	cout << "Welcome!" << endl;
	cout << "This program gives basic information about various video games released\n"
		<< "over the years. You can add to this data set, print the dataset, find\n"
		<< "the most popular game based on its rank, or quit the program.\n"
		<< endl;
}

//Name:   displayMenu()
//Desc:   this function displays the menu of options
//input:  none
//output: the menu
//return: none
void displayMenu() {
	cout << endl; //blank line
	cout << "Pick an option from below:" << endl;
	cout << endl; //blank line
	cout << "(A)DD" << endl;
	cout << "(R)EMOVE" << endl;
	cout << "(P)RINT" << endl;
	cout << "(F)IND" << endl;
	cout << "(O)LDEST" << endl;
	cout << "(W)RITE OUT" << endl;
	cout << "(Q)UIT" << endl;
	cout << endl; //blank line
}

//Name:   readOption()
//Desc:   this function reads in the user's menu selection
//input:  char &option
//output: error message, call to displayMenu() for menu
//return: none
void readOption(char& option) {
	cin >> option;
	option = tolower(option);
	while (!cin || cin.peek() != '\n' || !(validateOption(option))) {
		cout << "Invalid option!" << endl;
		displayMenu();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> option;
		option = tolower(option);
	}
	cout << endl; //blank line
}

//Name:   validateOption()
//Desc:   this function checks the user input, to ensure that it is any of the valid menu options
//input:  const char option
//output: none
//return: boolean value, true if valid or false if invalid
bool validateOption(const char option) {
	if (isalpha(option) &&
			(option == 'a' || option == 'r' || option == 'p' || option == 'f' ||
			 option == 'o' || option == 'w' || option == 'q')) {
		return true;
	}
	return false;
}

//Name:   exeOption()
//Desc:   This function manages all of the function calls to specific menu options,
//	   based on what the user has selected.
//input:  GameData games[], int &count, const char option, ofstream& outFile
//output: error message, confirmation message (write out), thank you message
//return: int status
int exeOption(GameData games[], int &count, const char option, ofstream& outFile) {
	int status = 0;
	switch (option)
	{
		case 'a':
			addGame(games, count);
			break;
		case 'r':
			removeGame(games, count);
			break;
		case 'p':
			printData(games, count);
			break;
		case 'f':
			findGame(games, count);
			break;
		case 'o':
			findOldest(games, count);
			break;
		case 'w':
			printData(games, count, outFile);
			cout << "Wrote out to output-games.txt." << endl;
			break;
		case 'q':
			cout << "Thank you for using my program!" << endl;
			status = 1;
			break;
		default:
			cout << "Please choose an option from the menu:" << endl;
			displayMenu();
			status = 2;
	}
	return status;
}

//Name:   getInt()
//Desc:   This function receives an integer from the user and validates it
//input:  char prompt[], int count
//output: error message, prompt
//return: int num
int getInt(char prompt[], int count) {
	int num = 0;

	cout << prompt;
	cin >> num;

	while (!cin || cin.peek() != '\n' || num < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, please try again." << endl;
		cout << prompt;
		cin >> num;
	}

	return num;
}

//Name:   toLowerCase()
//Desc:   This function converts a char array to all lowercase letters
//input:  char phrase[]
//output: none
//return: none
void toLowerCase(char phrase[]) {
	for (int i = 0; i < strlen(phrase); i++) {
		phrase[i] = tolower(phrase[i]);
	}
}
