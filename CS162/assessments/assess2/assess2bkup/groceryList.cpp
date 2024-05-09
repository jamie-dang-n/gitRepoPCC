// Jamie Dang - groceryList.cpp
/* groceryList implementation file
 * CS162 Summer 2023, assessment files */

#include "groceryList.h"

// Default constructor
GroceryList::GroceryList() {
    itemCount = 0;
    capacity = 3;
    items = new Item*[capacity];
}

// Destructor
GroceryList::~GroceryList() {
    for(int i = 0; i < itemCount; i++) {
        delete items[i];
    }
    delete[] items;
}

// Getter for itemCount. There is no setter (can only be changed by adding new items).
int GroceryList::getItemCount() {
    return itemCount;
}

// grow() function. Should be called if itemCount >= capacity.
void GroceryList::grow() {
    capacity *= 2;
    Item ** tempList = new Item*[capacity];
    
    for(int i = 0; i < itemCount; i++) {
        tempList[i] = items[i]; // copy the pointers.
    }
    
    delete [] items; // Get rid of the old list.
    items = tempList; // Make the items list point to the new list.
}

// Print the grocery list. It uses column output using setw().
void GroceryList::printItems() {
    cout << setprecision(2) << fixed << showpoint;
    cout << setw(10) << left << "Name" << setw(12) << right << "Price" <<
        setw(10) << "Count" << endl;
    cout << setw(10) << left << "----" << setw(12) << right << "-----" <<
        setw(10) << "-----" << endl;

    for(int i = 0; i < itemCount; i++) {
        cout << left <<  i + 1 << ". " << setw(10) << items[i]->getName() <<
            right << "  $" << setw(6) << items[i]->getPrice() << setw(10) <<
            items[i]->getCount() << endl;
    }
}

// The function to load items from the file into the array of items.
// There is no write file function.
bool GroceryList::loadItems() {
    bool success = false;
    char nameString[STR_SIZE];
    int count = 0;
    double price = 0;
    inFile.open(fileName);

    if(inFile.is_open()) {
        while(!inFile.eof() && itemCount < ARRAY_SIZE) {
            inFile.getline(nameString, STR_SIZE, ';');
            inFile >> price;
            inFile.ignore(); // throw away the semicolon.
            inFile >> count;
            inFile.ignore(); // throw away the newline.
            items[itemCount] = new Item;
            items[itemCount]->setName(nameString);
            items[itemCount]->setPrice(price);
            items[itemCount]->setCount(count);
            itemCount++;
            if(itemCount >= capacity) { // make more room.
                grow();
            }
            inFile.peek(); // Check for the eof marker.
        }
        success = true;
    }
    return success;
}


// adding an item to the list
void GroceryList::addItem() {
	Item tempItem;
	char tempName[STR_SIZE];
	double tempPrice = 0.0;
	int tempCount = 0;

	// Receiving input
	cout << "What is the new item name?: ";
	cin.getline(tempName, STR_SIZE, '\n');
	
	cout << "What is the item count?: ";
	cin >> tempCount;
	// Validate Count
	while (!cin || cin.peek() != '\n' || tempPrice < 0.0) {
		cout << "Invalid quantity. Please try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "What is the item count?: ";
		cin >> tempCount;
	}

	cout << "What is the item price?: ";
	cin >> tempPrice;
	// Validate Price
	while (!cin || cin.peek() != '\n' || tempPrice < 0.0) {
		cout << "Invalid price. Please try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "What is the item price?: ";
		cin >> tempPrice;
	}

	// Setting up tempItem
	tempItem.setPrice(tempPrice);
	tempItem.setCount(tempCount);
	tempItem.setName(tempName);

	// Grow the list if needed	
	if (itemCount >= capacity) {
		grow();
	} 		

	// Use copy constructor to add tempItem to the list
	items[itemCount] = new Item(tempItem);
	itemCount++;	
}

