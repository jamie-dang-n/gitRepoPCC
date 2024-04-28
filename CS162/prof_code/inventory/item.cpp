/* inventory item class header file
 * CS162, Su 2023
 * Robert Martin */
#include "item.h"
#include "main.h"
#include <iostream>
using namespace std;

void InvItem::setCount(int count) {
    this->count = count;  // set the count argument.
}

InvItem::~InvItem() { // Invoked when the object goes out of scope, when it's destroyed.
    if(name != nullptr)
        delete[] name;  // free the memory just before the item goes out of score or is deleted..
}

// default constructor
InvItem::InvItem() {
    count = 0;
    price = 0.0;
    name = nullptr; // null string. Pointing at nothing.
}

// Constructor that takes arguments.
InvItem::InvItem(char nameArg[], int countArg, double priceArg) {
    int len = strlen(nameArg);
    name = new char[len + 1]; // Allocate. plus 1 for the null terminator.
    //name = new char[strlen(nameArg) + 1]; // combined. 
    strcpy(name, nameArg);
    count = countArg;
    price = priceArg;
}

// Constructor that takes arguments.
InvItem::InvItem(const char nameArg[], int countArg, double priceArg) {
    int len = strlen(nameArg);
    name = new char[len + 1]; // Allocate. plus 1 for the null terminator.
    //name = new char[strlen(nameArg) + 1]; // combined. 
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
        delete[] name; // crash if name is nullptr.
    int len = strlen(nameArg);
    name = new char[len + 1];
    strcpy(name, nameArg);
}


// item3.=(item2.=(item));  item3 = item2 = item;
const InvItem & InvItem::operator=(const InvItem & otherItem) {
    // item1 = item1; don't copy one item to itself.
    if(this != &otherItem) {
        count = otherItem.count;
        price = otherItem.price;
        if(name != nullptr)
            delete[] name;
        name = new char[strlen(otherItem.name) + 1];
        strcpy(name, otherItem.name);
    }
    return *this; // return the address of the current object.
}

// Copy constructor, for brand new items.
InvItem::InvItem(InvItem & otherItem) {
    count = otherItem.count;
    price = otherItem.price;
    name = new char[strlen(otherItem.name) + 1];
    strcpy(this->name, otherItem.name);
}

/*InvItem operator+(const InvItem & item1, const InvItem & item2) {
    InvItem retItem;  // automatic, allocated on the stack, removed at function termination.
    retItem.name = new char[strlen(item1.name) + strlen(" and ") + strlen(item2.name)];
    strcpy(retItem.name, item1.name);
    strcat(retItem.name, " and ");
    strcat(retItem.name, item2.name);
    retItem.count = item1.count + item2.count;
    retItem.price = item2.price;
    return retItem;
}*/

// from main, current object is item, and the argument is item2.
InvItem InvItem::operator+(const InvItem & otherItem) const {
    InvItem retItem;  // automatic, allocated on the stack, removed at function termination.
    retItem.name = new char[strlen(name) + strlen(" and ") + strlen(otherItem.name) + 1];
    strcpy(retItem.name, name);
    strcat(retItem.name, " and ");
    strcat(retItem.name, otherItem.name);
    retItem.count = count + otherItem.count;
    retItem.price = otherItem.price;
    return retItem;
}

// Operator insertion, friend function. Prototype is in the class definition.
// << item. Notice that I can use dot notation, rather than the getters.
ostream & operator<<(ostream & out, const InvItem & theItem) {
               
            out << left << setw(15) << theItem.name;
            out << "count: " << std::right << std::setw(5) << theItem.count; 
            out << std::left << "  price: " << std::right << std::setw(5) <<
                theItem.price << std::endl; 
    return out;
}

// cout << item1 << item2;

// item1 == item2
// Friend function for InvItem, has direct access to private members of InvItem.
bool operator==(const InvItem & item1, const InvItem & item2) {
    bool returnVal = false;
    if(strcmp(item1.name, item2.name) == 0) { // <0, 0 equal, >0 
        returnVal = true;
    }
    return returnVal;
}

/*bool InvItem::operator==(const InvItem & otherItem) const {
    bool returnVal = false;
    if(strcmp(name, otherItem.name) ==0) {
        returnVal = true;
    }
    return returnVal;
}*/
