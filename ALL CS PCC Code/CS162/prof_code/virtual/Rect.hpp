// Header file for the Rect ADT (class)
// Polymorphism Example, CS162, PCC Rockcreek

#ifndef __RECT__
#define __RECT__
#include <cstring>

//Rectangle ADT.
class Rect {
    double length;
    double width;
    char * name;

    public:
    // Default constructor prototype.
    Rect();
    // Constructor with arguments.
    Rect(const char[], double, double);

    // Functions required for dynamic members:
    Rect(const Rect & otherRect);  // Copy constructor.
    Rect & operator=(const Rect &); // Overloaded assignment.
    ~Rect(); // Destructor.

    // mutators "setters"
    // indirect access.
    void setLength(double);
    void setWidth(double);
    void setName(const char[]);
    
    // accessors "getters"
    double getLength() const;
    double getWidth() const;
    double area() const;
    const char * getName();
    void getInfo(); // base class version.
};
#endif
