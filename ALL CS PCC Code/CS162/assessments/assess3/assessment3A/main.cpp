/* main function file
 * CS162 Summer 2023 assessment files */

#include "main.h"
using namespace std;

// Function main, the driver for the grocery list class.
// The function creates a groceryList item (shoppingCart), calls the loadItems()
// member function to read items from a file, and then prints the list.
// Your job is to fill in the code to accomplish the assessment tasks.
int main() {
	bool listLoaded = false;
	Item maxItem;
	GroceryList shoppingCart;
	listLoaded = shoppingCart.loadItems();

	cout << "\nWelcome to the shopping cart program.\n";
	if(listLoaded) {
		cout << "Successfully loaded " << shoppingCart.getItemCount() << " items.\n";
		cout << "The items in the cart are: \n\n";
		shoppingCart.printItems();
	}
	else {
		cout << "An error occured while loading the grocery list items.\n";
	}

	// *****************************************
	// Fill in the code for the assessment here.
	// *****************************************
	maxItem = shoppingCart.getMaxPriceItem();
	cout << "\nThe item with the max price is:\n" << maxItem << endl << endl;
	shoppingCart.addSecond();
	cout << "\nThe shopping cart with the new item is:" << endl << endl;
	shoppingCart.printItems();



	return 0;
}
