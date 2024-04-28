// Jamie Dang - item.cpp
/* Grocery item implementation file
 * CS162 Summer 2023, assessment files */

#include "item.h"
#include <cstring>

// Default constructor.
Item::Item() {
    price = 0.0;
    count = 0;
    name = nullptr;
}

// copy constructor
Item::Item(const Item & otherItem) {
	price = otherItem.price;
	count = otherItem.count;
	name = new char[strlen(otherItem.name) + 1];
	strcpy(name, otherItem.name);
}

// Destructor
Item::~Item() {
    if(name != nullptr) {
        delete[] name;
    }
    name = nullptr;
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


