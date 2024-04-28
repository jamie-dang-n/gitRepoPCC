#ifndef GROUP_H
#define GROUP_H

#include <cctype>
#include <cstring>

class Group {
	public:
		// Constructors and Destructors
		Group();
		Group(char *, int, char, bool);
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

	private:
		char * name;
		int num;	
		char specialInfo;
		bool wantPromo;
};

#endif
