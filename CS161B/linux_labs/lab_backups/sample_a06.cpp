//This program reads from items.txt and prints the total calories of each item
//items.txt has 3 columns of data - itemname that can have spaces, quantity - an int
//and calories - an int
//The program will read the data into a 2 dim char array and a 2 dim int array
//It will calculate the total calories for each item and output to screen
//
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//constant for number of items
const int ITEMS = 10;
//constant for number of characters
const int MAXCHAR = 51;

//function prototypes
bool openFile(ifstream &inFile);
int loadData(ifstream &inFile, char items[][MAXCHAR], int otherData[][2]);
void calcCalories(char items[][MAXCHAR], int otherData[][2], int size);

//main function that will call openFile, loadData and calcCalories
int main()
{
	ifstream inFile;
	int size = 0;
	char items[ITEMS][MAXCHAR];
	int otherData[ITEMS][2] = {0};
	if(!openFile(inFile))
	{
		cout << "File did not open! Program terminating!!" << endl;
		exit(0);
	}
	size = loadData(inFile, items, otherData);
	calcCalories(items, otherData, size);
	
	return 0;
}

//Name:			openFile
//Description:	opens the file and returns true or false
//input params:	file stream variable
//ouput:		none
//return:		true or false
//
bool openFile(ifstream &inFile)
{
	inFile.open("items.txt");
	if(!inFile)
	{
		return false;
	}
	return true;
}

//Name:			loadData
//Description: 	loads data from file
//input params:	char array for item names, and int array for other data (2 dim arrays)
//output:		none
//return:		size of the number of items.
//
int loadData(ifstream &inFile, char items[][MAXCHAR], int otherData[][2])
{
	int size = 0;
	//read the first item name outside to check if the file is empty
	inFile.getline(items[size], MAXCHAR, ';');
	while(!inFile.eof())
	{
		//read the next 2 int data into the int 2 dim array
		inFile >> otherData[size][0];
		inFile.ignore(5, ';');
		inFile >> otherData[size][1];
		inFile.ignore(5, '\n');
		//increment size for next item
		size++;
		//read next item name from the next line in the text file
		inFile.getline(items[size], MAXCHAR, ';');
	}
	return size;
}
		
//Name:			calcCalories
//Description:	calculates total calories from the 2 arrays and outputs to screen
//input params:	size, the 2 arrays
//output:		total calories for each item and other info
//return:		none
//
void calcCalories(char items[][MAXCHAR], int otherData[][2], int size)
{
	//tempCalories to calc total calories for each line
	int tempCalories = 0;
	for(int i = 0; i < size; i++)
	{
		//calculate total calories for each line
		tempCalories = otherData[i][0] * otherData[i][1];
		//output each line
		cout << items[i] << ";" << tempCalories << endl;
	}
	cout << "Thank you!!" << endl;
}
