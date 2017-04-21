/*
 * Order.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: Jenny
 */

#include "Order.hpp"
#include <fstream>
#include <iomanip>

Order::Order() {
	cout << "Creating order" << endl;
	string foodItemsFile = "FoodItems.txt";
	string mediaItemsFile = "MediaItems.txt";
	string electronicItemsFile = "ElectronicItems.txt";

	ifstream inputFile;

	inputFile.open(foodItemsFile.c_str());
	readFoodItems(inputFile);
	inputFile.close();
	inputFile.open(mediaItemsFile.c_str());
	readMediaItems(inputFile);
	inputFile.close();
	inputFile.open(electronicItemsFile.c_str());
	readElectronicItems(inputFile);
	inputFile.close();

}//default constructor

Order::Order(Customer *theCustomerPointer)
{
	OrderCustomer = theCustomerPointer;

	cout << "Creating order" << endl;
	string foodItemsFile = "FoodItems.txt";
	string mediaItemsFile = "MediaItems.txt";
	string electronicItemsFile = "ElectronicItems.txt";

	ifstream inputFile;

	inputFile.open(foodItemsFile.c_str());
	readFoodItems(inputFile);
	inputFile.close();
	inputFile.open(mediaItemsFile.c_str());
	readMediaItems(inputFile);
	inputFile.close();
	inputFile.open(electronicItemsFile.c_str());
	readElectronicItems(inputFile);
	inputFile.close();

}//overloaded constructor

Order::~Order() {
	cout << "Deleting order" << endl;
	for (unsigned int i = 0; i < ItemsInOrder.size(); i++)
	{
		delete ItemsInOrder[i];
	}//for
	ItemsInOrder.clear();
	delete OrderCustomer;
}//destructor

string Order::getOrderNumber(void)
{
	return OrderNumber;
}//getOrderNumber
void Order::setOrderNumber(string aString)
{
	OrderNumber = aString;
}//setOrderNumber
Date Order::getOrderDate(void)
{
	return OrderDate;
}//getOrderDate
void Order::setOrderDate(int month, int day, int year)
{
	OrderDate.setMonth(1);
	OrderDate.setDay(1);
	OrderDate.setYear(1970);
}//setOrderDate
vector<OrderItem*> Order::getItemsInOrder(void)
{
	return ItemsInOrder;
}//getItemsInOrder
void Order::setItemsInOrder(OrderItem *anItem)
{
	ItemsInOrder.push_back(anItem);
}//setItemsInOrder
Customer* Order::getOrderCustomer(void)
{
	return OrderCustomer;
}//getOrderCustomer
void Order::setOrderCustomer(Customer *aCustomer)
{
	OrderCustomer = aCustomer;
}//setOrderCustomer

void Order::readFoodItems(ifstream &inFile)
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
			string tempItemNumber;
			string tempItemDescription;
			int tempQuantity;
			float tempCustomerCost;
			float tempVendorCost;
			bool tempTaxExempt;

			int tempExpirationYear;
			int tempExpirationMonth;
			int tempExpirationDay;
			int tempCalories;
			int tempFat;

			inFile >> tempOrderNumber >> tempItemNumber >> tempItemDescription
			>> tempQuantity >> tempCustomerCost >> tempVendorCost >> tempTaxExempt
			>> tempExpirationYear >> tempExpirationMonth >> tempExpirationDay
			>> tempCalories >> tempFat;

			if (tempOrderNumber == OrderNumber)
			{
				FoodItem *tempFoodItem = new FoodItem();

				ItemsInOrder.push_back(tempFoodItem);

				tempFoodItem->setOrderNumber(tempOrderNumber);
				tempFoodItem->setItemNumber(tempItemNumber);
				tempFoodItem->setItemDescription(tempItemDescription);
				tempFoodItem->setQuantity(tempQuantity);
				tempFoodItem->setCustomerCost(tempCustomerCost);
				tempFoodItem->setVendorCost(tempVendorCost);
				tempFoodItem->setTaxExempt(tempTaxExempt);

				tempFoodItem->setExpirationDate(tempExpirationYear, tempExpirationMonth, tempExpirationDay);

				ItemsInOrder.push_back(tempFoodItem);
			}

		}//else
	}//while
}//readFoodItems
void Order::readMediaItems(ifstream &inFile)
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
			string tempItemNumber;
			string tempItemDescription;
			int tempQuantity;
			float tempCustomerCost;
			float tempVendorCost;
			bool tempTaxExempt;

			string tempAuthor;
			int tempMonth;
			int tempDay;
			int tempYear;
			string tempISBN;

			MediaItem *tempMediaItem = new MediaItem();

			inFile >> tempOrderNumber >> tempItemNumber >> tempItemDescription
			>> tempQuantity >> tempCustomerCost >> tempVendorCost
			>> tempTaxExempt >> tempYear >> tempMonth >> tempDay
			>> tempAuthor >> tempISBN;

			tempMediaItem->setOrderNumber(tempOrderNumber);
			tempMediaItem->setItemNumber(tempItemNumber);
			tempMediaItem->setItemDescription(tempItemDescription);
			tempMediaItem->setQuantity(tempQuantity);
			tempMediaItem->setCustomerCost(tempCustomerCost);
			tempMediaItem->setVendorCost(tempVendorCost);
			tempMediaItem->setTaxExempt(tempTaxExempt);

			tempMediaItem->setAuthorName(tempAuthor);
			tempMediaItem->setPublicationDate(tempMonth, tempDay, tempYear);
			tempMediaItem->setISBNNumber(tempISBN);

			ItemsInOrder.push_back(tempMediaItem);
		}//else
	}//while
}//readMediaItems
void Order::readElectronicItems(ifstream &inFile)
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
			string tempItemNumber;
			string tempItemDescription;
			int tempQuantity;
			float tempCustomerCost;
			float tempVendorCost;
			bool tempTaxExempt;

			int tempWarrantyMonths;
			string tempType;

			ElectronicItem *tempElectronicItem = new ElectronicItem();

			inFile >> tempOrderNumber >> tempItemNumber >> tempItemDescription
			>> tempQuantity >> tempCustomerCost >> tempVendorCost
			>> tempTaxExempt >> tempWarrantyMonths >> tempType;

			tempElectronicItem->setOrderNumber(tempOrderNumber);
			tempElectronicItem->setItemNumber(tempItemNumber);
			tempElectronicItem->setItemDescription(tempItemDescription);
			tempElectronicItem->setQuantity(tempQuantity);
			tempElectronicItem->setCustomerCost(tempCustomerCost);
			tempElectronicItem->setVendorCost(tempVendorCost);
			tempElectronicItem->setTaxExempt(tempTaxExempt);

			tempElectronicItem->setElectronicType(tempType);
			tempElectronicItem->setWarrantyMonths(tempWarrantyMonths);

			ItemsInOrder.push_back(tempElectronicItem);
		}//else
	}//while
}//readElectronicItems

double Order::getTotalOfOrder(void)
{
	double total;
	for (unsigned int i = 0; i < ItemsInOrder.size(); i++)
	{
		total += ItemsInOrder[i]->getCustomerCost() * ItemsInOrder[i]->getQuantity();
	}//for
	return total;
}//getTotalOfOrder
