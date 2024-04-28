// CS162 Rect driver function
#include "rect.hpp"
#include "box.hpp"

int main() {
	Box b1; // Box constructor is invoked, and Box will invoke Rect automatically (default constructors) 
	b1.setHeight(2.3); // using box class setter; indirect access to height
			   // abstraction-- an interface to work with an object
	//double volume = b1.volume();
	
	Rect r1; // invokes the default constructor, no parenthesis! ()
	
	cout << "The area of r1 is" << r1.area() << endl;
	cout << r1.getWidth() << endl;

	Rect r2(2.3, 4.5); // parameterized constructor 
	Box b2(2.0, 3.0, 4.0);
	
	r2.print();
	cout << "The area of r2 is: " << r2.area() << endl;
	
	
	return 0;
}
