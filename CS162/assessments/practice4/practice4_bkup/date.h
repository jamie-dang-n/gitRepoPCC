#pragma once
#include <ctime>
#include <iostream>
using namespace std;

class Date
{
private:
	time_t	rawTime;

public:
	Date();
	Date(int year, int month, int day);

	int getYear() const;
	int getMonth() const;
	int getDay() const;
	ostream& print(ostream& out) const;
	bool operator< (const Date& right) const;

	bool setDate(int year, int month, int day);
};

ostream& operator<< (ostream& out, const Date& aDate);
