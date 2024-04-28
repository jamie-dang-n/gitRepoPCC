#pragma once
#ifndef TOOLS_H
#define TOOLS_H

#include "GameData.h"

// Function Prototypes

// Prints Welcome Message
void welcome();

// Displays Menu
void displayMenu();

// Reads in the user's selection
void readOption(char& option);

// Validates user's selection
bool validateOption(const char option);

// Executes the menu options
int exeOption(GameData games[], int &count, const char option, ofstream& outFile);

// Receives integer input
int getInt(char prompt[], int count);

// Converts char array to lowercase
void toLowerCase(char phrase[]);
#endif
