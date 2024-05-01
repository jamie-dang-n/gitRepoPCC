#ifndef STACK_H
#define STACK_H

#include "entry.h"

class Stack {
	public:
		// Constructors and Destructor
		Stack();
		Stack(int);
		~Stack();

		// Public Operations
		bool isEmpty() const;
		bool pop();
		void push(const char * clientName, const char * clientEmail);
		bool peek(Entry& returnEntry) const;
		void display();
	private:
		const static int GROWTH_FACTOR = 2;
		int top; // if top == currCapacity - 1, the stack is full
		int currCapacity;
		Entry * stack;

		// Private Methods
		void expand();
};

#endif
