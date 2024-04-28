// Rect ADT (class) implementation file
// CS162, PCC

#include "Box.hpp"
#include <iostream>
using namespace std;

// The base class constructor,
// for Rect, is invoked automatically.
Box::Box() {
    height = 0.0;
    setName("Box");
    purpose = new char[strlen("purpose") + 1];
    strcpy(purpose, "purpose");
}

// Use and initialization list for Rect.
Box::Box(const char purposeArg[], const char nameArg[], double l, double w, double h) :
    Rect(nameArg, l, w) // invoke the base class constructor.
{
    height = h;
    purpose = new char[strlen(purposeArg) + 1];
    strcpy(purpose, purposeArg);
}

// Copy Constructor.
Box::Box(Box & b) : Rect(b) {
    //setLength(b.getLength());
    //setWidth(b.getWidth());
    height = b.height;
    //setName(b.getName());
    purpose = new char[strlen(b.purpose) + 1];
    strcpy(purpose, b.purpose);
}



Box::~Box() {
    cout << "In the box destructor." << endl;
    if(purpose != nullptr)
        delete[] purpose;
}

double Box::getHeight() const {
    return height;
}
void Box::setHeight(double h) {
    height = h;
}

// Overrides the getInfo function in Rect.
void Box::getInfo() {
    cout << getName() << " info: " << ", purpose: " << purpose;
    cout << ", Length: " <<  getLength() << ", Width: " << getWidth() << ", Height: " <<
        height << endl;
}

Box & Box::operator=(Box & otherBox) {
    Rect::operator=(otherBox); // call the base class assignment operator.
    if(purpose != nullptr)
        delete[] purpose;
    purpose = new char[strlen(otherBox.purpose) + 1];
    strcpy(purpose, otherBox.purpose);
    height = otherBox.height;
    return *this;
}
