/* Box implementation code file. */
#include "box.hpp"

// Default Constructor
Box::Box() {
	height = 1.0; // you can initialize this to whatever you want
}

// Contructor for Box that takes arguments for all 3 dimensions
// Pass lengthArg and widthArg to Rect with initialization list 
Box::Box(double lengthArg, double widthArg, double heightArg) : Rect(lengthArg, widthArg) {
	height = heightArg;
	// height is part of the box class, so we can access it directly
	// length and width are part of the rect class, so we need the initialization list to access them
}

double Box::getHeight() {
	return height;
	// ex 1: get height from a database
	// ex 2: get height from some other app or .dll (dynamic linked library)... etc
}

void Box::setHeight(double heightArg) {
	height = heightArg;	
}

// Volume member function: gets the volume of the box
// returns: the volume as a double
// arguments: none
double Box::volume() {
	return getLength() * getWidth() * height;
}





