/* inventory item header file
 * Robert Martin, CS162 Su23
 */

#ifndef item_h
#define item_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

const int strSize = 100;  // STR_SIZE
const int arrSize = 10;


// Class to contain one inventory item.
// POD, plain old data, PDS - passive data structure, trivial data structure.
// Abstract data type
class InvItem { // default private for a class.
    int count; // initialization is available after C++11 (2011). int count = 0;
    double price; // double price = 0.0; Values set in the constructor.
    char * name; // c-string, not a string object. name is a char *.

    public:
    double getPrice() const; // accessor for price.
    int getCount() const;    // accessor for count.
    void setCount(int count);
    const char * getName() const;  // accessor for name that returns a constant pointer.
    void getName(char * copyDestination, int size) const; // accessor that makes a copy.
    void setName(char * nameArg);
    InvItem(char name[], int count, double price); // constructor that takes arguments. overloading.
    InvItem();  // default constructor, no arguments. overloading - change the signature.
    ~InvItem(); // tilde, destructor, can have only one, unlike constructors.
    void loadItem(); // prototype, member function, makes this an object
    // member functions can directly access other members.
};

#endif

