#ifndef STACK_H
#define STACK_H
#include "student.h"
#include <fstream>

class Stack 
{
public:
	Stack();
	Stack(const Stack& aStack);
	~Stack();

	void push(const Student& aStudent);
	bool pop(Student& aStudent);
	/*
	bool peek(Student& aStudent) const;
	int getSize() const;
	bool isEmpty() const;
	*/
	const Stack& operator= (const Stack& aStack);
	friend ostream& operator<< (ostream& out, const Stack& aStack);

	void loadFromFile(const char * fileName);
	void saveToFile(const char * fileName) const;
private:
	Student ** 			aStack;
	const static int	INIT_CAP = 3;
	const static int	GROWTH_FACTOR = 2;
	int					currCapacity;
	int 				top;

	void destroy();
	void expand();
};

#endif 
