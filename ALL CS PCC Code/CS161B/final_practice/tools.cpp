//Implememtation file for tools.h
#include "tools.h"

//mainMenu function
//input:
//output:
//return:
//
void mainMenu()
{
	cout << "Please pick an option: " << endl;
	cout << "1. Add a Chick" << endl;
	cout << "2. Remove a Chick" << endl;
	cout << "3. Edit a Chick" << endl;
	cout << "4. Quit" << endl;
}

//read option
int readOption()
{
	int option = 0;
	cin >> option;
	while(!cin || option < 1 || option > 4)
	{
		cout << "Invalid option! Please try again!\n" << endl;
		mainMenu();
		cin.clear();
		cin.ignore(100, '\n');
		cin >> option;
	}
	cin.ignore(100, '\n');
	return option;
}

//exeOtion
void exeOption(int option, ChickType list[], int &size)
{
	bool status = true;
	switch(option)
	{
		//call your functions here.
		case 1:
			status = addChick(list, size);
			if (status == true) {
				cout << "Chick added!" << endl;
			} else {
				cout << "No Chicks Added." << endl;
			}
			break;
		case 2:
			status = removeChick(list, size);
			if (status == true) {
				cout << "Chick(s) Removed." << endl;
			} else {
				cout << "No Chicks Removed." << endl;
			}
			break;
		case 3:
			editChick(list, size);
			break;
		case 4:
			break;
		default:
			cout << "Invalid option!!" << endl;
	}
}

