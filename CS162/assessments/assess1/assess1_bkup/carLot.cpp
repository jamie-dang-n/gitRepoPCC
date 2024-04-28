/* carLot implementation file
 * CS162 Summer 2023, assessment files */

#include "carLot.h"

// Default constructor
CarLot::CarLot() {
    carCount = 0;
}

// Getter for carCount. There is no setter (can only be changed by adding new cars).
int CarLot::getCarCount() const {
    return carCount;
}

// Print the inventory. It uses column output using setw().
void CarLot::printCars() const {
    cout << setprecision(2) << fixed << showpoint;
    cout << setw(25) << left << "Make and Model" << setw(15) << right << "List Price" <<
        setw(15) << "Dealer Cost" << setw(10) << "Year" << endl;
    cout << setw(25) << left << "-------------" << setw(15) << right << "----------" <<
        setw(15) << "-----------" << setw(10) << "----" << endl;

    for(int i = 0; i < carCount; i++) {
        cout << left <<  i + 1 << ". " << setw(20) << inventory[i].getMakeModel() <<
            right << setw(9) << "$" << inventory[i].getListPrice() << setw(6) <<
            "$" << inventory[i].getDealerCost() << setw(11) <<
            inventory[i].getYear() << endl;
    }
}

// The function to load cars from the file into the inventory array.
// There is no write file function.
bool CarLot::loadCars() {
    bool success = false;
    char makeModel[STR_SIZE];
    double price = 0.0, cost = 0.0;
    int year = 0;
    inFile.open(fileName);

    if(inFile.is_open()) {
        while(!inFile.eof() && carCount < ARRAY_SIZE) {
            inFile.getline(makeModel, STR_SIZE, ';');
            inFile >> price;
            inFile.ignore(); // throw away the semicolon.
            inFile >> cost;
            inFile.ignore(); // throw away the semicolon.
            inFile >> year;
            inFile.ignore(); // throw away the newline.
            inventory[carCount].setMakeModel(makeModel, STR_SIZE);
            inventory[carCount].setListPrice(price);
            inventory[carCount].setDealerCost(cost);
            inventory[carCount].setYear(year);
            carCount++;
            inFile.peek(); // Check for the eof marker.
        }
        success = true;
    }
    return success;
}

// This function calculates the total potential revenue of selling all cars on the lot
double CarLot::totalRevenue() const {
	double total = 0;
	double currRev = 0;
	for (int i = 0; i < carCount; i++) {
		currRev = inventory[i].calculateRevenue();
		total += currRev;
	}	
	return total;
}

