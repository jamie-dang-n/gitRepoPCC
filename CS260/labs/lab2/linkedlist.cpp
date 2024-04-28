#include "linkedlist.h"
// Implementation for the member functions of the LinkedList class (linkedlist.h)

//Default Constructor
LinkedList::LinkedList() {
	size = 0;
	head = NULL;
	tail = NULL;
}

// Destructor
LinkedList::~LinkedList() {
	// Delete List
	Node *curr = head;
	while (curr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
	tail = NULL;
}

// Add characters ot the list
void LinkedList::add (char ch) {
	Node *newNode = NULL;

	// Populate newNode
	newNode = new Node;
	newNode->data = ch; // idk if this is the right idea lol, FIXME	
	newNode->next = NULL;
	
	// Check if list is empty
	if (!head) {
		head = newNode;
		tail = newNode;
	} else {
		// append to the end of the list
		tail->next = newNode;
		newNode->next = NULL;
		tail = tail->next;
	}
	size++;
}

// Find characters in the list
bool LinkedList::find (char ch) {
	bool found = false;
	Node * curr = head;
	while (curr && !found) {
		if (curr->data == ch) {
			found = true;
		}
		curr = curr->next;
	}
	return found;
}

// Delete characters in the list
bool LinkedList::del (char ch) {
	bool successfulDel = false;
	Node *prev = NULL, *curr = head;
	int idx = 0;
	if (size != 0) {
		// the list is not empty	
		while (curr && idx < size && (curr->data != ch)) {
			prev = curr;
			curr = curr->next;
			idx++;
		}
		
		// now remove at curr
		if (!prev) {
			// removal at start
			head = curr->next;
		} else if (curr == tail) {
			// removal at end
			prev->next = curr->next;
			tail = prev;
		} else {
			// removal in middle
			prev->next = curr->next;
		}
		delete curr;
		curr = NULL;
		prev = NULL;
		size--;
		successfulDel = true;
	}
	return successfulDel;
}

// Print the list
void LinkedList::print() {
	for (Node *curr = head; curr; curr = curr->next) {
		cout << curr->data << endl;
	}
}


