// Author: Jamie Dang
// Date: 5/3/24
// Program Number: CS260 Project 2
// Purpose: Implementation file for stack class,
// using dynamically allocated arrays and Entry
// objects as the elements in the array.
// Module Name: stack.cpp (implementation file for stack.h)

#include "stack.h"

// Default Constructor
Stack::Stack() : top(-1), stack(nullptr) {
}



// Parameterized Constructor - initializes size
Stack::Stack(int initSize) {
	currCapacity = initSize;
	stack = new Entry[currCapacity];
	top = -1;
}




// Destructor
Stack::~Stack() {
	if (stack) {
		delete[] stack;
	}
	stack = nullptr;
}




// Public Operations // 

// Name: loadFromFile
// Purpose: load data into stack from fileName.txt
// Input: const char * fileName
// Output: none
// Return: none
void Stack::loadFromFile(const char * fileName){ 
	ifstream inFile; // insert from file

	// Data members to fill from inFile
	char name[MAX_CHAR];
	char email[MAX_CHAR];

	// Open data file to read in
	inFile.open(fileName);
	if (!inFile) {
		cerr<< "Error: Could not open the input file. Program terminating." << endl;
		exit(1);
	}

	// Ignore header row
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');
	
	// Input loop from file
	inFile.getline(name, MAX_CHAR, ';');
	while(!inFile.eof()) {
		inFile.getline(email, MAX_CHAR, '\n');
		
		// add song
		push(name, email);

		// continue reading loop
		inFile.getline(name, MAX_CHAR, ';');
	}

	inFile.close();
}

// Name: isEmpty
// Purpose: Checks if stack is empty
// Input: none
// Output: none
// Return: none
bool Stack::isEmpty() const {
	return top < 0;
}



// Name: pop
// Purpose: removes an entry from the top of the stack
// Input: none
// Output: none
// Return: bool success
bool Stack::pop() {
	bool success = false;
	if (!isEmpty()) {
		top--; // decrement top to remove from the top of the stack
		success = true;
	}
	return success;
}



// Name: push
// Purpose: adds an entry to the top of the stack
// Input: const char * clientName and clientEmail
// Output: none
// Return: none
void Stack::push(const char * clientName, const char * clientEmail) {
	Entry newEntry(clientName, clientEmail);
	if (top == (currCapacity - 1)) { // expand array if full
		expand();
	}

	// push to top of the array
	top++;
	stack[top] = newEntry;
}



// Name: peek 
// Purpose: returns the top entry of the stack
// Input: Entry& returnEntry-- used to return 
// 		  the entry at the top of the stack
// Output: none
// Return: bool success
bool Stack::peek(Entry& returnEntry) const {
	bool success = false;
	if (!(isEmpty())) {
		success = true;
		returnEntry = stack[top];
	}
	return success;
}



// Name: display 
// Purpose: displays the entire stack.
// Input: none
// Output: the entire stack
// Return: none
void Stack::display() {
	int j = 0;
	if (!isEmpty()) {
		cout << "There are " << top + 1 << " entries." << endl;
		for (int i = top; i >= 0; i--) {
			cout << j + 1 << ". ";
			cout << stack[i].getFullName() << "; " << stack[i].getEmail() << endl;
			j++;
		}	
	} else {
		cout << "No entries to display." << endl;
	}
}



// Private Methods //


// Name: expand
// Purpose: expand should be called ONLY 
// 			when the array is full and must 
// 			be grown. Expand function will 
// 			grow the stack by allocating a 
// 			new, larger dynamic array of entries.
// Input: none
// Output: none
// Return: none
void Stack::expand() {
	// note: top holds the index of the position AFTER the last item in the array
	currCapacity *= GROWTH_FACTOR;
	
	// Allocate new dynamic array
	Entry * tempStack = new Entry[currCapacity];
	
	// Copy everything
	for (int i = 0; i < top + 1; i++) {
		tempStack[i] = stack[i];
	}	

	// deallocate the stack
	delete[] stack;

	stack = tempStack;
}

