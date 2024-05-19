#include "clist.h"

// Iteratively compute and return the number of nodes in the circular linked list.
int count(node * head) {
	int num = 0;
	node * curr = nullptr;

	if (head) {
		num++;
		curr = head->next;
		while (curr != head) {
			num++;
			curr = curr->next;
		}
	}

	return num;
}

// Recursively compute and return the number of nodes in the circular linked list.
int countR(node * head) {
	int num = 0;
	
	// unwrap the circular linked list into a singly linked list
	node * temp = head->next;
	head->next = nullptr;	

	// recurse with the helper function
	num = _countR(temp);

	// put the list back together
	head->next = temp;

	return num;
}

// helper function to count recursively
int _countR(node * head) {
	if (head) {
		// list is not empty -- recurse
		return _countR(head->next) + 1;	
	}
	// list is empty -- this is the base case
	return 0;
}

// Iteratively compute and return the sum of the ints contained in the circular linked list
int sum(node * head) {
	int sum = 0;
	node * curr = nullptr;

	if (head) {
		sum += head->data;
		curr = head->next;
		while (curr != head) {
			sum+= curr->data;
			curr = curr->next;
		}
	}

	return sum;
}

// Recursively compute and return the sum of the ints contained in the circular linked list.
int sumR(node * head) { 
	int sum = 0;

	// unwrap the circular linked list into a singly linked list
	node * temp = head->next;
	head->next = nullptr;	

	// recurse with the helper function
	sum = _sumR(temp);

	// put the list back together
	head->next = temp;

	return sum;
}

// helper function to sum recursively
int _sumR(node * head) {
	if (head) {
		// list is not empty -- recurse
		return _sumR(head->next) + head->data;	
	}
	// list is empty -- this is the base case
	return 0;
}
