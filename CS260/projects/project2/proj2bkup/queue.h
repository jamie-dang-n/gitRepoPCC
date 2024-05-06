// Author: Jamie Dang
// Date: 5/3/24
// Program Number: CS260 Project 2
// Purpose: header file to define queue ADT in terms of 
// a circular lnked list. The class implements the ADT
// with a circular linked list of Group objects.
// Module Name: queue.h (header file for queue.cpp)

#ifndef QUEUE_H
#define QUEUE_H

#include "group.h"
#include <fstream>
#include <limits>
#include <cstring>

class Queue {
	public:
		// Constructors and Destructors
		Queue();
		~Queue();

		// Public Methods
		bool enqueue(const Group& aGroup);
		bool dequeue();
		bool peek(Group& returnGroup);
		void display();
		bool isEmpty();
		int getNum();
		void loadFromFile(const char * fileName);
	private:
		// Constants
		const static int MAX_CHAR = 101;

		// Queue data members
		struct Node {
			Node * next;
			Group data;
			// Node Constructor
			Node (const Group& aGroup) {
				data = aGroup;
				next = nullptr;
			}	
		};
		Node * rear;
		int numGroups;
};


#endif
