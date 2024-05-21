// Author: Jamie Dang
// Date: 
// Program Number:
// Purpose: header file for main.cpp
// Module name: main.h

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <limits>
#include "bst.h"

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
void exeMenu(int option, BST& aTree, Website sites[], int & numFound);
bool exeRemoveTopic(BST& aTree);
void exeAdd(BST& aTree);
void exeDisplayTopic(BST& aTree);
void exeRetrieve(BST& aTree, Website sites[], int & numFound);
void exeEdit(BST & aTree);

#endif
