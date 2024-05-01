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
		char * name;
		int num;	
		char specialInfo;
		bool wantPromo;
		void init(const char *, int, char, bool);
};

#endif
