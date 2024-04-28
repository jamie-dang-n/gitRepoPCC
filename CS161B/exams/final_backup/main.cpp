//main driver file
//add header comments here.
#include "person.h"
// const int CAPACITY = 20;

//function protoypes

//main and then functions.
int main()
{
	// Variables
	PersonType list[CAPACITY];
	int 	   count  = 0;
	char	   fileName[] = "persons.txt";

	// Welcome Message
	cout << "Welcome to my Citizen's Database." << endl;
	cout << endl; // blank line
	cout << "Here is your list so far:" << endl;
	cout << endl; // blank line

	populatePersons(list, count, fileName);
	printPersons(list, count);

	// Adding a person to the list and displaying the list
	cout << endl; // blank line
	if (addPerson(list,count) == true) {
		cout << "\nAfter adding a person, the list is:\n" << endl;
		printPersons(list, count);
	}

	cout << endl; // blank line
	cout << "Thank you for using my Citizen Database!!" << endl;

	return 0;
}


