/* Grocery item implementation file
 * CS162 Summer 2023, assessment files */

#include "item.h"
#include <cstring>

// Default constructor
Item::Item() {
    price = 0.0;
    count = 0;
    name = nullptr;
}

// Constructor with arguments
Item::Item(const char * nameArg, double priceArg, int countArg) {
    count = countArg;
    price = priceArg;
    name = new char[strlen(nameArg) + 1];
    strcpy(name, nameArg);
}

// Copy constructor
Item::Item(const Item & otherItem) {
    name = nullptr;
    *this = otherItem;
}

// Destructor
Item::~Item() {
    if(name != nullptr) {
        delete[] name;
    }
    name = nullptr;
}

// Overloaded assignment operator
Item & Item::operator=(const Item & otherItem) {
    if(&otherItem != this) {
        if(name != nullptr) {
            delete[] name;
        }
        name = new char[strlen(otherItem.name) + 1];
        strcpy(name, otherItem.name);
    
        price = otherItem.price;
        count = otherItem.count;
    }
    return *this;
}

// Overloaded insertion function, for printing.
ostream & operator<<(ostream & out, const Item & item) {
    out << left << setw(10) << item.name << right << "  $" <<
        setw(6) << item.price << setw(10) << item.count;
    return out;
}

// All the getters for price, count, and name.
double Item::getPrice() {
    return price;
}

int Item::getCount() {
    return count;
}

const char * Item::getName() {
    return name;
}

// All the setters for price, count, and name.
void Item::setPrice(double priceArg) {
    price = priceArg;
}

void Item::setCount(int countArg) {
    count = countArg;
}

void Item::setName(const char * nameArg) {
    if(name != nullptr) {
        delete[] name;
    }
    name = new char[strlen(nameArg) + 1];
    strcpy(name, nameArg);
}
