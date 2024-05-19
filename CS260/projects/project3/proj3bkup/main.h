// Author: Jamie Dang
// Date: 5/14/2024
// Program Number: CS260 Project 3
// Purpose: header file for main.cpp
// Module name: main.h

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <limits>
#include "table.h"

using namespace std;


// Constants
const int MENU_OPTIONS = 1;
const int RATING_OPTIONS = 2;
const int MAX_CHAR = 101;
const int NUM_SITES = 50;

// Function Prototypes
void welcome();
void displayMenu();
int getInt(const int id);
bool validInt(const int id, int num);
void exeMenu(int option, Table& aTable, Website sites[], int & numFound);
void exeAdd(Table& aTable);
void exeDisplayTopic(Table& aTable);
void exeRetrieve(Table& aTable, Website sites[], int & numFound);
void exeEdit(Table & aTable);

#endif
