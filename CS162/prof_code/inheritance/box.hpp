/* Robert Martin
 * CS162 Summer '23
 * Inheritance example, box class. */
#include "rect.hpp" // base class header

#ifndef BOX_H
#define BOX_H

class Box : Rect { // Box inherits ("is a") from Rect. Rect is the base class.
	// Box is the derived class
	private:
	double height; // specific to box class
	// rect class already has the length and width data member
	// INHERIT the length and width from Rect class

	public:	
	// Getter
	double getHeight();
	// Setter
	void setHeight(double heightArg);
	double volume();		
	// Default Constructor
	Box(); // will be invoked, and will automatically invoke Rect() default constructor (base class default constructor)
	// Parameterized constructor
	Box(double, double, double);  // names of args not required for prototypes
};

#endif

