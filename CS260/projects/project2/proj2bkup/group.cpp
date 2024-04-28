#include "group.h"

Group::Group() : name(nullptr), num(0), specialInfo('n'), wantPromo(0){
}

Group::Group(char * name, int num, char specialInfo, bool wantPromo) {
	setName(name);
	setNum(num);
	setSpecialInfo(specialInfo);
	setWantPromo(wantPromo);
}

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


