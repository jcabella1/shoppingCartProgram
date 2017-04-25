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
#include "OrderItem.hpp"
#include "Customer.hpp"
using namespace std;

void readCustomerFile(ifstream &, vector<Customer*> &);
void readOrderFile(ifstream &, vector<Order*> &, vector<Customer*>);
void printAllOrders(vector<Order*>);
void printOrder(Order*, string);

int main(int argc, char *argv[]) {
	vector<Customer*> theCustomers;
	vector<Order*> theOrders;

	//
	//file name variables
	//
	string orderFile = "OrderFile.txt";
	string customerFile = "CustomerFile.txt";

	//
	//Create ifstream
	//
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
	// Command line argument validation
	//
	if (argc == 1)
	{
		cout << "Order Report: " << endl;
		printAllOrders(theOrders);
	}//if
	else if (argc == 2)
	{
		cout << "Order Report: " << endl;
		for (unsigned int i = 0; i < theOrders.size(); i++)
	 	{
			if (theOrders[i]->getOrderNumber() == argv[1])
			{
				printOrder(theOrders[i], argv[1]);
			}//if
		}//for
	}//else if
	else
	{
		cout << "Error, you can only enter 2 arguments" << endl;
		cout << "Program is ending, have a nice day" << endl;
		cout << "Program ended with exit value: 1" << endl;
		return 1;
	}//else

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

//
// Read customers from a customer file
//
void readCustomerFile(ifstream & inFile, vector<Customer*> &theCustomerVector)
{
	while (inFile.good())
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
}//readCustomerFile

//
// Read orders from the orders file
//
void readOrderFile(ifstream &inFile, vector<Order*> &theOrderVector, vector<Customer*> theCustomerVector)
{
	while (inFile.good())
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
			bool found;
			Customer *tempCustomer;
			for (unsigned int i = 0; i < theCustomerVector.size(); i++)
			{
				if (theCustomerVector[i]->getCustomerNumber() == tempCustomerID)
				{
					tempCustomer = theCustomerVector[i];
					found = true;
				}//if
			}//for

			//
			// If the customer is found, create new Order that points to that Customer
			// If not found, assign nullptr to orderCustomer
			//
			if (found)
			{
				Order *tempOrder = new Order(tempOrderNumber, tempCustomer);

				tempOrder->setOrderDate(tempMonth, tempDay, tempYear);

				theOrderVector.push_back(tempOrder);
			}//if
			else
			{
				Order *tempOrder = new Order(tempOrderNumber, nullptr);

				tempOrder->setOrderDate(tempMonth, tempDay, tempYear);

				theOrderVector.push_back(tempOrder);
			}//else
	}//while

}//readOrderFile

//
// 	Prints all orders
//
void printAllOrders(vector<Order*> theOrderVector)
{
	for (unsigned int i = 0; i < theOrderVector.size(); i++)
	{
		printOrder(theOrderVector[i], theOrderVector[i]->getOrderNumber());
	}//for
}//printAllOrders

//
// Prints the passed order with the matching order number
//
void printOrder(Order* theOrderPointer, string theOrderNumber)
{

		cout << endl;
		cout << "========================================" << endl;
		cout << right << setw(25) << "Order ID" << setw(15) << "Customer ID" << setw(15) << "Order Date" << setw(20) << "Customer" << endl;
		cout << right << setw(25) << "--------" << setw(15) << "-----------" << setw(15) << "----------" << setw(20) << "--------" << endl;
		cout << right << setw(25) << theOrderPointer->getOrderNumber() << setw(15)
					<< theOrderPointer->getOrderCustomer()->getCustomerNumber() << setw(15)
					<< theOrderPointer->getOrderDate().getDateString() << setw(20)
					<< theOrderPointer->getOrderCustomer()->getCustomerName() << endl;
		cout << endl;

		//
		// Print out food items
		//
		cout << right  << setw(25) << "Food items ordered:" << setw(25) << "Item Number" << setw(25) << "Item Description" << setw(15) << "Calories" << setw(15) << "Cost" << endl;
		cout << setw(50) << "-----------" << setw(25) << "----------------" << setw(15) << "--------" << setw(15) << "----" << endl;
		for (unsigned int i = 0; i < theOrderPointer->getItemsInOrder().size(); i++)
		{
			if (theOrderPointer->getItemsInOrder()[i]->whoAmI() == "fooditem")
			{
				FoodItem *FoodItemPointer = static_cast<FoodItem*>(theOrderPointer->getItemsInOrder()[i]);
				cout << right << setw(50) << FoodItemPointer->getItemNumber() << setw(25)
						<< FoodItemPointer->getItemDescription() << setw(15)
						<< FoodItemPointer->getCalories() << setw(15)
						<< FoodItemPointer->getCustomerCost() << endl;
			}//if
			else { } // do nothing
		}//for

		//
		// Print out media items
		//
		cout << right << setw(25) << "Media items ordered:" << setw(25) << "Item Number" << setw(25) << "Item Description" << setw(15) << "ISBN" << setw(15) << "Cost" << endl;
		cout << setw(50) << "-----------" << setw(25) << "----------------" << setw(15) << "----" << setw(15) << "----" << endl;
		for (unsigned int i = 0; i < theOrderPointer->getItemsInOrder().size(); i++)
		{
			if (theOrderPointer->getItemsInOrder()[i]->whoAmI() == "mediaitem")
			{
				MediaItem *MediaItemPointer = static_cast<MediaItem*>(theOrderPointer->getItemsInOrder()[i]);

				cout << right << setw(50) << MediaItemPointer->getItemNumber() << setw(25)
					<< MediaItemPointer->getItemDescription() << setw(15)
					<< MediaItemPointer->getISBNNumber() << setw(15)
					<< MediaItemPointer->getCustomerCost() << endl;
			}//if
			else { } //do nothing

		}//for

		//
		// Print out electronic items
		//
		cout << right << setw(25) << "Electronic items ordered:" << setw(25) << "Item Number" << setw(25) << "Item Description" << setw(15) << "Warranty" << setw(15) << "Cost" << endl;
		cout << setw(50) << "-----------" << setw(25) << "----------------" << setw(15) << "--------" << setw(15) << "----" << endl;

		for (unsigned int i = 0; i < theOrderPointer->getItemsInOrder().size(); i++)
		{
			if (theOrderPointer->getItemsInOrder()[i]->whoAmI() == "electronicitem")
			{
				ElectronicItem *ElectronicItemPointer = static_cast<ElectronicItem*>(theOrderPointer->getItemsInOrder()[i]);
				cout << right << setw(50) << ElectronicItemPointer->getItemNumber() << setw(25)
					<< ElectronicItemPointer->getItemDescription() << setw(15)
					<< ElectronicItemPointer->getWarrantyMonths() << setw(15)
					<< ElectronicItemPointer->getCustomerCost() << endl;
			}//if
			else { } //do nothing

		}//for

		cout << "Total for this order will be: $" << theOrderPointer->getTotalOfOrder() << endl;

}//printOrder
