//This is the header file for chicks struct
#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//constants
const int MAXCHAR = 101;
const int CAP = 20;

//definition of main ChickType struct
struct ChickType
{
	char breed[MAXCHAR];
	double feed;
	char eggColor[MAXCHAR];
};

//function prototypes
void printAChick(ChickType aChick);
void readInput(ChickType chicks[], int &size);
void outputData(const ChickType chicks[], const int size);
//add your prototypes to add a chick and remove a chick
bool addChick(ChickType list[], int &count);
bool removeChick(ChickType list[], int &count);
void editChick(ChickType list[], int count);
void getIndex(int &num, int count);
// void sortList(ChickType list[], int &size);
