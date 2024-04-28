#include <iostream>
#include "linkedlist.h"

using namespace std;

void find(LinkedList& list, char ch)
{
	if (list.find(ch))
		cout << "found ";
	else
		cout << "did not find ";
	cout << ch << endl;
}

int main()
{
	LinkedList	list;
	//bool success = false;

	list.add('x');
	list.add('y');
	list.add('z');
	list.print();
	find(list, 'y');

	list.del('y');
	list.print();
	find(list, 'y');

	list.del('x');
	list.print();
	find(list, 'y');

	list.del('z');
	list.print();
	find(list, 'y');

	/*
	success = list.del('j');
	if (!success) {
		cout << "Unable to delete." << endl;
	}
	list.print();
	*/

	return 0;
}
