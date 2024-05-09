#ifndef LIST_H
#define LIST_H
#include "student.h"
#include <fstream>

class List
{
public:
	List();
	List(const List& aList);
	~List();

	void append(const Student& aStudent);
	bool get(int position, Student& aStudent) const;
	bool insert(int position, const Student& aStudent);
	/*
	bool remove(int poisiton, Student& aStudent);
	*/
	const List& operator= (const List& aList);
	friend ostream& operator<< (ostream& out, const List& aList);

	void loadFromFile(const char * fileName);
	void saveToFile(const char * fileName) const;
private:
	struct Node
	{
		Node(const Student& aStudent)
		{
			data = new Student(aStudent);
			prev = next = nullptr;
		}
		~Node()
		{
			delete data;
			data = nullptr;
			prev = next = nullptr;
		}
		Student * data;
		Node *prev, *next;
	};
	Node *head, *tail;
	int size;
	void destroy(Node * currHead);
	void copy(Node * currHeadSrc, Node * prevHeadDes, Node *& currHeadDes);
	bool get(Node * currHead, int currPosition, int position, Student& aStudent) const;
	bool insert(Node * currHead, int currPosition, int position, const Student& aStudent);
};

#endif 
