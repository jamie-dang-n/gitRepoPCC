/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Final Project
# Date:             6/9/2023
# Description:      This program gives basic information about 10 different Video 
#		    Games; the data can be adjusted by removing or adding information.
#		    In particular, the data includes information about the ranking of
#	            the games compared to each other (based on their popularity),
#		    the name of the game, the year the game was released, and the 
#		    system the game was released on. 
# Input:            text file videogames.txt
# Output:           Data about the info in videogames.txt, output may also be 
#		    printed to output-games.txt
# Sources:          Final Project Specifications
#******************************************************************************/

#include "GameData.h"
#include "tools.h"

// Main
int main() {
	// Variables
	ifstream inFile;
	ofstream outFile;
	char inFileName[MAXCHAR] = "videogames.txt";
	char outFileName[MAXCHAR] = "output-games.txt";
	GameData games[CAP];
	int count = 0;
	char option;
	int exeStatus = 0;

	// Open Files
	openFile(inFileName, inFile);
	openFile(outFileName, outFile);

	// Load in Data
	loadData(inFile, games, count);

	// Welcome Message
	welcome();

	// Input/Menu Loop
	do
	{
		displayMenu();
		readOption(option);
		exeStatus = exeOption(games, count, option, outFile);
	} while ((exeStatus) != 1);

	// Close Files
	outFile.close();
	inFile.close();

	return 0;
}
