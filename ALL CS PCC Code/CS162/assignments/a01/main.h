#ifndef MAIN_H
#define MAIN_H

#include "task.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <limits> // for cin.ignore
using namespace std;

// Constants
const int CAP = 30;

// Function Prototypes
void welcome();
void displayMenu();
char getOption();
bool validOption(char option);
bool checkInt(const int num, const int identifier);
int getInt(int identifier, char prompt[], char error[]);
void makeLower(char phrase[]);
void exeMenu(Task tasks[], int &count);
#endif
