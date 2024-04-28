#include "list.h"

List::List() : head(nullptr), tail(nullptr), size(0){}

List::List(const List& aList) : head(nullptr), tail(nullptr), size(0)
{
	*this = aList;
}

List::~List()
{
	destroy(head);
	size = 0;
}

void List::destroy(Node * currHead)
{
	if(currHead)
	{
		destroy(currHead->next);
		delete currHead;
	}
}

bool List::get(int position, Student& aStudent) const
{
	if(position < 0 || position >= size)
		return false;
	return get(head, 0, position, aStudent);
}

bool List::get(Node * currHead, int currPosition, int position, Student& aStudent) const
{
	if(!currHead)
		return false;
	if(currPosition == position)
	{
		aStudent = *(currHead->data);
		return true;
	}
	return get(currHead->next, ++currPosition, position, aStudent);
}

bool List::insert(int position, const Student& aStudent)
{
	if(position < 0 || position >= size)
		return false;
	return insert(head, 0, position, aStudent);
}

bool List::insert(Node * currHead, int currPosition, int position, const Student& aStudent)
{
	if(!currHead)
		return false;
	if(currPosition == position)
	{
		Node * newNode = new Node(aStudent);
		newNode->next = currHead;
		newNode->prev = currHead->prev;
		if(currHead->prev)
		{
			currHead->prev->next = newNode;
		}
		else
		{
			head = newNode;
		}
		currHead->prev = newNode;
		size++;
		return true;
	}
	return insert(currHead->next, ++currPosition, position, aStudent);
}

void List::append(const Student& aStudent)
{
	Node * newNode = new Node(aStudent);
	if(!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	size++;
}

const List& List::operator= (const List& aList)
{
	if(this == &aList)
		return *this;
	destroy(head);
	size = aList.size;
	copy(aList.head, nullptr, this->head);
	
	return *this;
}	

void List::copy(Node * currHeadSrc, Node * prevHeadDes, Node *& currHeadDes)
{
	if(!currHeadSrc)
	{
		currHeadDes = nullptr;
		tail = prevHeadDes;
	}
	else
	{
		currHeadDes = new Node(*(currHeadSrc->data));
		currHeadDes->prev = prevHeadDes;
		copy(currHeadSrc->next, currHeadDes, currHeadDes->next);
	}
}

ostream& operator<< (ostream& out, const List& aList)
{
	List::Node * curr;

	out << endl << "Displaying the list ... " << endl;
	for(curr=aList.head; curr; curr=curr->next)
	{
		out << *(curr->data) << endl;
	}

	cout << endl << "Displaying the list in reverse ... " << endl;
	for(curr=aList.tail; curr; curr=curr->prev)
	{
		out << *(curr->data) << endl;
	}
	return out;
}

void List::loadFromFile(const char * fileName)
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
		append(currStudent);
		in.get(currName, MAX_CHAR, ';');
	}
	in.close();
}

void List::saveToFile(const char * fileName) const
{
	ofstream	out;
	
	out.open(fileName);
	if(!out)
	{
		cerr << "Fail to open " << fileName << " for writing!" << endl;
		exit(1);
	}

	for(Node * curr=head; curr; curr=curr->next)
	{
		out << curr->data->getName() << ';' << curr->data->getGpa() << endl;
	}
	out.close();
}
	
