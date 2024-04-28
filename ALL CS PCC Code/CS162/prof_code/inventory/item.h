/* inventory item header file
 * Robert Martin, CS162 Su23
 */

#ifndef item_h
#define item_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

const int strSize = 100;  // STR_SIZE
//const int arrSize = 10;


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
    InvItem(const char name[], int count, double price); // constructor that takes arguments. overloading.
    InvItem(char name[], int count, double price); // constructor that takes arguments. overloading.
    InvItem();  // default constructor, no arguments. overloading - change the signature.
    InvItem(InvItem &); // copy constructor.
    ~InvItem(); // tilde, destructor, can have only one, unlike constructors.
    void loadItem(); // prototype, member function, makes this an object
    const InvItem & operator=(const InvItem &); // overload the assignment operator.
    InvItem operator+(const InvItem &) const;
    //friend InvItem operator+(const InvItem & item1, const InvItem & item2);  // item1 + item2;
    friend ostream & operator<<(ostream & out, const InvItem & theItem); // cout << item3; infix
    // fuctional notation: <<(cout, item3);
    // friend functions can have direct access to private members.
    // member functions can directly access other members.
    friend bool operator==(const InvItem & item1, const InvItem & item2); 
};

#endif

