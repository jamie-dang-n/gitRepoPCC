/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Linux Lab 1
# Date:             5/9/2023
# Description:      This is Linux Lab1.
# Input:            
# Output:           
# Sources:          Lab 1 Video
#******************************************************************************/
#include <iostream>
#include <limits> // for cin.ignore()
using namespace std;

int main() {
	int num = 0;
	cout << "Please enter a number: ";
	cin >> num;
	while (!cin || cin.peek() != '\n') {
		cout << "Bad number! Try again!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a number: ";
		cin >> num;
	}
	cout << "You entered " << num << "." << endl;
	return 0;
}


