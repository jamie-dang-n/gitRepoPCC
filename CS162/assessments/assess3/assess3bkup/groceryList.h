/* GroceryList Header file
 * CS162 Summer 2023 Assessment Files */

#ifndef GROCERY_LIST
#define GROCERY_LIST
#include "item.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits> // for cin.ignore()
using namespace std;

struct Node {
	Item item;
	Node * next;
};

class GroceryList {
	Node * head;  // Dynamic array of pointers. Set in constructor.
	int itemCount;
	char fileName[STR_SIZE] = "groceryList.txt";
	ifstream inFile;
	// Private helper functions - number validation
	void validateNum(double &);
	void validateNum(int &);

	public:
	GroceryList();
	~GroceryList();
	int getItemCount();
	bool loadItems();
	void printItems();
	// Add any new function prototypes here.
	Item getMaxPriceItem();
	void addSecond();

	
};

#endif
