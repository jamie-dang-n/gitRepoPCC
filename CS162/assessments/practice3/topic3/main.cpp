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

	//invoke your functions here to do what is required
	cout << endl << "Current Inventory: " << endl;	
	inventory.printList();
	cout << endl; // blank line

	// Task 1: getLowerCostItems()
	float userPrice;
	int numItems;
	InventoryItem * lowerCostItems;
	
	userPrice = getFloat();
	numItems = inventory.getLowerCostItems(userPrice, lowerCostItems);
	cout << endl; // blank line

	cout << "There are " << numItems << " items below that price." << endl;
	cout << "The items in your list below that price are:" << endl;	
	for (int i = 0; i < numItems; i++) {
		lowerCostItems[i].print();
	}
	cout << endl; // blank line

	// Deallocate the Dynamically allocated array
	delete[] lowerCostItems;

	// Task 2: swapFirstAndLast()
	cout << "After swapping the first and last item, the list is:" << endl;
	inventory.swapFirstAndLast();
	inventory.printList();

	return 0;
}

float getFloat() {
	float userFloat;
	cout << "Enter the maximum price and I will print the items below that price $: ";
	cin >> userFloat;
	while (!cin || cin.peek() != '\n' || userFloat < 0.0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please enter a valid price." << endl;
		cout << "Enter the maximum price and I will print the items below that price $: ";
		cin >> userFloat;
	}
	return userFloat;
}
