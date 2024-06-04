#include "dlist.h"

//put the implmenetation of the required functions here

//Recursively compute and return the sum of data in nodes that contains even
//numbers in the doubly linked list
int sumEven(node * head) {
	 if (head) {
		// list is not empty; check the data at head
		if (head->data % 2 == 0) {
			// if the condition is true, the number is even
			// recurse and increment count by 1
			return sumEven(head->next) + 1; 
		} else {
			return sumEven(head->next); // recurse without incrementing
		}
	 }
	 // outside the if block, the list is empty; this is the base case
	 return 0;	
}

//Recursively adds a node that contains -1 in data after every node that contains even
//number and return the number of nodes tagged. E.g if a list contains 2, 9, 4, 7, 10,
//after tagEven is invoked, the list will look like 2, -1, 9, 4, -1, 7, 10, -1
int tagEven(node *& head) {
	if (head) {
		// list is not empty; check the data at head
		if (head->data % 2 == 0) {
			// if the condition is true, the number is even
			// call insert function
			insert(head);

			// recurse to next value, incrementing by 1 to represent the tag
			return tagEven(head->next) + 1;
		} else {
			return tagEven(head->next); // recurse without incrementing
		}
	}
	// outside the if block, the list is empty; this is the case case
	return 0;
}


// Helper function to insert (-1) after an even number in the doubly linked list
void insert(node * & insert) {
	// insert is the position at which to insert

	// temporary pointers to facilitate insertion
	node * pos = insert;
	node * nextNode = pos->next;

	// create the (-1) node
	node * newNode = new node;
	newNode->data = -1;
	newNode->previous = nullptr;
	newNode->next = nullptr;	
	
	// start insertion-- we will only be inserting in the middle or end
	if (nextNode) {
		// inserting in the middle
		pos->next = newNode;
		nextNode->previous = newNode;
		newNode->previous = pos;
		newNode->next = nextNode;
	} else {
		// inserting in end
		pos->next = newNode;
		newNode->previous = pos;
	}
	newNode = nullptr;
}
