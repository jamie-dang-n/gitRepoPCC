#include "stack.h"

// Default Constructor
Stack::Stack() : top(-1), stack(nullptr) {
}



// Parameterized Constructor
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



// Checks if stack is empty
bool Stack::isEmpty() const {
	return top < 0;
}



//  Pop function removes an entry from the top of the stack
bool Stack::pop() {
	bool success = false;
	if (!isEmpty()) {
		top--; // decrement top to remove from the top of the stack
		success = true;
	}
	return success;
}



// Push function adds an entry to the top of the stack
void Stack::push(const char * clientName, const char * clientEmail) {
	Entry newEntry(clientName, clientEmail);
	if (top == (currCapacity - 1)) { // expand array if full
		expand();
	}

	// push to top of the array
	top++;
	stack[top] = newEntry;
}



// Peek function returns the top entry of the stack
bool Stack::peek(Entry& returnEntry) const {
	bool success = false;
	if (!(isEmpty())) {
		success = true;
		returnEntry = stack[top];
	}
	return success;
}



// Display function displays the entire stack.
void Stack::display() {
	if (!isEmpty()) {
		cout << "There are " << top + 1 << " entries." << endl;
		for (int i = 0; i < top + 1; i++) {
			cout << i + 1 << ". ";
			cout << stack[i].getFullName() << "; " << stack[i].getEmail() << endl;
		}	
	} else {
		cout << "No entries to display." << endl;
	}
}



// Private Method // 
// Expand should be called ONLY when the array is full and must be grown
// Expand function will grow the stack by allocating a new, larger dynamic array
// of entries.
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

