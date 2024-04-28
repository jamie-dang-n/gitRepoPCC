// Jamie Dang -- main.h 
#ifndef MAIN_H
#define MAIN_H

#include "tasklist.h"
#include <cctype>
using namespace std;

// Function Prototypes
void welcome();
void displayMenu();
void getOption(char &option);
void exeMenu(char option, TaskList &tasks, char fileName[]);
bool validOption(char option);
// Tester Code
void testerCode();
void printTask(Task &aTask, char aName[]);
#endif
