// Jamie Dang - groceryList.h
/* GroceryList Header file
 * CS162 Summer 2023 Assessment Files */

#ifndef GROCERY_LIST
#define GROCERY_LIST
#include "item.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits> // for cin.ignore
using namespace std;

const int ARRAY_SIZE = 20;

class GroceryList {
	Item ** items;  // Dynamic array of pointers. Set in constructor.
	int itemCount;
	int capacity;  // Set in constructor.
	char fileName[STR_SIZE] = "groceryList.txt";
	ifstream inFile;

	public:
	GroceryList();
	~GroceryList();
	int getItemCount();
	bool loadItems();
	void printItems();
	void grow();
	// Add any new function prototypes here.
	void addItem();
};

#endif
