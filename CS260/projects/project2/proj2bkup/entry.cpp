// Author: Jamie Dang
// Date: 5/3/24
// Program Number: Project 2
// Purpose: implements entry class methods
// Module Name: entry.cpp (implementation file for entry.h)

#include "entry.h"

// Default Constructor
Entry::Entry() : fullName(nullptr), email(nullptr) {
	setFullName("n/a");
	setEmail("n/a");
}



// Parameterized Constructor -- initializes each data member
Entry::Entry(const char * clientName, const char * clientEmail) : fullName(nullptr), email(nullptr)  {
	setFullName(clientName);
	setEmail(clientEmail);
}



// Copy Constructor
Entry::Entry(const Entry& anEntry) : fullName(nullptr), email(nullptr) {
	setFullName(anEntry.fullName);
	setEmail(anEntry.email);
}



// Destructor
Entry::~Entry() {
	if (fullName) {
		delete[] fullName;
	}

	if (email) {
		delete[] email;
	}
	fullName = nullptr;
	email = nullptr;
}



// Getters
const char * Entry::getFullName() {
	return fullName;
}



const char * Entry::getEmail() {
	return email;
}



// Setters
void Entry::setFullName(const char * clientName) {
	if (fullName) {
		delete[] fullName;
	}

	fullName = new char[strlen(clientName) + 1];
	strcpy(fullName, clientName);
}



void Entry::setEmail(const char * clientEmail) {
	if (email) {
		delete[] email;
	}

	email = new char[strlen(clientEmail) + 1];
	strcpy(email, clientEmail);
}



// Assignment operator overload
const Entry & Entry::operator=(const Entry& anEntry) {
	setFullName(anEntry.fullName);
	setEmail(anEntry.email);
	return *this;
}



// Insertion operator overload
ostream& operator<< (ostream& out, const Entry& anEntry) {
	out << "Full Name: " <<  anEntry.fullName << endl;
	out << "Email: " << anEntry.email << endl;
	return out;
}

