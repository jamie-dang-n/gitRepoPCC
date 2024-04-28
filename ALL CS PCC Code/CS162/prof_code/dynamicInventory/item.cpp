/* inventory item class header file
 * CS162, Su 2023
 * Robert Martin */
#include "item.h"
#include "main.h"

void InvItem::setCount(int count) {
    this->count = count;  // set the count argument.
}

InvItem::~InvItem() { // Invoked when the object goes out of scope, when it's destroyed.
    if(name != nullptr)
        delete[] name;
}

// default constructor
InvItem::InvItem() {
    count = 0;
    price = 0.0;
    name = nullptr; // null string.
}

// Constructor that takes arguments.
InvItem::InvItem(char nameArg[], int countArg, double priceArg) {
    int len = strlen(nameArg);
    name = new char[len + 1]; // Allocate. plus 1 for the null terminator.
    strcpy(name, nameArg);
    count = countArg;
    price = priceArg;
}

// load Inventory item.
// Argument: a reference to an inventory item.
// Ask the user for the name, count, and price of the new inventory item.
void InvItem::loadItem() {
    char numberStr[strSize];
    char tempStr[strSize];
    std::cout << "What is the new item name? :";
    std::cin.getline(tempStr, strSize);
    if(name != nullptr)
        delete[] name;
    name = new char[strlen(tempStr) + 1];  // Allocate just the right amount of space.
    strcpy(name, tempStr);
    std::cout << "What is the new item count? :";
    count = validInt();
    std::cout << "What is the new item price? :";
    price = validDouble();
}

// Implementation of "getters," also called accessor functions.
const char * InvItem::getName() const {
    return name; // can't return an array, but we are returning the poiter - first location.
}

int InvItem::getCount() const {
    return count;
}

double InvItem::getPrice() const {
    return price;
}

// This is the style of getter that is used in the Zybooks chapter.
// The user/client sends an address of the c-string that they want the name to be copied to.
// It's important to know the size of copyDestination, so the buffer doesn't overflow.
// Only the user/client knows the size of their string, so they pass it in as an int.
void InvItem::getName(char * copyDestination, int size) const {
    strncpy(copyDestination, name, size);
}

void InvItem::setName(char * nameArg) {
    if(name != nullptr)
        delete[] name;
    int len = strlen(nameArg);
    name = new char[len + 1];
    strcpy(name, nameArg);
}

