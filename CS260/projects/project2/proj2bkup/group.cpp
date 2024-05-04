// Author: Jamie Dang 
// Date: 5/3/24
// Program Number: CS260 Project 2
// Purpose: Implements group class methods
// Module Name: group.cpp (implementation file for group.h)

#include "group.h"

// Default Constructor
Group::Group() : name(nullptr), num(0), specialInfo('n'), wantPromo(0){
}



// Parameterized Constructor -- iniitalizes each data member
Group::Group(const char * name, int num, char specialInfo, bool wantPromo)
				: name(nullptr), num(0), specialInfo('n'), wantPromo(0){
	init(name, num, specialInfo, wantPromo);
}



// Copy Constructor
Group::Group(const Group& aGroup) {
	name = new char[strlen(aGroup.name) + 1];
	*this = aGroup;	
}



// Destructor
Group::~Group() {
	// Setting non-dynamic variables to null values
	num = 0;
	wantPromo = false;
	specialInfo = '\0';

	// deleting dynamic memory
	if (name) {
		delete [] name;
	}
	name = nullptr;
}



// Setters
void Group::setName(const char * name) {
	if (this->name) {
		delete[] this->name;
		this->name = nullptr;
	}

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

bool Group::setNum(const int num) {
	bool success = false;
	if (num > 0) {
		this->num = num;
		success = true;
	}
	return success;
}

bool Group::setSpecialInfo(const char specialInfo) {
	bool success = false;
	char temp = specialInfo;
	temp = tolower(temp);
	if (temp == 'h' || temp == 'w' || temp == 'n') {
		this->specialInfo = temp;
		success = true;
	}
	return success;
}

void Group::setWantPromo(const bool wantPromo) {
	this->wantPromo = wantPromo;
}



// Getters
const char * Group::getName() const {
	return name;
}

int Group::getNum() const {
	return num;
}

char Group::getSpecialInfo() const {
	return specialInfo;
}

bool Group::getWantPromo() const {
	return wantPromo;
}



// Private Methods

// Name: init
// Purpose: initializes each data member by calling all setters
// Input: const char * name, int num, char specialInfo, bool wantPromo
// Output: none
// Return: none
void Group::init(const char * name, int num, char specialInfo, bool wantPromo) {
	setName(name);
	setNum(num);
	setSpecialInfo(specialInfo);
	setWantPromo(wantPromo);
}



// Assignment Operator Overload
const Group& Group::operator= (const Group& aGroup) {
	if (this == &aGroup) {
		return *this;
	}	
	init(aGroup.name, aGroup.num, aGroup.specialInfo, aGroup.wantPromo);
	return *this;
}



// Insertion Operator Overload
ostream& operator<< (ostream& out, const Group& aGroup) {
	out << "\"" << aGroup.name << "\"" << ", " << aGroup.num << " person(s), ";
	switch (aGroup.specialInfo) {
		case 'w':
			out << "wheelchair";
			break;
		case 'h':
			out << "high chair";
			break;
		case 'n':
			out << "no special seating";
			break;
	}
	out << ", ";
	if (aGroup.wantPromo) {
		out << "wants promo." << endl;
	} else {
		out << "no promo." << endl;
	}
	return out;
}
