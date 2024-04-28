// Polymorphism Example, CS162, PCC Rockcreek
#ifndef __BOX__
#define __BOX__
#include "Rect.hpp"

// Inheritance: "is-a" relationship.
// Box "is a" rectangle with 1-more dimension.
class Box : public Rect {
    double height;
    char * purpose;
    // length and width are inherited.

    public:
    // member function prototypes.
    Box();
    Box(Box &);
    Box(const char [], const char [], double, double, double);
    ~Box();
    Box & operator=(Box &);

    double getHeight() const;
    void setHeight(double h);
    // Override the getInfo function from Rect.
    void getInfo();
};

#endif

