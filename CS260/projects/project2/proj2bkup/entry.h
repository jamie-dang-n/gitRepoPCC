// Author: Jamie Dang
// Date: 5/3/24
// Program Number: CS260 Project 2
// Purpose: Header file for entry class to hold data for stack ADT
// Module Name: entry.h (header file for entry.cpp)

#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <cstring>

using namespace std;

class Entry {
	public:
		// Entry Constructors
		Entry();
		Entry(const char * clientName, const char * clientEmail);
		Entry(const Entry& anEntry);	

		// Entry Destructor
		~Entry();

		// Getters
		const char * getFullName();
		const char * getEmail();

		// Setters
		void setFullName(const char *);
		void setEmail(const char *);

		// Operator
		const Entry & operator=(const Entry& anEntry);
		friend ostream& operator<< (ostream& out, const Entry& anEntry);
	private:
		// Entry Data Members
		char * fullName;
		char * email;


};

#endif
