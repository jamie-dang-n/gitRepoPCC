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
	int idx;
	float newPrice;
	
	cout << endl << "Current Inventory: " << endl;	
	inventory.printList();
	
	cout << "\nItem created by my constructor:" << endl;
	InventoryItem item1("Blueberries", 1.99);
	item1.print();
	cout << endl; // blank line

	cout << "Enter index of item to change: ";
	validInt(idx, inventory);
	idx = idx - 1;
	cout << "Enter new price of the item: ";
	validFloat(newPrice, inventory);	
	cout << endl; // blank line

	cout << "After modifying item " << idx << ", the updated list is as below:" << endl;
	inventory.changePrice(idx, newPrice);
	cout << "Current Inventory:" << endl;
	inventory.printList();

	return 0;
}

void validInt(int &num, const ItemList inventory) {
	cin >> num;
	while (!cin || cin.peek() != '\n' || num <= 0 || num > inventory.length()) {
		cout << "Error: Please enter a valid integer for the index." << endl;
		cout << "Enter index of item to change: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> num;
	}
}

void validFloat(float &num, const ItemList inventory) {
	cin >> num;
	while (!cin || cin.peek() != '\n' || num < 0.0 ) {
		cout << "Error: Please enter a valid price." << endl;
		cout << "Enter new price of the item: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> num;
	}
}
