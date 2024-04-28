#include "date.h"

Date::Date()
{
	tm *	timeInfo;

	time(&rawTime);
	timeInfo = localtime(&rawTime);
	timeInfo->tm_sec = 0;
	timeInfo->tm_min = 0;
	timeInfo->tm_hour = 0;
	rawTime = mktime(timeInfo);
}

Date::Date(int year, int month, int day):Date::Date()
{
	setDate(year, month, day);
}

int Date::getYear() const
{
	tm *	timeInfo;
	timeInfo = localtime(&rawTime);
	return timeInfo->tm_year + 1900;
}

int Date::getMonth() const
{
	tm *	timeInfo;
	timeInfo = localtime(&rawTime);
	return timeInfo->tm_mon + 1;
}

int Date::getDay() const
{
	tm *	timeInfo;
	timeInfo = localtime(&rawTime);
	return timeInfo->tm_mday;
}

ostream& Date::print(ostream& out) const
{
	const int MAX_CHAR = 80;
	char	dateString[MAX_CHAR];
	tm *	timeInfo;

	timeInfo = localtime(&rawTime);
	strftime(dateString, MAX_CHAR, "%a %F", timeInfo);
	out << dateString;
	return out;
} 

bool Date::setDate(int year, int month, int day)
{
	tm *	timeInfo;
	time_t	tempTime;

	tempTime = time(&tempTime);
	timeInfo = localtime(&tempTime);
	timeInfo->tm_year = year - 1900;
	timeInfo->tm_mon = month - 1;
	timeInfo->tm_mday = day;
	timeInfo->tm_sec = 0;
	timeInfo->tm_min = 0;
	timeInfo->tm_hour = 0;
	tempTime = mktime(timeInfo);
	if(tempTime < 0)
		return false;
	else
	{
		rawTime = tempTime;
		return true;
	} 
}

ostream& operator<< (ostream& out, const Date& aDate)
{
	return aDate.print(out);
}

bool Date::operator< (const Date& right) const
{
	return difftime(right.rawTime, this->rawTime) > 0;
}
