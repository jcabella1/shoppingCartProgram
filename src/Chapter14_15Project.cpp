//*****************
//Project Name: Chapter 14/15 Project
//Project Description: A shopping cart program -- reads to and from simple text files
//Project Author: Abella, Jenny
//Is this an extra credit Project:  No
//Date completed: 04/25/2017
//Operating system used: Windows 10
//IDE Used:  Eclipse Neon


//*****************
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Order.hpp"
#include "Customer.hpp"
using namespace std;

void readCustomerFile(ifstream &, vector<Customer*> &);
void readOrderFile(ifstream &, vector<Order*> &);
void printOrders(vector<Order*>);

int main(int argc, char *argv[]) {
	vector<Customer*> theCustomers;
	vector<Order*> theOrders;
	vector<OrderItem*> theOrderItems;

	//file name variables
	string orderFile = "OrderFile.txt";
	string customerFile = "CustomerFile.txt";

	ifstream inputFile;

	inputFile.open(customerFile.c_str());

	if (inputFile.fail())
	{
		cout << "Could not open file " << customerFile << ". Program is ending" << endl;
		cout << "Program ended with exit value: -1";
		return -1;
	}//if

	readCustomerFile(inputFile, theCustomers);

	inputFile.close();

	inputFile.open(orderFile.c_str());

	if (inputFile.fail())
	{
		cout << "Could not open file " << orderFile << ". Program is ending." << endl;
		cout << "Program ended with exit value: -1";
		return -1;
	}//if

	readOrderFile(inputFile, theOrders);

	//delete all pointers
	theCustomers.clear();
	for (unsigned int i = 0; i < theCustomers.size(); i++)
	{
		delete theCustomers[i];
	}//for
	theOrders.clear();
	for (unsigned int i = 0; i < theOrders.size(); i++)
	{
		delete theOrders[i];
	}//for

	inputFile.close();

	cout << "Program ending, have a nice day" << endl;
	cout << "Program ended with exit value: 0" << endl;
	return 0;
}//main

void readCustomerFile(ifstream & inFile, vector<Customer*> &theCustomerVector)
{
	while (true)
		{

		if (inFile.fail())
		{
			break;
		}//if
		else
		{
			string tempID;
			string tempName;
			string tempEmail;
			int tempYear;
			int tempMonth;
			int tempDay;

			inFile >> tempID >> tempName >> tempEmail >> tempYear >> tempMonth >> tempDay;

			Customer *aCustomer = new Customer();

			aCustomer->setCustomerNumber(tempID);
			aCustomer->setCustomerName(tempName);
			aCustomer->setEmail(tempEmail);
			aCustomer->setDateJoined(tempMonth, tempDay, tempYear);

			theCustomerVector.push_back(aCustomer);
		}//else
	}//while

}//readCustomerFile

//
// Read orders from the input stream
//
void readOrderFile(ifstream &inFile, vector<Order*> &theOrderVector)
{
	while (true)
	{
		if (inFile.fail())
		{
			break;
		}//if
		else
		{
			string tempOrderNumber;
			int tempYear;
			int tempMonth;
			int tempDay;
			string tempCustomerID;

			inFile >> tempOrderNumber >> tempYear >> tempMonth >> tempDay;

			Order *tempOrder = new Order();

			tempOrder->setOrderNumber(tempOrderNumber);
			tempOrder->setOrderDate(tempDay, tempMonth, tempYear);
			tempOrder->getOrderCustomer().setCustomerNumber(tempCustomerID);
			theOrderVector.push_back(tempOrder);

		}//else
	}//while

}//readOrderFile

//
// Prints all of the orders
//
void printOrders(vector<Order*> theOrderVector)
{
	cout << setw(15) << "Order Number" << setw(15) << "Order Date" << setw(15) << "Customer Number" << endl;
	for (int i = 0; i < theOrderVector.size(); i++)
	{
		cout << setw(15) << theOrderVector[i]->getOrderNumber << setw(15) << theOrderVector[i]->getOrderDate().getYear();
	}//for

}//printOrders
