// CS162 Rect implementation
#include "rect.hpp"

// Constructors
Rect::Rect() {
    length = 1.0;
    width = 1.0;
}

Rect::Rect(double len, double wid) {
    length = len;
    width = wid;
}

// Getters, accessors, indirect read
double Rect::getLength() {
    return length;
}

double Rect::getWidth() {
    return width;
}

// Setters, mutators, indirect write
void Rect::setLength(double len) {
    length = len;
}

void Rect::setWidth(double wid) {
    width = wid;
}

void Rect::print() {
    cout << "Length: " << length << ", width: " << width << endl;
}

double Rect::area() {
    return length * width;
}

double Rect::perimeter() {
    return 2 * (length + width);
}
