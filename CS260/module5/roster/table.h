#ifndef TABLE_H
#define TABLE_H
#include "student.h"
#include <fstream>

class Table 
{
public:
	Table();
	Table(const Table& aTable);
	~Table();

	void add(const Student& aStudent);
	/*
	bool remove(const char * key, Student& aStudent);
	bool retrieve(const char * key, Student& aStudent) const;
	int getSize() const;
	*/
	const Table& operator= (const Table& aTable);
	friend ostream& operator<< (ostream& out, const Table& aTable);

	void loadFromFile(const char * fileName);
	void saveToFile(const char * fileName) const;
private:
	struct Node
	{
		Node(const Student& aStudent)
		{
			data = new Student(aStudent);
			next = nullptr;
		};
		
		Student *	data;
		Node *		next;
	};
	Node** 				aTable;
	const static int	INIT_CAP = 10;
	int					currCapacity;
	int 				size;

	int calculateIndex(const char * key) const;
	void destroy();
	void destroyChain(Node *& currHead);
	void copyChain(Node * srcHead, Node *& destHead);
	void displayChain(ostream& out, Node * currHead) const;
	void writeOutChain(ostream& out, Node * currHead) const;
};

#endif 
