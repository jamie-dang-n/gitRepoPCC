/* Grocery item header file
 * CS162 Summer 2023, assessment files */

#ifndef ITEM
#define ITEM
#include <iostream>
#include <iomanip>
using namespace std;
const int STR_SIZE = 100;

class Item {
    double price;
    int count;
    char * name;
    
    public:
    Item();
    Item(const char * nameArg, double priceArg, int countArg);
    Item(const Item & otherItem);
    ~Item();
    double getPrice();
    int getCount();
    const char * getName();
    void setPrice(double);
    void setCount(int);
    void setName(const char *);
    Item & operator=(const Item & otherItem);
    friend ostream & operator<<(ostream & out, const Item &);
    // Add any new function prototypes here.
};

#endif
