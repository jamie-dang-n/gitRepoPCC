/* groceryList implementation file
 * CS162 Summer 2023, assessment files */

#include "groceryList.h"

// Default constructor
GroceryList::GroceryList() {
    itemCount = 0;
    head = nullptr;
}

// Destructor
GroceryList::~GroceryList() {
    Node * cur = head;
    while(cur != nullptr) {
        cur = cur->next;
        delete head;
        head = cur;
    }
}

// Getter for itemCount. There is no setter (can only be changed by adding new items).
int GroceryList::getItemCount() {
    return itemCount;
}


// Print the grocery list. It uses column output using setw().
void GroceryList::printItems() {
    Node * cur = head;
    int index = 1;
    cout << setprecision(2) << fixed << showpoint;
    cout << setw(10) << left << "Name" << setw(12) << right << "Price" <<
        setw(10) << "Count" << endl;
    cout << setw(10) << left << "----" << setw(12) << right << "-----" <<
        setw(10) << "-----" << endl;

    while(cur != nullptr) {
        cout << left << index << ". " << cur->item << endl;
        cur = cur->next;
        index++;
    }
}

// The function to load items from the file into the array of items.
// There is no write file function.
bool GroceryList::loadItems() {
    Node * newNode;
    bool success = false;
    char nameString[STR_SIZE];
    int count = 0;
    double price = 0;
    inFile.open(fileName);

    if(inFile.is_open()) {
        while(!inFile.eof()) {
            inFile.getline(nameString, STR_SIZE, ';');
            inFile >> price;
            inFile.ignore(); // throw away the semicolon.
            inFile >> count;
            inFile.ignore(); // throw away the newline.
            newNode = new Node;
            newNode->next = nullptr;
            newNode->item.setName(nameString);
            newNode->item.setPrice(price);
            newNode->item.setCount(count);

            if(head == nullptr) {
                head = newNode;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
            itemCount++;
            inFile.peek(); // Check for the eof marker.
        }
        success = true;
    }
    return success;
}

// Finding the item with the maximum price
Item GroceryList::getMaxPriceItem() {
	Node * curr;
	Item maxItem;
	double maxPrice = 0.0;

	// Set the maximums to the first item in the list 
	maxItem = head->item;
	maxPrice = maxItem.getPrice();

	// Traverse to find the max price item
	curr = head;
	while (curr) {
		if (curr->item.getPrice() > maxPrice) {
			maxItem = curr->item;
			maxPrice = maxItem.getPrice();
		}
		curr = curr->next;
	}
	return maxItem;
}


// Adding a grocery item to the second position in the list
void GroceryList::addSecond() {
	Node * temp;
	Node * second;
	char userName[STR_SIZE];
	double userPrice = 0.0;
	int userCount = 0;

	// Getting user input
	cout << "What is the new item name?: ";
	cin.getline(userName, STR_SIZE, '\n');

	cout << "What is the item count?: ";
	cin >> userCount;
	validateNum(userCount);
	
	cout << "What is the item price?: ";
	cin >> userPrice;
	validateNum(userPrice);

	Item newItem(userName, userPrice, userCount);

	// Creating the new node
	temp = new Node;
	temp->item = newItem;

	// Inserting the new node after head
	second = head->next;
	head->next = temp;
	temp->next = second;

	// Increment itemCount
	itemCount++;
}

// Overloaded helper functions for validating numberic input
void GroceryList::validateNum(double & num) {
	while (!cin || cin.peek() != '\n' || num < 0.0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please enter a valid number." << endl;
		cout << "What is the item price?: ";
		cin >> num;
	}
}

void GroceryList::validateNum(int & num) {
	while (!cin || cin.peek() != '\n' || num < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please enter a valid number." << endl;
		cout << "What is the item count?: ";
		cin >> num;
	}
}

