/*
 * Date.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: Jenny
 */

#include "Date.hpp"

Date::Date()
{
	cout << "You are creating a Date Object" << endl;
	Year = 1970;
	Month = 1;
	Day = 1;
}
Date::Date(int theMonth, int theDay, int theYear)
{
	cout << "You are creating a Date Object" << endl;
	Month = theMonth;
	Day = theDay;
	Year = theYear;
}

bool Date::setYear(int anInt)
{
	bool returnValue = true;

	Year = anInt;

	return returnValue;
}
bool Date::setMonth(int anInt)
{
	bool returnValue = true;

	Month = anInt;

	return returnValue;
}
bool Date::setDay(int anInt)
{
	bool returnValue = true;

	Day = anInt;

	return returnValue;
}

int Date::getYear(void)
{
	return Year;
}
int Date::getMonth(void)
{
	return Month;
}
int Date::getDay(void)
{
	return Day;
}

string Date::getDateString()
{
	 ostringstream convert;

	 string yearString;
	 string monthString;
	 string dayString;

	 convert << setfill('0') << setw(2); // zero padding
	 convert << getMonth();
	 monthString = convert.str();
	 convert.str("");

	 convert << setfill('0') << setw(2); // zero padding
	 convert << getDay();
	 dayString = convert.str();
	 convert.str("");

	 convert << getYear();
	 yearString = convert.str();
	convert.str("");


	 return monthString + "/" + dayString + "/" + yearString;
}

Date::~Date() {
	Year = 0;
	Month = 0;
	Day = 0;
	cout << "You are deleting a Date Object!" << endl;
}

