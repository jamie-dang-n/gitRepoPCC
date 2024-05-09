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
    Node * tail;
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
                tail = newNode;
            }
            else {
                // tail is declared locally.
                tail->next = newNode;
                tail = newNode;
            }
            itemCount++;
            inFile.peek(); // Check for the eof marker.
        }
        success = true;
    }
    return success;
}

// This function removes the first node in the linked list
void GroceryList::removeFirst() {
	if (head == nullptr) { // no items to remove
		cout << "No actions taken, no items to remove." << endl;
	} else {
		Node * second = head->next;
		delete head;
		head = second;
		itemCount--; // removed an item, so we decrement itemCount
	}
}

// This function moves the last element to be the new head of the list
void GroceryList::lastToFirst() {
	Node * curr = head;
	Node * prev = nullptr;
	while (curr->next != nullptr) {
		prev = curr;
		curr = curr->next;
	}
	// When we exit the loop, we've found the last node
	prev->next = nullptr;
	curr->next = head;
	head = curr;
}	

