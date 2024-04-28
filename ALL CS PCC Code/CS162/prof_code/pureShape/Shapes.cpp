//
//  Shapes.cpp
//  Shapes
//
//  Created by Robert Martin.
//  CS162 PCC
//

#include "Shapes.hpp"

Shape::Shape() {
    cout << "Base class constructor." << endl;
}

Shape::~Shape(){
    cout << "Base class destructor." << endl;
}

Shape::Shape(const char name[]) {
    strncpy(myName, name, strSize);
}

void Shape::setName(const char name[]) {
    strncpy(myName, name, strSize);
}

void Shape::getName(char name[], int size) {
    strncpy(name, myName, size);
}

Circle::Circle() : Shape("Circle") {
    radius = 0;
}

Circle::Circle(double r) : Shape("Circle") {
    radius = r;
}

double Circle::area() {
    char name[strSize];
    getName(name, strSize);
    cout << "Calculating area of a " << name << endl;
    return radius * radius * PI;
}

Circle::~Circle() {
    cout << "Circle destructor." << endl;
}

Triangle::Triangle() : Shape("Triangle") {
    base = 0;
    height = 0;
}

Triangle::Triangle(double b, double h) : Shape("Triangle") {
    base = b;
    height = h;
}

double Triangle::area() {
    char name[strSize];
    getName(name, strSize);
    cout << "Calculating area of a " << name << endl;
    return base * 0.5 * height;
}

Triangle::~Triangle() {
    cout << "Triangle destructor." << endl;
}

Rectangle::Rectangle() : Shape("Rectangle") {
    length = 0;
    width = 0;
}

Rectangle::Rectangle(double l, double w) : Shape("Rectangle") {
    length = l;
    width = w;
}

double Rectangle::area() {
    char name[strSize];
    getName(name, strSize);
    cout << "Calculating area of a " << name << endl;
    return length * width;
}

Rectangle::~Rectangle() {
    cout << "Rectangle destructor." << endl;
}

