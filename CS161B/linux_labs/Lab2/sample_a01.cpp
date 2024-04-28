//This program demos loops, conditions and some functions.
//A program to ask the user for coffee sizes and sell coffee
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//constants
const double SMALL = 2.50;
const double MED = 3.25;
const double LARGE = 4.50;

int main()
{
	char coffeeSize = '\0';
	int quantity = 0;
	double price = 0;

	cout << "Please enter the size of the coffee:" << endl;
	cout << "(s) Small, (m) Medium, (l) Large :" << endl;
	cout << ">>";
	cin >> coffeeSize;
	coffeeSize = tolower(coffeeSize);
	while(coffeeSize != 's' && coffeeSize != 'm' && coffeeSize != 'l')
	{
		cout << "Invalid input!! Please try again!" << endl;
		cout << "Please enter the size of the coffee: " << endl;
		cin >> coffeeSize;
		coffeeSize = tolower(coffeeSize);
	}
	cout << "Enter quantity of coffee: ";
	cin >> quantity;	
	if(coffeeSize == 's')
	{
		price += (quantity * SMALL);
	}
	else if(coffeeSize == 'm')
	{
		price += (quantity * MED);
	}
	else if(coffeeSize == 'l')
	{
		price += (quantity * LARGE);
	}

	//output the price
	cout << fixed << showpoint << setprecision(2);
	cout << "Your total coffee price is $" << price << endl;

	return 0;
}
