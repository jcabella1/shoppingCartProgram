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
void readOrderFile(ifstream &, vector<Order*> &, vector<Customer*>);
void printOrder(vector<Order*>);

int main(int argc, char *argv[]) {
	vector<Customer*> theCustomers;
	vector<Order*> theOrders;

	//file name variables
	string orderFile = "OrderFile.txt";
	string customerFile = "CustomerFile.txt";

	//Create ifstream
	ifstream inputFile1;

	//
	//Open customers file
	//
	inputFile1.open(customerFile.c_str());

	if (inputFile1.fail())
	{
		cout << "Could not open " << customerFile << ". Program is ending" << endl;
		cout << "Program ended with exit value: -1";
		return -1;
	}//if

	//
	// Read info from customer file
	//
	readCustomerFile(inputFile1, theCustomers);

	inputFile1.close();

	ifstream inputFile2;

	//
	// Open Orders file
	//
	inputFile2.open(orderFile.c_str());
	if (inputFile2.fail())
	{
		cout << "Could not open " << orderFile << ". Program is ending." << endl;
		cout << "Program ended with exit value: -1";
		return -1;
	}//if

	//
	// Now reading data from Orders file
	//
	readOrderFile(inputFile2, theOrders, theCustomers);

	//
	// Prints all orders
	//
	printOrder(theOrders);

//	//
//	// TODO: Commandline arguments
//	//
//	if (argc == 1)
//	{
//
//	}//if
//	else if (argc == 2)
//	{
//
//	}//else if
//	else
//	{
//		cout << "Error, you can only enter 2 arguments" << endl;
//		cout << "Program is ending, have a nice day" << endl;
//		cout << "Program ended with exit value: -1" << endl;
//
//		return -1;
//	}//else


	//
	//delete all pointers
	//
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

	inputFile2.close();

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
void readOrderFile(ifstream &inFile, vector<Order*> &theOrderVector, vector<Customer*> theCustomerVector)
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

			inFile >> tempOrderNumber >> tempYear >> tempMonth >> tempDay >> tempCustomerID;

			//
			//look for the customer ID in the customer vector and point to the customer
			//
			for (unsigned int i = 0; i < theCustomerVector.size(); i++)
			{
				if (theCustomerVector[i]->getCustomerNumber() == tempCustomerID)
				{
					Order *tempOrder = new Order(theCustomerVector[i]);

					tempOrder->setOrderNumber(tempOrderNumber);
					tempOrder->setOrderDate(tempMonth, tempDay, tempYear);

					theOrderVector.push_back(tempOrder);
				}//if
			}//for

		}//else
	}//while

}//readOrderFile

//
// Prints indicated order
//
void printOrder(vector<Order*> theOrderVector)
{
	cout << "Order Report" << endl;
	for (unsigned int i = 0; i < theOrderVector.size(); i++)
	{
		cout << "=====================================" << endl;
		cout << "Order ID" << setw(15) << "Customer ID" << setw(15) << "Order Date" << setw(20) << "Customer" << endl;
		cout << "--------" << setw(15) << "-----------" << setw(15) << "----------" << endl;

			cout << theOrderVector[i]->getOrderNumber() << setw(15)
					<< theOrderVector[i]->getOrderCustomer()->getCustomerNumber() << setw(15)
					<< theOrderVector[i]->getOrderDate().getDateString() << setw(15)
					<< theOrderVector[i]->getOrderCustomer()->getCustomerName() << endl;
	}//for

}//printOrders
