/*
 * Customer.hpp
 *
 *  Created on: Apr 4, 2017
 *      Author: Jenny
 */

#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_
#include <iostream>
#include "Date.hpp"

using namespace std;

class Customer {
public:
	Customer();
	virtual ~Customer();

	Date getDateJoined(void);
	void setDateJoined(int month, int day, int year);
	string getCustomerNumber(void);
	void setCustomerNumber(string);
	string getCustomerName(void);
	void setCustomerName(string);
	string getEmail(void);
	void setEmail(string);

private:
	string CustomerNumber;
	string CustomerName;
	string email;
	Date DateJoined;
};

#endif /* CUSTOMER_HPP_ */
