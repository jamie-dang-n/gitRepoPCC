#include "stack.h"

Stack::Stack() : top(0)
{
	currCapacity = INIT_CAP;
	aStack = new Student*[currCapacity];
	for(int i=0; i<currCapacity; i++)
	{
		aStack[i] = nullptr;
	}
}

Stack::Stack(const Stack& aStack) : aStack(nullptr), top(0)
{
	*this = aStack;
}

Stack::~Stack()
{
	destroy();
}

void Stack::destroy()
{
	for(int i=0; i<top; i++)
	{
		if(aStack[i])
			delete aStack[i];
	}
	if(aStack)
		delete [] aStack;
}

void Stack::push(const Student& aStudent)
{
	if(currCapacity == top)
	{
		expand();
	}
	aStack[top] = new Student(aStudent);	
	top++;
}

void Stack::expand()
{
	currCapacity *= GROWTH_FACTOR;
	Student ** tempStack = new Student*[currCapacity];
	for(int i=0; i<top; i++)
	{
		tempStack[i] = aStack[i]; //only copy the pointers
	}
	delete [] aStack;
	aStack = tempStack;
}

bool Stack::pop(Student& aStudent)
{
	if(top == 0)
		return false;
	aStudent = *(aStack[top-1]);
	delete aStack[top-1];
	top--;
	return true;
}

const Stack& Stack::operator= (const Stack& stackSrc)
{
	if(this == &stackSrc)
		return *this;
	destroy();
	top = stackSrc.top;
	currCapacity = stackSrc.currCapacity;
	aStack = new Student*[currCapacity];
	for(int i=0; i<top; i++)
	{
		aStack[i] = new Student(*(stackSrc.aStack[i])); //copy the student
	}
	return *this;
}	

ostream& operator<< (ostream& out, const Stack& srcStack)
{
	out << endl << "Displaying the stack ..." << endl;
	for(int i=0; i<srcStack.top; i++)
	{
		out << *(srcStack.aStack[i]) << endl;
	}
	return out;
}

void Stack::loadFromFile(const char * fileName)
{
	ifstream 	in;
	Student		currStudent;
	const int 	MAX_CHAR = 101;
	char		currName[MAX_CHAR];
	float		currGpa;

	in.open(fileName);
	if(!in)
	{
		cerr << "Fail to open " << fileName << " for reading!" << endl;
		exit(1);
	}

	in.get(currName, MAX_CHAR, ';');
	while(!in.eof())
	{
		in.get();
		in >> currGpa;
		in.ignore(MAX_CHAR, '\n');
		
		currStudent.setName(currName);
		currStudent.setGpa(currGpa);
		push(currStudent);
		in.get(currName, MAX_CHAR, ';');
	}
	in.close();
}

void Stack::saveToFile(const char * fileName) const
{
	ofstream	out;
	
	out.open(fileName);
	if(!out)
	{
		cerr << "Fail to open " << fileName << " for writing!" << endl;
		exit(1);
	}

	for(int i=0; i<top; i++)
	{
		out << aStack[i]->getName() << ';' << aStack[i]->getGpa() << endl;
	}
	out.close();
}
	
