// CS162 PCC rectangle class
#ifndef __RECT__
#define __RECT__

#include <iostream>
using namespace std;

class Rect {
	private: // allow direct access to derived classes ONLY.
	double length;
	double width;
	public:
	Rect(); // Default Constructor
	Rect(double len, double wid); // Parameterized Constructor -- takes arguments
	double getLength();
	double getWidth();
	void setLength(double len);
	void setWidth(double wid);
	double area();
	double perimeter();
	void print();
};

#endif
