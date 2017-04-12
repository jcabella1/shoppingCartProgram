/*
 * Date.hpp
 *
 *  Created on: Mar 1, 2017
 *      Author: Jenny
 */

#ifndef DATE_HPP_
#define DATE_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
private:
	int Year;
	int Month;
	int Day;
public:
	Date();
	Date(int theMonth, int theDay, int theYear);
	virtual ~Date();

	bool setYear(int);
	bool setMonth(int);
	bool setDay(int);

	int getYear(void);
	int getMonth(void);
	int getDay(void);

	string getDateString(void);
};

#endif /* DATE_HPP_ */
