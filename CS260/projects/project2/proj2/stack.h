// Author: Jamie Dang
// Date: 5/3/24
// Program Number: CS260 Project 2
// Purpose: Header file for implementing the Stack ADT
// as a class with a dynamically allocated array. The 
// array contains Entry objects.
// Module Name: stack.h (header file for stack.cpp)

#ifndef STACK_H
#define STACK_H

#include "entry.h"

using namespace std;

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
		// Stack data members
		const static int GROWTH_FACTOR = 2;
		int top; // if top == currCapacity - 1, the stack is full
		int currCapacity;
		Entry * stack;

		// Private Methods
		void expand();
};

#endif
