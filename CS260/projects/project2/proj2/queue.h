#ifndef QUEUE_H
#define QUEUE_H

#include "group.h"


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

	private:
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
