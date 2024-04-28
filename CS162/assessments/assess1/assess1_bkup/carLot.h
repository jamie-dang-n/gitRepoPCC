/* CarLot Header file
 * CS162 Summer 2023 Assessment Files */

#ifndef GROCERY_LIST
#define GROCERY_LIST
#include "car.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int ARRAY_SIZE = 20;

class CarLot {
	Car inventory[ARRAY_SIZE];
	int carCount;
	char fileName[STR_SIZE] = "carInventory.txt";
	ifstream inFile;

	public:
	CarLot();
	int getCarCount() const;
	bool loadCars();
	void printCars() const;
	// Add any new function prototypes here.
	double totalRevenue() const;

};

#endif
