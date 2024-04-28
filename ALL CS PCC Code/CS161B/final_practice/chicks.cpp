//This file builds a struct for chicks
//And has some function implementations

#include "chicks.h"

//readInput
void readInput(ChickType chicks[], int &size)
{
	ifstream inFile;
	ChickType aChick;
	inFile.open("chicks.txt");
	//make sure file opens
	inFile.ignore(100, '\n');
	inFile.getline(aChick.breed, MAXCHAR, ';');
	while(!inFile.eof())
	{
		inFile >> aChick.feed;
		inFile.ignore(5, ';');	
		inFile.getline(aChick.eggColor, MAXCHAR, '\n');
		if(size < CAP)
		{
			chicks[size++] = aChick;
		}		
		else
		{
			cout << "List full!" << endl;
			inFile.close();
			return;
		}
		inFile.getline(aChick.breed, MAXCHAR, ';');
	}
	inFile.close();
}


// Sorts the list so that the addChick algorithm will insert sorted
//void sortList(ChickType list[], int size) {
//	ChickType min = list[0];
//	ChickType temp;
//	int i = 0;
//	int j = 0;
//	int pos = 0;
//	for (i = 0; i < size; i++) {
//		for (j = i + 1; j < size; j++) {
//			if (list[j].breed[0] < min.breed[0]) {
//				min = list[j];
//				pos = j;
//			}		
//			if (i != pos) {
//				temp = list[i];
//				list[i] = min;
//				list[j] = temp;		
//			}
//		}
//	}
//}

//output data
void outputData(const ChickType chicks[], int size)
{
	cout << endl;
	for(int i = 0; i < size; i++)
	{
		printAChick(chicks[i]);
	}
	cout << endl;
}

//prints a single line of data
void printAChick(ChickType aChick)
{
	cout << aChick.breed << ";";
	cout << aChick.feed << ";" << aChick.eggColor << endl;
}


//Name:   addChick()
//Desc:   This functon adds a chick to the list, in alphabetical manner.
//input:  ChickType list[], int &count
//output: error messages, input prompts
//return: boolean value
bool addChick(ChickType list[], int &count) {
	ChickType userChick;
	int pos = count;
	if (count != CAP) {
		cout << "Enter the name of the chick breed: ";
		cin.getline(userChick.breed, MAXCHAR, '\n');
		cout << "Enter the feed amount: ";
		cin >> userChick.feed;
		// Input Validation Loop
		while (!cin || cin.peek() != '\n') {
			cout << "Error: Please enter a valid feed amount." << endl;
			cout << "Enter the feed amount: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> userChick.feed;
		}
		cin.ignore(100, '\n');
		cout << "Enter the egg color: ";
		cin.getline(userChick.eggColor, MAXCHAR, '\n');
		for (int i = 0; i < count; i++) {
			if (userChick.breed[0] < list[i].breed[0]) {
				pos = i;
				break;
			}
		}
		for (int j = count; j > pos; j--) {
			list[j] = list[j - 1];
		}
		list[pos] = userChick;
		count++;
		return true;
	} else {
		return false;
	}
}


//Name:   removeChick()
//Desc:   This functon removes a chick from the list
//input:  ChickType list[], int &count
//output: prompt for breed name, removal warning
//return: boolean value
bool removeChick(ChickType list[], int &count) {
	int pos = -1;
	char userBreed[MAXCHAR];
	cout << "Enter the name of the breed to remove: ";
	cin.getline(userBreed, MAXCHAR, '\n');
	cout << "Warning! All chicks that belong to the breed will be removed." << endl;
	for (int i = 0; i < count; i++) {
		if (strcmp(list[i].breed, userBreed) == 0) {
			pos = i;
			for (int j = pos; j < count - 1; j++) {
				list[j] = list[j + 1];
			}
			count--;
		}	
	}
	if (pos == -1) {
		return false;
	} else {
		return true;
	}
}

//Name:   editChick()
//Desc:   This functon edits a ChickType item within the list based on index value
//input:  ChickType list[], int count
//output: prompt for member data, error messages
//return: none
void editChick(ChickType list[], int count) {
	int index = 0;
	getIndex(index, count);
	cin.ignore(100, '\n');
	cout << "Enter the name of the chick breed: ";
	cin.getline(list[index].breed, MAXCHAR, '\n');
	cout << "Enter the feed amount: ";
	cin >> list[index].feed;
	// Input Validation Loop
	while (!cin || cin.peek() != '\n') {
		cout << "Error: Please enter a valid feed amount." << endl;
		cout << "Enter the feed amount: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> list[index].feed;
	}
	cin.ignore(100, '\n');
	cout << "Enter the egg color: ";
	cin.getline(list[index].eggColor, MAXCHAR, '\n');	
}

//Name:   getIndex()
//Desc:   This functon receives an index number from the user, to edit a chick
//	  in the list.
//input:  int &num, int count
//output: prompt for the index, error message
//return: none
void getIndex(int &num, int count){
	cout << "Enter the index of the chick to edit: ";
	cin >> num;
	while (!cin || cin.peek() != '\n' || (num < 0 && num >=count)) {
		cout << "Error: Please enter a valid number." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> num;
	}
}
