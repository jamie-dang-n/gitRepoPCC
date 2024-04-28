// Rect ADT (class) implementation file
// CS162, PCC
//
#include "Rect.hpp"
#include <iostream>
using namespace std;

// Default constructor.
Rect::Rect() {
    length = 0.0;
    width = 0.0;
    name = new char[strlen("Rect") + 1];
    strcpy(name, "Rect");
}

// Copy Constructor
Rect::Rect(const Rect & otherRect) {
    name = new char[strlen(otherRect.name) + 1];
    strcpy(name, otherRect.name);
    length = otherRect.length;
    width = otherRect.width;
}

Rect & Rect::operator=(const Rect & r) {
    if(name != nullptr)
        delete[] name;
    name = new char[strlen(r.name) + 1];
    strcpy(name, r.name);
    length = r.length;
    width = r.width;
    return *this;
}

// Destructor.
Rect::~Rect() {
    cout << "In the rect destructor." << endl;
    if(name != nullptr)
        delete[] name;
}

// Constructor with arguments.
Rect::Rect(const char nameArg[], double l, double w) {
    length = l;
    width = w;
    name = new char[strlen(nameArg) + 1];
    strcpy(name, nameArg);
}

// set the name
void Rect::setName(const char nameArg[]) {
    name = new char[strlen(nameArg) + 1];
    strcpy(name, nameArg);
}

// Setter (Mutator) Definitions
void Rect::setLength(double l) {
    length = l;
}

void Rect::setWidth(double w) {
    width = w;
}

// Getter (Accessor) Definitions
double Rect::getLength() const {
    return length;
}

double Rect::getWidth() const {
    return width;
}

double Rect::area() const {
    return length * width;
}

void Rect::getInfo() {
    cout << name <<  " info: Length: " << length << ", Width: " << width << endl;
}

const char * Rect::getName() {
    return name;
}
