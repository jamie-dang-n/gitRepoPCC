#include "dlist.h"
using namespace std;

void getInt(int&);

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	int num = 0;
	int delNum = 0;
	cout << endl; // blank line
	cout << "Jamie's Code Solutions" << endl;
	cout << "[int count()] The number of items in this list is: " << count(head) << endl;	

	
	cout << "[void insert()] Calling insert(): " << endl;
	//cout << "Enter number for insertion position: ";
	//getInt(num);
	insert(head, 2024, count(head));
	cout << "[void insert()] List after insert(): " << endl;
	display(head);

	cout << "[int remove()] Calling remove(): " << endl;
	//cout << "Enter number for removal positon: ";
	//getInt(num);
	delNum = remove(head, count(head));
	cout << "Number removed: " << delNum << endl;
	cout << "[int remove()] List after remove(): " << endl;
	
	display(head);
	destroy(head);    
	return 0;
}

void getInt(int& num) {
	cin >> num;	
	while (!cin || cin.peek() != '\n' || num < 0) {
		cout << "Error: please enter a valid position :";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> num;
	}
}
