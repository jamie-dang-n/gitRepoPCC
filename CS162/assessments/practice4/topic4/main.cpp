#include "main.h"

int main(int argc, char ** argv)
{
	ItemList		inventory;
	char			fileName[] = "items.txt";

	//open file to read data and populate inventory
	ifstream		in;
	in.open(fileName);
	if(!in)
	{
		cerr << "Fail to open " << fileName << " for input!" << endl;
		return 1;
	}
	inventory.readList(in);

	cout << endl << "Current Inventory: " << endl;	
	inventory.printList();
	cout << endl; // blank line

	//invoke your functions here to do what is required
	// Task 1: getOlderItems()
	int userYear, userMonth, userDay;
	int numOlder;
	InventoryItem * olderItems;

	// Date user input
	getDate(userYear, userMonth, userDay);
	
	// Set up Date object from user
	Date userDate(userYear, userMonth, userDay);

	// Call getOlderItems()
	numOlder = inventory.getOlderItems(userDate, olderItems);
	if (numOlder != 0) {
		cout << "Yes! There are old items in your list." << endl; 
		cout << endl; // blank line
		for (int i = 0; i < numOlder; i++) {
			olderItems[i].print();
		}
		cout << endl; // blank line
	} else {
		cout << "There are no items older than that date in your list." << endl;
		cout << endl; // blank line
	}

	// Deallocating the array
	delete[] olderItems;


	// Task 2: Removing first and last nodes
	cout << "Removing first and last nodes." << endl;
	inventory.removeFirstAndLast();
	cout << endl; // blank line
	
	cout << "Updated list below:" << endl;
	inventory.printList();

	return 0;
}

void getDate(int& year, int& month, int& day) {
	cout << "Enter the expiration date to find items: ";
	cin >> year;
	cin.get(); // remove the /
	cin >> month;
	cin.get(); // remove the /
	cin >> day;
	cout << endl; // blank line
	
	while ((year < 0 || month < 0 || (day < 0 || day > 31)) || !cin || cin.peek() != '\n') {
		cout << "Error: Please enter a valid date. It should be in year/month/day format." << endl;
		cout << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	
		cout << "Enter the expiration date to find items: ";
		cin >> year;
		cin.get(); // remove the /
		cin >> month;
		cin.get(); // remove the /
		cin >> day;
		cout << endl; // blank line
	}
}
