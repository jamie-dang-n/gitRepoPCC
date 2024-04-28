#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <iostream>
#include <ostream>

using namespace std;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	// Public Member Functions/Client Interface
	void add(char ch);
	bool find(char ch) const;
	bool del(char ch);
	void print() const;
private:
	struct Node {
		// Node Data Members
		char data;
		Node * next;
	};
	// Private Recursive Methods
	void print(Node * first) const; // recursive print
	void add(Node *& first, int data); // recursive add
	void destroy(Node * curr); // recursive destroy
	void find(Node * first, char ch, bool & success) const; // recursive find
	void del(Node * curr, Node * prev, char ch, bool & success); // recursive delete
	// List Data Members
	Node * head;
	int size;
};

#endif // _LINKED_LIST_
