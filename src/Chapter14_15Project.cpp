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
#include "Order.hpp"
#include "Customer.hpp"
using namespace std;

int main() {
	vector<Customer*> theCustomers;
	vector<Order*> theOrders;

	//file name variables
	string orderFile = "OrderFile.txt";
	string customerFile = "CustomerFile.txt";
	string foodItemsFile = "FoodItems.txt";
	string mediaItemsFile = "MediaItems.txt";
	string electronicItemsFile = "ElectronicItems.txt";

	ifstream inputFile;

	inputFile.open(customerFile.c_str());

	if (inputFile.fail())
	{
		cout << "Could not open file " << customerFile << ". Program is ending" << endl;
		cout << "Program ended with exit value: -1";
		return -1;
	}

	while (true)
	{
		Customer *aCustomer = new Customer();

		if (inputFile.fail())
		{
			break;
		}//if
		else
		{
			theCustomers.push_back(aCustomer);
		}//else
	}//while

	inputFile.close();

	inputFile.open(orderFile.c_str());

	if (inputFile.fail())
	{
		cout << "Could not open file " << orderFile << ". Program is ending." << endl;
		cout << "Program ended with exit value: -1";
		return -1;
	}

	while (true)
	{
		Order *anOrder = new Order();

		if (inputFile.fail())
		{
			break;
		}//if
		else
		{
			theOrders.push_back(anOrder);
		}//else
	}//while


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
