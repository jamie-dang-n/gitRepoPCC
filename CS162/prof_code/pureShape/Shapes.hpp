//
//  Shapes.h
//  Shapes
//
//  Created by Robert Martin
//  CS162, PCC
//

#ifndef __Shapes__Shapes__
#define __Shapes__Shapes__

#include <iostream>
#include <cstring>
using namespace std;
const int strSize = 50;

const double PI = 3.14159;

class Shape // Pure Virtual Class
{
    char myName[strSize];
public:
    virtual double area() = 0; // This makes Shape an abstract class.
    virtual ~Shape();  // base class destructor.
    void setName(const char name[]);
    void getName(char name[], int size);
    Shape(); // default constructor.
    Shape(const char name[]);
};

class Circle : public Shape
{
    public:
        double area();
        Circle();
        Circle(double);
        ~Circle();
    private:
        double radius;
};

class Triangle : public Shape
{
public:
    double area();
    Triangle();
    Triangle(double b, double h);
    ~Triangle();
    
private:
    double height, base;
};

class Rectangle : public Shape
{
public:
    double area();
    Rectangle();
    Rectangle(double l, double w);
    ~Rectangle();
    
private:
    double length, width;
};
#endif /* defined(__Shapes__Shapes__) */
