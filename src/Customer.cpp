/*
 * Customer.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: Jenny
 */

#include "Customer.hpp"
#include <fstream>
#include <iomanip>


Customer::Customer() {
	cout << "Creating customer" << endl;
	this->CustomerNumber = "Unknown";
	this->CustomerName = "Unknown";
	this->email = "Unknown";
	this->DateJoined.setMonth(1);
	this->DateJoined.setDay(1);
	this->DateJoined.setYear(1970);

}//default constructor

Customer::~Customer() {
	cout << "Deleting customer" << endl;
	this->CustomerNumber = "X";
	this->CustomerName = "X";
	this->email = "X";
	this->DateJoined.setMonth(0);
	this->DateJoined.setDay(0);
	this->DateJoined.setYear(0);

}//destructor

Date Customer::getDateJoined(void)
{
	return DateJoined;
}//getDateJoined
void Customer::setDateJoined(int month, int day, int year)
{
	DateJoined.setMonth(month);
	DateJoined.setDay(day);
	DateJoined.setYear(year);
}//setDateJoined
string Customer::getCustomerNumber(void)
{
	return CustomerNumber;
}//getCustomerNumber
void Customer::setCustomerNumber(string aString)
{
	CustomerNumber = aString;
}//setCustomerNumber
string Customer::getCustomerName(void)
{
	return CustomerName;
}//getCustomerName
void Customer::setCustomerName(string aString)
{
	CustomerName = aString;
}//setCustomerName
string Customer::getEmail(void)
{
	return email;
}//getEmail
void Customer::setEmail(string aString)
{
	email = aString;
}//setEmail
