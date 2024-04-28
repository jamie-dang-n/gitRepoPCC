//
//  main.cpp
//  Shapes
//
//  Created by Robert Martin
//  CS162 PCC
//

#include "Shapes.hpp"

#include <iostream>

int main(int argc, const char * argv[]) {
    //Shape s1; // Can't be done, because Shape is a pure virtual class.
    double radius, length, width, base, height;
    Shape * r1 = new Rectangle(2, 3);
    Shape * t1 = new Triangle(2, 3);
    Shape * c1 = new Circle(2.5);
    Shape * s1;
    char shapeChoice = ' ';

    cout << "Area of r1: " << r1->area() << endl;
    cout << "Area of t1: " << t1->area() << endl;
    cout << "Area of c1: " << c1->area() << endl;

    cout << "What shape do you want? c, r, t: ";
    cin >> shapeChoice;
    if(shapeChoice == 'c') {
        cout << "What is the radius? ";
        cin >> radius;
        s1 = new Circle(radius);
    }
    else if(shapeChoice == 'r') {
        cout << "What is the length and width? ";
        cin >> length >> width;
        s1 = new Rectangle(length, width);
    }
    else if(shapeChoice == 't') {
        cout << "What is the base and height? ";
        cin >> base >> height;
        s1 = new Triangle(base, height);
    }
    
    cout << "Area of s1: " << s1->area() << endl;

    delete r1;
    delete t1;
    delete c1;
    delete s1;
    return 0;
}
