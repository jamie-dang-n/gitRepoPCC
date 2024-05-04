// Author: Jamie Dang
// Date: 5/3/24
// Program Number: Project 2
// Purpose: Implementation file for queue methods,
// using a circular linked list and Nodes holding
// Group objects as data. rear->next holds the front of 
// the queue, whereas rear holds the back of the queue.
// Module Name: queue.cpp (implementation file for queue.h)

#include "queue.h"

// Default Constructor
Queue::Queue() : rear(nullptr), numGroups(0) {
}

// Destructor
Queue::~Queue() {
	Node * front = nullptr;
	Node * curr = nullptr;
	if (!isEmpty()) {
		front = rear->next;
		curr = front;
		rear->next = nullptr; // break into singly linked list
		while (curr) {
			front = curr->next;
			delete curr;
			curr = front;
		}
	}
	numGroups = 0;
}




// Public Methods // 


// Name: isEmpty
// Purpose: Check if queue is empty
// Input: none
// Output: none
// Return: boolean value from rear == nullptr
bool Queue::isEmpty() {
	return (rear == nullptr); // if rear == nullptr, the queue is empty
}


// Name: getNum
// Purpose: Returns number of groups in the queue
// Input: none
// Output: none
// return: int numGroups
int Queue::getNum() {
	return numGroups;
}




// Name: enqueue 
// Purpose: adds a group to the end of the circular
// 			linked list (the queue).
// Input: const Group& aGroup -> group to insert
// Output: none
// Return: bool success
bool Queue::enqueue(const Group& aGroup) {
	bool success = false;
	// Create the new node
	Node * newNode = new Node(aGroup);
	Node * front = nullptr;
	// Insert the new node
	if (isEmpty()) {
		// Inserting into empty list
		rear = newNode;
		rear->next = rear;	
		success = true;
		numGroups++;
	} else {
		// inserting into list with data
		front = rear->next;
		rear->next = newNode;
		rear = newNode;
		rear->next = front;
		success = true;
		numGroups++;
	}
	front = nullptr;
	return success;
}




// Name: dequeue 
// Purpose: removes the entry at the front of the queue
// Input: none
// Output: none
// Return: bool success
bool Queue::dequeue() {
	bool success = false;
	Node * front = nullptr;
	Node * toDelete = nullptr;
	// Check that the list is not already empty
	if (!isEmpty()) {
		front = rear->next;
		if (front == rear) { // only one node in the list
			rear->next = nullptr;
			delete rear;
			rear = nullptr;
		} else { // multiple nodes in list
			toDelete = front;
			front = front->next;
			rear->next = front;
			toDelete->next = nullptr;
			delete toDelete;
		}
		success = true;
		numGroups--;
	}
	toDelete = nullptr;
	front = nullptr;
	return success;	
}



// Name: peek 
// Purpose: returns the entry at the front of the queue
// Input: none
// Output: none
// Return: bool success
bool Queue::peek(Group& returnGroup) {
	bool success = false;
	if (!isEmpty()) {
		returnGroup = (rear->next)->data;
		success = true;
	}
	return success;
}



// Name: display 
// Purpose: displays the entire queue
// Input: none
// Output: the entire queue and the number of people in line
// Return: none
void Queue::display() {
	Node * curr = nullptr;
	int i = 0;
	if (!isEmpty()) {   
		curr = rear->next;
		cout << "There's " << numGroups << " group(s) in line." << endl;
		while (curr && i < numGroups) {
			cout << i + 1 << ". ";
			cout << curr->data;
			curr = curr->next;
			i++;
		}	
	} else {
		cout << "There's 0 group(s) in line." << endl;
	}
}
