// Author: Jamie Dang
// Date: 5/14/2024
// Program Number: CS260 Project 3
// Purpose: this is the client code to run the website topic tracker, 
// 			using a hash table to implement the table ADT. Each entry 
// 			is a Website object.
// Module name: main.cpp

#include "main.h"

int main() {
	// variables
	int option = 0;
	Website sites[NUM_SITES];
	int numFound = 0;
	Table aTable;

	aTable.loadFromFile("data.txt"); // prepopulate the table
	
	welcome();
	do {
		displayMenu();
		option = getInt(MENU_OPTIONS);
		cout << endl; // blank line
		exeMenu(option, aTable, sites, numFound);
	} while (option != 8);

	return 0;
}



// **** Function Definitions

// Display Functions

// Welcome Message
void welcome() {
	cout << "Welcome to the \"Website Topic Tracker\"!" << endl;
}

// Menu Display
void displayMenu() {
	cout << "\nPlease choose an option:\n" << endl;
	cout << "(1) Add a new website by topic" << endl;
	cout << "(2) Retrieve based on topic keyword" << endl;
	cout << "(3) Edit a website's reviews and ratings" << endl;
	cout << "(4) Remove all websites with a 1 star rating" << endl;
	cout << "(5) Display based on topic keyword" << endl;
	cout << "(6) Display all websites" << endl;
	cout << "(7) Monitor hashing performance" << endl;
	cout << "(8) Quit" << endl;
}



// Name: 	getInt
// Purpose: receive an integer from the user, checks the validity based on
// 			const int id. returns the integer after receiving valid input.
int getInt(const int id) {
	int num = 0;
	cout << ">> ";
	cin >> num;
	while (!cin || cin.peek() != '\n' || num < 0 || !validInt(id, num)) {
		cout << "Error: Invalid entry. Please try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << ">> ";
		cin >> num;
	}
	return num;
}



// Name: 	validInt
// Purpose: helper function for getInt to validate int num
bool validInt(const int id, int num) {
	bool valid = true;
	switch(id) {
		case MENU_OPTIONS:
			if (num < 1 || num > 8) {
				valid = false;
			}	
			break;
		case RATING_OPTIONS:
			if (num < 1 || num > 5) {
				valid = false;
			}
			break;
		default:
			valid = false;
			break;
	}
	return valid;
}



// Name: 	exeMenu
// Purpose: executes all menu options with Table public methods and helper functions
void exeMenu(int option, Table& aTable, Website sites[], int & numFound) {
	switch(option) {
		case 1:
			exeAdd(aTable);
			break;
		case 2:
			exeRetrieve(aTable, sites, numFound);
			break;
		case 3:
			exeEdit(aTable);
			break;
		case 4:
			if(aTable.remove()) {
				cout << "Removal successful. Updated table:" << endl;
				aTable.display();
			} else {
				cout << "Removal not successful. There may have been no ratings of value 1." << endl;
			}
			break;
		case 5:
			exeDisplayTopic(aTable);			
			break;
		case 6:
			aTable.display();
			break;
		case 7:
			aTable.monitor();
			break;
		case 8:
			cout << "Thank you for using this program!" << endl;
			break;
		default:
			cout << "Error: Invalid entry. Please try again." << endl;
			break;
	}
}



// Name: 	exeEdit
// Purpose: receives user input, then executes the edit public method for the Table object
void exeEdit(Table& aTable) {
	// Variables to read into
	char topic[MAX_CHAR] = {'\0'};
	char address[MAX_CHAR] = {'\0'};
	char newReview[MAX_CHAR] = {'\0'};
	int newRating = -1;

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear out input stream

	// Get user input
	cout << "Enter the website's topic: ";
	cin.getline(topic, MAX_CHAR, '\n');

	cout << "Enter the website's address: ";
	cin.getline(address, MAX_CHAR, '\n');

	cout << "Enter your new review: ";
	cin.getline(newReview, MAX_CHAR, '\n');

	cout << "Enter your rating for this website: ";
	newRating = getInt(RATING_OPTIONS);

	// edit the entry
	if (aTable.edit(topic, address, newReview, newRating)) {
		cout << "Entry successfully edited. Updated table:" << endl;
		aTable.display();
	} else {
		cout << "Unable to edit entry because a match was not found. "
		   	 << "Please try again and double-check your topic and website address." << endl;
	}
}



// Name: 	exeAdd
// Purpose: receives user input, creates a new website, then adds it to the 
// 			table object using the add public method 
void exeAdd(Table& aTable) {
	// Data members to read into
	char topic[MAX_CHAR] = {'\0'};
	char address[MAX_CHAR] = {'\0'};
	char summary[MAX_CHAR] = {'\0'};
	char review[MAX_CHAR] = {'\0'};
	int rating = -1;

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear out input stream

	// Start input
	cout << "Enter the website's topic: ";
	cin.getline(topic, MAX_CHAR, '\n');

	cout << "Enter the website's address: ";
	cin.getline(address, MAX_CHAR, '\n');

	cout << "Enter the website summary: ";
	cin.getline(summary, MAX_CHAR, '\n');

	cout << "Enter your review of the website: ";
	cin.getline(review, MAX_CHAR, '\n');

	cout << "Enter your rating for this website: ";
	rating = getInt(RATING_OPTIONS);

	// Create the website with the parameterized constructor
	Website aSite(topic, address, summary, review, rating);

	// add site to the table
	aTable.add(aSite);
}



// Name: 	exeDisplayTopic
// Purpose: receives user input for a topic, then executes the public displayTopic 
// 			function from the Table object.
void exeDisplayTopic(Table& aTable) {
	char topic[MAX_CHAR] = {'\0'};
	cout << "Enter a topic: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear out input stream
	cin.getline(topic, MAX_CHAR, '\n');
	if (!aTable.displayTopic(topic)) {
		cout << "The topic \"" << topic << "\" was not found." << endl;
	}
}




// Name: 	exeRetrieve
// Purpose: receives user input, then calls the Table object's public retrieve method to save
// 			all matching entries to the sites array.
void exeRetrieve(Table& aTable, Website sites[], int & numFound) {
	char topic[MAX_CHAR] = {'\0'};
	numFound = 0;
	cout << "Enter a topic to retrieve: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear out input stream
	cin.getline(topic, MAX_CHAR, '\n');
	if (!aTable.retrieve(topic, sites, numFound)) {
		cout << "The topic \"" << topic << "\" was not found and could not be " 
			<< "saved into the array of websites." << endl;
	} else {
		cout << "The topic \"" << topic << "\" has been found. All entries have "
			<< "been saved into the array of websites:" << endl;
		for (int i = 0; i < numFound; i++) {
			cout << sites[i];
		}
	}
}
