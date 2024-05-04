// Author: Jamie Dang
// Date: 5/3/24
// Program Number: Project 2
// Purpose: Header file for group class to hold data for Queue nodes
// Module Name: group.h (header file for group.cpp)

#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class Group {
	public:
		// Constructors and Destructors
		Group();
		Group(const char *, int, char, bool);
		Group(const Group& aGroup);
		~Group();

		// Setters
		void setName(const char *);
		bool setNum(const int);
		bool setSpecialInfo(const char);
		void setWantPromo(const bool);

		// Getters
		const char * getName() const;
		int  getNum() const;
		char getSpecialInfo() const;
		bool getWantPromo() const;

		// Operators
		const Group& operator= (const Group& aGroup); 
		friend ostream& operator<< (ostream& out, const Group& aGroup);

	private:
		// Group data members
		char * name; 		// Name of Group
		int num;	 		// Number of people in group
		char specialInfo;	// Special seating needs
		bool wantPromo;		// Want/Don't Want promo
		// Private methods
		void init(const char *, int, char, bool);
};

#endif
