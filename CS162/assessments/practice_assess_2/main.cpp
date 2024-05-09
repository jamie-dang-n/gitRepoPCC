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

	//invoke your functions here to do what is required
	char ** itemNames;
	int numItems = 0;
	char name[MAX_CHAR];
	float price;
	int month;
	int day;
	int year;
	Date aDate;

	cout << endl; // blank line
	cout << "Enter name of item1: ";
	cin >> name;
	cout << "Enter price of item1: ";
	cin >> price;
	cout << "Enter expiry date of item1: ";
	cin >> year;
	cin.get();
	cin >> month;
	cin.get();
	cin >> day;
	cin.ignore(MAX_CHAR, '\n');
	cout << endl; // blank line

	aDate.setDate(year, month, day);

	InventoryItem anItem(name, price, aDate);
	cout << "you entered: ";
	anItem.print();
	cout << endl; // blank line

	numItems = inventory.getItemNames(itemNames);
	cout << "There are " << numItems << " items in your list." << endl;
	cout << "The item names in your list are:" << endl;
	cout << endl; // blank line
	for (int i = 0; i < numItems; i++) {
		cout << itemNames[i] << endl;
	}

	// Done using the itemNames array, deallocating now
	for (int i = 0; i < numItems; i++) {
		delete[] itemNames[i];
	}
	delete[] itemNames;
	itemNames = NULL;

	return 0;
}
