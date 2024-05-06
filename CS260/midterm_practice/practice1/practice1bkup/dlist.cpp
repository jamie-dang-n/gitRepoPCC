#include "dlist.h"

//put the implmenetation of the required functions here
int count(node * head) {
	if (head) {
		return count(head->next) + 1;
	} 
	return 0;
}
void insert(node * & head, int newInt, int position) {
	// use recursion to find the position
	if (position != 0 && head->next) {
		insert(head->next, newInt, position - 1);
	} else {
		// create new node
		node * newNum;
		newNum = new node;
		newNum->data = newInt;
		newNum->previous = nullptr;
		newNum->next = nullptr;
		node * temp = head; // re-point using only temp instead of head
							// to preserve head pointing at the start of the list
		// insert
		if (temp->previous == nullptr) {
			// insert at top
			temp->previous = newNum;
			newNum->next = temp;
			head = newNum;
		} else if (temp->next == nullptr) {
			// insert at end
			newNum->previous = temp;
			temp->next = newNum;
		} else {
			// insert in middle
			newNum->previous = temp->previous;
			newNum->next = temp;
			temp->previous->next = newNum;
			temp->previous = newNum;
		}
	}
}

int remove(node * & head, int position) {
	int delNum = 0;
	// use recursion to find the position
	if (position != 0 && head->next) {
		delNum = remove(head->next, position - 1);
	} else { 
		node * delNode;
		delNode = head;// use delNode to repoint & delete instead of head	
		// to preserve head pointing at the start of the list
		delNum = head->data;
		// remove
		if (delNode->previous == nullptr) {
			// remove first node
			head = head->next;
			head->previous = nullptr;
		} else if (delNode->next == nullptr) {
			// remove last node
			(delNode->previous)->next = nullptr;
		} else {
			// remove node in middle
			delNode->previous->next = delNode->next;
			delNode->next->previous = delNode->previous;
		}
		delNode->next = nullptr;
		delNode->previous = nullptr;
		delete delNode;
		delNode = nullptr;
	}
	return delNum;
}



