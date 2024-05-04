// Author: Jamie Dang
// Date: 5/3/24
// Program Number: CS260 Project 2
// Purpose: Header file for main.cpp
// Module Name: main.h (header file for main.cpp)

#include <iostream> 
#include <fstream>
#include "queue.h"
#include "stack.h"
#include <limits> // for cin.ignore

using namespace std;

// Constants
const int MAXCHAR = 101; 	// Max length of char arrays (for locals)
const int MANAGER_MENU = 1; // index to denote manager menu validity 
const int SEATING = 2;		// index to denote special seating option validity
const int PROMO = 3;		// index to denote promo option validity

// Prototypes
void welcome();
void displayMenu();
void managerMenu();
void exeMenu(const int option, Queue& aQueue, Stack& aStack);
int getInt();
char getChar(const int typeChar);
bool validChar(char aChar, const int typeChar);
void readGroup(Group& returnGroup);
void addStack(Stack& returnStack); 
void exeManager(Stack& aStack);
bool saveToFile(Stack& aStack, const char fileName[]);
