/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Assignment 5
# Date:             5/10/23
# Description:      This program will open a file called “gamedata.txt”, then read 
#		    from it to find the newest and oldest game of the 9 present on 
#		    the dataset. It will also read from the text file to find the 
#		    average year in which the 9 games were released and what game 
#	    	    is the most popular, based on which has the most sales. 
#		    Gamedata.txt has 3 columns, in the following order: 
#		    game name, release year, and North American sales.
# Input:            file gamedata.txt
# Output:           oldest and newest game (by year, ints), the average release year
#		    (double), and the game with the most sales (double).
# Sources:          a05 Specifications and a05 Samples
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

// Constants
const int MAXCHAR = 50;
const int MAXSIZE = 10;

// Function Prototypes
void welcome();
void printData(char gameName[][MAXCHAR], int releaseYear[], double naSales[], int count);
bool openFile(ifstream &inFile);
int loadData(ifstream &inFile, char gameName[][MAXCHAR], int releaseYear[], double naSales[]);
int findOldest(int years[], int count);
int findNewest(int years[], int count);
int findMostSales(double sales[], int count);
int findAvgYear(int years[], int count);
void displayResults(int oldest, int newest, int mostPop, char names[][MAXCHAR], int year[], double sales[], int avg);

// Main()
int main() {
	// inFile and Array Variables
	ifstream inFile;
	char gameNames[MAXSIZE][MAXCHAR] = {0};
	int releaseYear[MAXSIZE] = {0};
	double naSales[MAXSIZE] = {0};
	int count = 0;

	// Variables
	int oldestIdx = 0;
	int newestIdx = 0;
	int mostPopIdx = 0;
	int avgYear = 0;

	// Welcome Message
	welcome();

	// Open File
	if(!openFile(inFile)) {
		cout << "Error: File could not be opened. Program Terminating." << endl;
		exit(0);
	}

	// Calculate Count, oldest/newest game, average release year, and most popular game.
	count = loadData(inFile, gameNames, releaseYear, naSales);
	printData(gameNames, releaseYear, naSales, count);
	oldestIdx = findOldest(releaseYear, count);
	newestIdx = findNewest(releaseYear, count);
	mostPopIdx = findMostSales(naSales, count);
	avgYear = findAvgYear(releaseYear, count);
	
	// Output Results
	displayResults(oldestIdx, newestIdx, mostPopIdx, gameNames, releaseYear, naSales,  avgYear);

	// Close File
	inFile.close();

	return 0;
}


//Name:   welcome()
//Desc:   This function prints out the welcome message and information about
//	  the program.
//input:  none
//output: info about the program, the welcome message
//return: none
void welcome() {
	cout << "Welcome to my File Input/Output Program!" << endl;
	cout << endl; //blank line
	cout << "This program will read game data (game name, release year, North American sales)\nfrom a file and display the oldest game, newest game, most popular game,\nand average release year of games in the dataset." << endl;
	cout << endl; //blank line
	cout << "Name; Release Year; North American Sales (in millions)" << endl;
	cout << endl; //blank line
}

//Name:   printData()
//Desc:   This function prints out the dataset.
//input:  char gameName[MAXCHAR], int releaseYear[], double naSales[], int count
//output: the dataset info
//return: none
void printData(char gameName[][MAXCHAR], int releaseYear[], double naSales[],int count){
	for (int i = 0; i < count; i++) {
		cout << (i + 1) << ": ";
		cout << gameName[i] << "; ";
		cout << releaseYear[i] << "; ";
		cout << naSales[i] << endl;
	}
}

//Name:   openFile()
//Desc:   This function opens the gamedata.txt file.
//input:  ifstream &inFile
//output: none
//return: boolean value (true or false)
bool openFile(ifstream &inFile){
	inFile.open("gamedata.txt");
	if (!inFile.is_open()) {
		return false;
	}
	return true;
}

//Name:   loadData() 
//Desc:   This function loads all the data from "gamedata.txt"
//input:  ifstream &inFile, char gameName[][MAXCHAR], int releaseYear[], double naSales[]
//output: none
//return: int count
int loadData(ifstream &inFile, char gameName[][MAXCHAR], int releaseYear[], double naSales[]){ 
	int count = 0;
	inFile.getline(gameName[count], MAXCHAR, ';');
	while (!inFile.eof()) {
		inFile >> releaseYear[count];
		inFile.ignore(5, ';');
		inFile >> naSales[count];
		inFile.ignore(5, '\n');
		count++;
		inFile.getline(gameName[count], MAXCHAR, ';');
	}
	return count;
}

//Name:   findOldest() 
//Desc:   This function finds the oldest game and returns the index of its location. 
//input:  int years[], int count
//output: none
//return: int oldestIdx
int findOldest(int years[], int count){
	int oldestIdx = 0;
	int oldestYear = years[0];
	for (int i = 0; i < count; i++) {
		if (years[i] < oldestYear) {
			oldestYear = years[i];
			oldestIdx = i;
		}
	}
	return oldestIdx;
}

//Name:   findNewest() 
//Desc:   This function finds the newest game and returns the index of its location.
//input:  int years[], int count
//output: none
//return: int newestIdx
int findNewest(int years[], int count) {
	int newestIdx = 0;
	int newestYear = years[0];
	for (int i = 0; i < count; i++) {
		if (years[i] > newestYear) {
			newestYear = years[i];
			newestIdx = i;
		}
	}
	return newestIdx;
}



//Name:   findMostSales() 
//Desc:   This function finds the game with the most sales in North America.  
//input:  double sales[], int count
//output: none
//return: int mostIdx
int findMostSales(double sales[], int count){
	int mostIdx = 0;
	double mostSales = sales[0];
	for (int i = 0; i < count; i++) {
		if (sales[i] > mostSales) {
			mostSales = sales[i];
			mostIdx = i;
		}
	}
	return mostIdx;
}



//Name:   findAvgYear() 
//Desc:   This function finds the average release year of the dataset. 
//input:  int years[], int count
//output: none
//return: int avgYear
int findAvgYear(int years[], int count) {
	int yearSum = 0;
	int avgYear = 0;
	for (int i = 0; i < count; i++) {
		yearSum += years[i];
	}
	avgYear = yearSum/count;
	return avgYear;
}


//Name:   displayResults()
//Desc:   This function displays the result after data analysis. 
//input:  ints oldest, newest, mostPop, year[]
//	  doubles sales[], avg
//	  char names[][MAXCHAR]
//output: All of the result data-- the oldest game, newest game, most popular game,
//	  and average release year.
//return: none
void displayResults(int oldest, int newest, int mostPop, char names[][MAXCHAR], int year[], double sales[], int avg) {
	cout << endl; // blank line
	cout << "The oldest game is: " << names[oldest] << ", released in " << year[oldest] << "." << endl;
	cout << "The newest game is: " << names[newest] << ", released in " << year[newest] << "." << endl;
	cout << "The most popular game is " << names[mostPop] << ", released in " << year[mostPop] << ". " << endl; 
	cout << names[mostPop] << " reached " << sales[mostPop] << " million sales in North America." << endl;
	cout << "The average year in which these games were released is " << avg << "." << endl;
	cout << endl; // blank line
	cout << "Thank you!" << endl;	
}
