#ifndef QUEUE_H
#define QUEUE_H
#include "student.h"
#include <fstream>

class Queue 
{
public:
	Queue();
	Queue(const Queue& aQueue);
	~Queue();

	void enqueue(const Student& aStudent);
	bool dequeue(Student& aStudent);
	/*
	bool peek(Student& aStudent) const;
	int getSize() const;
	bool isEmpty() const;
	*/
	const Queue& operator= (const Queue& aQueue);
	friend ostream& operator<< (ostream& out, const Queue& aQueue);

	void loadFromFile(const char * fileName);
	void saveToFile(const char * fileName) const;
private:
	struct Node
	{
		Student * data;
		Node * next;
	}
	Node * front, * back;
	int size;
};

#endif 
