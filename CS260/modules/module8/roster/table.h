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
	bool remove(const char * key, Student& aStudent);
	/*
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
			left = right = nullptr;
		};
		
		Student *	data;
		Node *		left;
		Node *		right;
	};

	Node *	root;
	int 	size;

	void add(Node *& currRoot, const Student& aStudent);
	bool remove(Node *& currRoot, const char * key, Student& aStudent);
	void deleteNode(Node *& target);
	void destroy(Node *& currRoot);
	void copy(Node * srcRoot, Node *& destRoot);
	void display(ostream& out, Node * currRoot) const;
	void displayPreorder(ostream& out, Node * currRoot) const;
	void displayInorder(ostream& out, Node * currRoot) const;
	void displayPostorder(ostream& out, Node * currRoot) const;
	void saveToFile(ostream& out, Node * currRoot) const;
	void loadFromArray(Student * studentList, int first, int last);
};

#endif 
