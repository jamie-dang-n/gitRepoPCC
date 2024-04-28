#include "linkedlist.h"

// Default Constructor
LinkedList::LinkedList() : head(nullptr), size(0){}

// Destructor
LinkedList::~LinkedList() {
	destroy(head);
	size = 0;
}

// Public Methods //
// Desc:   function called by the client to add a character 
// 		   to the list. Increments size by 1
// Return: none
void LinkedList::add(char ch) {
	add(head, ch);
	size++;
}

// Desc:   function called by the client to confirm if
// 		   a character exists in the list
// Return: bool success
bool LinkedList::find(char ch) const {
	bool success = false;
	find(head, ch, success);
	return success;
}

// Desc:   function called by the client to delete an entry
// 		   from the list. Decrements size by 1
// Return: bool success
bool LinkedList::del(char ch) {
	bool success = false;
	del(head, nullptr, ch, success);
	if (success) {
		size--;	
	}
	return success;
}

// Desc:   function that is called by the client to print list
// Return: none
void LinkedList::print() const {
	if (head) 
		print(head);	
	else
		cout << "List is empty." << endl;
}

// Private Methods // 
// Desc:   recursive printing, starting from the first node
// Return: none
void LinkedList::print(Node * first) const {
	// Recursive Case: if first is not at the end of the list
	// Base Case: if !first, do nothing
	if (first) {
		cout << first->data << endl; // print first
		print(first->next);
	}	
}

// Desc:   recursive adding, responsible for placing data
// 		   into the linked list, at the end of the list.
// Return: none
void LinkedList::add(Node *& first, int data) {
	// Recursive case: if first is not at the end of the list
	// Base case: If !first (end of list), start appending
	if (!first) { // end of list, append node to end 
		first = new Node;
		first->data = data;
		first->next = nullptr;
	} else { 
		add(first->next, data);
	}
}


// Desc:   helper function, recursively deletes the list 
// Return: none
void LinkedList::destroy(Node * curr) {
	// Recursive case: if the curr is not at the end of the list 
	// Base case: if !curr, do nothing
	if (curr) { 
		destroy(curr->next); // move to the next node
		delete curr; // delete curr at the tail, recursively moving backward
	}
}


// Desc:   helper function to recursively find an entry in the list
// Return: none
void LinkedList::find(Node * first, char ch, bool & success) const{
	// Recursive case: if finding ch was not successful at pointer first
	// Base case: ch was found at pointer first 
	if (first && !success) { // check that first exists before continuing
		if (first->data == ch) {
			success = true; // character was found
		} else {
			find(first->next, ch, success);
		}
	}
}


// Desc:   helper function to recursively find and remove an entry from the list
// Return: none
void LinkedList::del(Node * curr, Node * prev, char ch, bool & success) {
	// Recursive: if ch has not yet been found
	// Base case: ch was found at pointer curr; relink to remove
	if (curr) { // check that we are not accessing an empty pointer
		if (curr->data == ch) {
			success = true;
			// the correct entry was found, start relinking to remove
			if (!prev) { // delete at head
				head = curr->next;
			} else { // delete at end/in middle 
				prev->next = curr->next;
			}
			delete curr;
			curr = NULL;
			prev = NULL;
		} else {
			del(curr->next, curr, ch, success);
		}
	}
}
