// Author: Jamie Dang
// Date: 5/3/24
// Program Number: Project 2
// Purpose: This is the client code to run all 
// the Stack and Queue ADTs as an application to
// keep track of restaurant data.
// Module Name: main.cpp (client code)

#include "main.h"

int main() {
	// Variables
	int option = 0;
	Queue queue;
	Stack stack(2);

	// Welcome message
	welcome();

	// Menu Execution
	do {
		displayMenu();
		option = getInt();
		exeMenu(option, queue, stack);
	} while(option != 6);
	
	return 0;
}




// Function Definitions //



// Menu Display Functions

// Welcome Message
void welcome() {
	cout << "Welcome to the \"Restaurant Queue and Promo Stack Mananger\"!" << endl;
	cout << endl; // blank line
}



// Display Main Menu
void displayMenu() {
	cout << "Select an option:" << endl;
	cout << "(1) Enter a new group (enqueue)" << endl;
	cout << "(2) Seat next group (dequeue)" << endl;
	cout << "(3) Display number in line" << endl;
	cout << "(4) Peek at next group" << endl;
	cout << "(5) [Manager Only] Edit Promotional Data" << endl;
	cout << "(6) Quit" << endl;
}



// Display manager's menu for the stack
void managerMenu() {
	cout << "Select an option:" << endl;
	cout << "(A) Remove Recent Entry" << endl;
	cout << "(B) Display All Entries" << endl;
	cout << "(C) Display Next Entry" << endl;
}


// Operations

// Name: exeMenu
// Purpose: Execute the main menu; access the manager's menu
// Input: const int option, Queue& aQueue, Stack& aStack
// Output: error messages, prompts, confirmations
// Return: none
void exeMenu(const int option, Queue& aQueue, Stack& aStack) {
	Group aGroup;
	cout << endl; // blank line
	switch(option) {
		case 1:
			readGroup(aGroup);
			if (aQueue.enqueue(aGroup)) {
				cout << "Group successfully seated!" << endl;
			} else {
				cout << "Unable to seat group." << endl;
			}
			if (aGroup.getWantPromo()) {
				addStack(aStack);	
				cout << "Group added to promo list!" << endl;
			}
			break;
		case 2:
			if(aQueue.peek(aGroup)) {
				aQueue.dequeue();
				cout << "Group named \"" << aGroup.getName() <<"\" is now seated." << endl;
				cout << "There are " << aQueue.getNum() << " groups left in line." << endl;	
			} else {
				cout << "There are no groups to seat." << endl;
			}	
			break;
		case 3:
			aQueue.display();
			break;
		case 4:
			if (aQueue.peek(aGroup)) {
				cout << aGroup;
			} else {
				cout << "There are no groups to peek at." << endl;
			}
			break;
		case 5:
			exeManager(aStack);
			break;
		case 6:
			cout << "Thank you for using the \"Restaurant Queue and Promo Stack Manager\"!" << endl;
			break;
		default:
			cout << "Error: Invalid value. Please try again." << endl;
			break;
	}	
	cout << endl; // blank line
}



// Name: getInt
// Purpose: Read in and validate an integer
// Input: none
// Output: error message, reprompt
// Return: int num
int getInt() {
	int num;
	cout << ">> ";
	cin >> num;
	while (!cin || cin.peek() != '\n' || num < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Invalid value. Please try again." << endl;
		cout << ">> ";
		cin >> num;
	}	

	return num;
}


// Name: getChar
// Purpose: Read in and validate a character
// Input: const int typeChar -- allows the function
// 		  to be reused for multiple sets of valid chars.
// 		  typeChar acts as an ID number for what set to 
// 		  validate by, which is defined furhter in validChar().
// Output: error message, remprompt
// Return: char aChar
char getChar(const int typeChar) {
	char aChar;
	cout << ">> ";
	cin >> aChar;
	aChar = tolower(aChar);
	while (!validChar(aChar, typeChar) || cin.peek() != '\n' || !cin) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Invalid value. Please try again." << endl;
		cout << ">> ";
		cin >> aChar;
		aChar = tolower(aChar);
	}
	return aChar;
}



// Name: validChar
// Purpose: Helper function to validate a character
// 			based on the integer typeChar, which
// 			denotes what set of valid chars to test by.
// Input: char aChar, const int typeChar
// Output: none
// Return: bool valid
bool validChar(char aChar, const int typeChar) {
	bool valid = false;
	switch (typeChar) {
		case MANAGER_MENU:
			if (aChar == 'a' || aChar == 'b' || aChar == 'c') 
				valid = true;
			break;
		case SEATING:
			if (aChar == 'n' || aChar == 'h' || aChar == 'w')
				valid = true;
			break;
		case PROMO:
			if (aChar == 'y' || aChar == 'n')
				valid = true;
			break;
	}
	return valid;
}



// Name: readGroup
// Purpose: Read in data for a group and return by reference
// Input: Group& returnGroup
// Output: Prompts
// Return: none
void readGroup(Group& returnGroup) {
	char name[MAXCHAR];
	int num = 0;
	char seating;
	char promos;
	bool wantPromo = false;

	// clean up input stream
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Please enter the following information for the new group:" << endl;

	// Read in fullName
	cout << "Name of group: ";		
	cin.getline(name, numeric_limits<streamsize>::max(), '\n');

	// Read in number of people (num)
	cout << "Number of people in group: ";
	num = getInt();

	// Read in seating preferences
	cout << "Enter special seating needs (h for high chair, w for wheel chair, n for none): ";
	seating = getChar(SEATING);

	// read in promo
	cout << "Would you like to receive coupons,other promotional materials? (Y/N): ";
	promos = getChar(PROMO);

	if (promos == 'y') {
		wantPromo = true;
	}

	// set up returnGroup
	returnGroup.setName(name);
	returnGroup.setNum(num);
	returnGroup.setSpecialInfo(seating);
	returnGroup.setWantPromo(wantPromo);	
}



// Name: addStack
// Purpose: Read in data, then push it to the stack
// Input: Stack& returnStack (lets us modify the original stack)
// Output: Prompts for an entry
// Return: none
void addStack(Stack& returnStack) {
	char fullName[MAXCHAR];
	char email[MAXCHAR];

	// clean up input stream
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter your full name: ";
	cin.getline(fullName, numeric_limits<streamsize>::max(), '\n');
	cout << "Enter your email address: ";
	cin.getline(email, numeric_limits<streamsize>::max(), '\n');

	returnStack.push(fullName, email);
}



// Name: exeManager
// Purpose: Execute manager's menu (for the stack)
// Input: Stack& aStack
// Output: Confirmation of operations
// Return: none
void exeManager(Stack& aStack) {
	managerMenu();
	Entry anEntry;
	char option = getChar(MANAGER_MENU);
	cout << endl; // blank line
	switch(option) {
		case 'a':
			if(!aStack.isEmpty()) {
				saveToFile(aStack, "promos.txt");
				if (aStack.pop())
					cout << "Entry successfully removed." << endl;
			} else {
				cout << "Pop not successful." << endl;
			}
			break;
		case 'b':
			aStack.display();	
			break;
		case 'c':
			if (aStack.peek(anEntry)) {
				cout << anEntry;
			} else {
				cout << "There are no entries to peek at." << endl;
			}
			break;
		default:
			cout << "Error: Invalid value. Please try again." << endl; 
			break;
	}
}



// Name: saveToFile
// Purpose: Saves stack data to fileName.txt before popping
// Input: Stack& aStack, const char fileName[]
// Output: confirmation of operations
// Return: bool success
bool saveToFile(Stack& aStack, const char fileName[]) {
	bool success = false;
	Entry anEntry;
	ofstream out;
	out.open(fileName, ios_base::app);
	if (!out) {
		cout << "Unable to open output file. Stack data not saved." << endl;
	} else {
		aStack.peek(anEntry);
		out << anEntry << endl;
		cout << "Stack data successfully saved to " << fileName << "." << endl;
		success = true;
	}
	out.close();
	return success;
}
