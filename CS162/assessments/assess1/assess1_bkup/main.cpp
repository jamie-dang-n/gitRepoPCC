/* main function file
 * CS162 Summer 2023 assessment files */

#include "main.h"
using namespace std;

// Function main, the driver for the carLot class.
// The function creates a carLot object (dealership), calls the loadCars()
// member function to read cars from a file, and then prints the inventory.
// Your job is to fill in the code to accomplish the assessment tasks.
int main() {
	bool listLoaded = false;
	CarLot dealership;
	listLoaded = dealership.loadCars();

	cout << "\nWelcome to the car lot program.\n";
	if(listLoaded) {
		cout << "Successfully loaded " << dealership.getCarCount() << " cars.\n\n";
		cout << "The cars on the lot are: \n\n";
		dealership.printCars();
	}
	else {
		cout << "An error occured while loading the list of cars.\n";
	}

	// *****************************************
	// Fill in the code for the assessment here.
	// *****************************************
	
	// Displaying Total Car Revenue
	cout << "\nThe total potential revenue of selling all the cars on the lot is: $" << dealership.totalRevenue() << endl;
	


	return 0;
}
