#include "queue.h"

// Constructor and Destructor
Queue::Queue() : rear(nullptr), numGroups(0) {
}

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



// Check if queue is empty
bool Queue::isEmpty() {
	return (rear == nullptr); // if rear == nullptr, the queue is empty
}



// Returns number of groups in queue
int Queue::getNum() {
	return numGroups;
}




// Enqueue function adds a group to the end of the circular
// linked list (the queue)
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




// Dequeue function removes the entry at the front of the queue
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



// Peek function returns the entry at the front of the queue
bool Queue::peek(Group& returnGroup) {
	bool success = false;
	if (!isEmpty()) {
		returnGroup = (rear->next)->data;
		success = true;
	}
	return success;
}



// Display function displays the entire queue
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
