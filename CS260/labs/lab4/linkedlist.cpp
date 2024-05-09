#include "linkedlist.h"

// Default Constructor
LinkedList::LinkedList() : head(nullptr){}

// Destructor
LinkedList::~LinkedList() {
	Node * curr = head;
	while (curr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
	head = nullptr;
	curr = nullptr;
}

// add items to the end of the linked list (iteratively)
void LinkedList::add(int value) {
	Node * curr = head;
	Node * newNode = new Node(value);
	if (head) {
		// list is not empty; traverse to the end and insert
		while (curr->next != nullptr) { 
			curr = curr->next;
		}
		// exit while loop-- we're at the end of the linked list
		curr->next = newNode;
	} else {
		// list is empty
		head = newNode;
	}
}

// sum of ints in list, calculated iteratively
int LinkedList::sum() {
	Node * curr = head;
	int sum = 0;
	while (curr) {
		sum += curr->value;
		curr = curr->next;
	}
	return sum;
}

// Public function -> sum of ints in list, calculated recursively
int LinkedList::sumR() {
	return _sumR(head);
}

// Private helper function for sumR() (recursive sum)
int LinkedList::_sumR(Node * node) {
	if (node) {
		return _sumR(node->next) + node->value;
	}
	return 0;
}
