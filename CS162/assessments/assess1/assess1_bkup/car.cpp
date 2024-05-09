/* Car class implementation file
 * CS162 Summer 2023, assessment files */

#include "car.h"
#include <cstring>

// Default constructor.
Car::Car() {
    listPrice = 0.0;
    dealerCost = 0.0;
    year = 0;
    strcpy(makeModel, "No make and model");
}

// All the getters for listPrice, dealerCost, and makeModel, and year.
double Car::getListPrice() const {
    return listPrice;
}

double Car::getDealerCost() const {
    return dealerCost;
}


const char * Car::getMakeModel() const {
    return makeModel;
}

int Car::getYear() const {
    return year;
}
 
// All the setters for listPrice, dealerCost, makeModel and year.
void Car::setListPrice(double priceArg) {
    listPrice = priceArg;
}

void Car::setYear(int yearArg) {
    year = yearArg;
}

void Car::setMakeModel(char * makeModelArg, int strSize) {
    strncpy(makeModel, makeModelArg, strSize);
}

void Car::setDealerCost(double costArg) {
    dealerCost = costArg;
}

// This function calculates the revenue of the car
double Car::calculateRevenue() const {
	double revenue = listPrice - dealerCost;
	return revenue;
}




