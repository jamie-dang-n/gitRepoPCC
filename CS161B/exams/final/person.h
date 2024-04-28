//struct for PersonType
#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const int MAX_CHAR = 101;
const int CAPACITY = 20;

struct PersonType
{
	char name[MAX_CHAR];
	char citizenship[MAX_CHAR];
	int age;
};

//function prototypes
void populatePersons(PersonType list[], int& count, const char fileName[]);
void printPersons(const PersonType list[], int count);
bool addPerson(PersonType list[], int &count);
void getInt(int &num);
