// Author: Jamie Dang
// Date: 
// Program Number:
// Purpose: this is the client code to run the website topic tracker, 
// 
//
// Module name: main.cpp

#include "main.h"

int main() {
	BST aTree;	
	int option = 0;
	int numFound = 0;
	Website sites[NUM_SITES];

	aTree.loadFromFile("data.txt");	// prepopulate the table
	
	welcome();
	do {
		displayMenu();
		option = getInt(MENU_OPTIONS);
		cout << endl; // blank line
		exeMenu(option, aTree, sites, numFound);
	} while (option != 7);

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
	cout << "(1) Add a new website by keyword" << endl;
	cout << "(2) Remove a website based on a keyword (one match)" << endl;
	cout << "(3) Remove all websites with a topic (all matches)" << endl;
	cout << "(4) Retrieve a site (based on keyword)" << endl;
	cout << "(5) Display all websites alphabetically" << endl;
	cout << "(6) Monitor tree height" << endl;
	cout << "(7) Quit" << endl;
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
			if (num < 1 || num > 7) {
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
void exeMenu(int option, BST& aTree, Website sites[], int & numFound) {
	switch(option) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			/*
			if (exeRemoveTopic(aTree)) {
				cout << "Removal successful." << endl;
			} else {
				cout << "Removal not successful." << endl;
			}
			*/
			break;
		case 5:
			aTree.display();
			break;
		case 6:
			break;
		case 7:
			cout << "Thank you for using this program!" << endl;
			break;
		default:
			cout << "Error: Invalid entry. Please try again." << endl;
			break;
	}
}

bool exeRemoveTopic(BST& aTree) {
	char topic[MAX_CHAR];
	cout << "Enter a topic: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear out input stream
	cin.getline(topic, MAX_CHAR, '\n');
	return aTree.removeTopic(topic);
}

/*
// Name: 	exeEdit
// Purpose: receives user input, then executes the edit public method for the Table object
void exeEdit(BST& aTree) {
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
	if (aTree.edit(topic, address, newReview, newRating)) {
		cout << "Entry successfully edited. Updated table:" << endl;
		aTree.display();
	} else {
		cout << "Unable to edit entry because a match was not found. "
		   	 << "Please try again and double-check your topic and website address." << endl;
	}
}



// Name: 	exeAdd
// Purpose: receives user input, creates a new website, then adds it to the 
// 			table object using the add public method 
void exeAdd(BST& aTree) {
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
	aTree.add(aSite);
}



// Name: 	exeDisplayTopic
// Purpose: receives user input for a topic, then executes the public displayTopic 
// 			function from the Table object.
void exeDisplayTopic(BST& aTree) {
	char topic[MAX_CHAR] = {'\0'};
	cout << "Enter a topic: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear out input stream
	cin.getline(topic, MAX_CHAR, '\n');
	if (!aTree.displayTopic(topic)) {
		cout << "The topic \"" << topic << "\" was not found." << endl;
	}
}




// Name: 	exeRetrieve
// Purpose: receives user input, then calls the Table object's public retrieve method to save
// 			all matching entries to the sites array.
void exeRetrieve(BST& aTree, Website sites[], int & numFound) {
	char topic[MAX_CHAR] = {'\0'};
	numFound = 0;
	cout << "Enter a topic to retrieve: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear out input stream
	cin.getline(topic, MAX_CHAR, '\n');
	if (!aTree.retrieve(topic, sites, numFound)) {
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
*/