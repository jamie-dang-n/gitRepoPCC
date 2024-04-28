// The GameData Struct
#pragma once
#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <limits>
#include <cctype>

using namespace std;

// Constants
const int MAXCHAR = 101;
const int CAP = 50;

// GameData Struct
struct GameData {
	char gameName[MAXCHAR];
	char platform[MAXCHAR];
	int rank;
	int releaseYear;

};

// Function Prototypes

// Open inFile
void openFile(char fileName[], ifstream& inFile);

// Open outFile, overloaded function with the above
void openFile(char fileName[], ofstream& outFile);

// Read data in from file, and calculate count of lines
void loadData(ifstream& inFile, GameData games[], int& count);

// Add a game to the games[] array
void addGame(GameData games[], int& count);

// Remove a game from the games[] array
void removeGame(GameData games[], int& count);

// Find a game based off its name in the games[] array
void findGame(const GameData games[], const int count);

// Find the oldest game in the games[] array
void findOldest(const GameData games[], const int count);

// Print game data to the console
void printData(const GameData games[], const int count);

// Write game data to a file, overloaded function with the above
void printData(const GameData games[], const int count, ofstream& outFile);

// Print one line of data from the dataset
void printLine(const GameData games[], int pos);
#endif
