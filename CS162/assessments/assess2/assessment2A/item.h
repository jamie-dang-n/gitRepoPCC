// Jamie Dang - item.h
/* Grocery item header file
 * CS162 Summer 2023, assessment files */

#ifndef ITEM
#define ITEM

const int STR_SIZE = 100;

class Item {
	double price;
	int count;
	char * name;

	public:
	Item();
	~Item();
	double getPrice();
	int getCount();
	const char * getName();
	void setPrice(double);
	void setCount(int);
	void setName(const char *);
	// Add any new function prototypes here.
	// Copy Constructor
	Item(const Item & otherItem);
};

#endif
