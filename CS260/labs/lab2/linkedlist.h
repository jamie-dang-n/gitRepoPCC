#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <iostream>
#include <cstring>

using namespace std;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);
	void print();


private:
	//fill in your code here
	struct Node {
		char data;
		Node * next;
	};
	Node * head;
	Node * tail;
	int size;
};

#endif // _LINKED_LIST_
