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
	OrderCustomer = nullptr;

	cout << "Creating order" << endl;
	string foodItemsFile = "FoodItems.txt";
	string mediaItemsFile = "MediaItems.txt";
	string electronicItemsFile = "ElectronicItems.txt";

	ifstream inputFile1;
	ifstream inputFile2;
	ifstream inputFile3;

	inputFile1.open(foodItemsFile.c_str());
	readFoodItems(inputFile1);
	inputFile1.close();
	inputFile2.open(mediaItemsFile.c_str());
	readMediaItems(inputFile2);
	inputFile2.close();
	inputFile3.open(electronicItemsFile.c_str());
	readElectronicItems(inputFile3);
	inputFile3.close();

}//default constructor

Order::Order(string orderNum, Customer *theCustomerPointer)
{
	OrderCustomer = theCustomerPointer;
	OrderNumber = orderNum;

	cout << "Creating order" << endl;
	string foodItemsFile = "FoodItems.txt";
	string mediaItemsFile = "MediaItems.txt";
	string electronicItemsFile = "ElectronicItems.txt";

	ifstream inputFile1;
	ifstream inputFile2;
	ifstream inputFile3;

	inputFile1.open(foodItemsFile.c_str());
	readFoodItems(inputFile1);
	inputFile1.close();
	inputFile2.open(mediaItemsFile.c_str());
	readMediaItems(inputFile2);
	inputFile2.close();
	inputFile3.open(electronicItemsFile.c_str());
	readElectronicItems(inputFile3);
	inputFile3.close();

}//overloaded constructor

Order::~Order() {
	cout << "Deleting order" << endl;
//	for (unsigned int i = 0; i < ItemsInOrder.size(); i++)
//	{
//		delete ItemsInOrder[i];
//	}//for
//	ItemsInOrder.clear();
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
	OrderDate.setMonth(month);
	OrderDate.setDay(day);
	OrderDate.setYear(year);
}//setOrderDate
vector<unique_ptr<OrderItem>> Order::getItemsInOrder(void)
{
	return ItemsInOrder;
}//getItemsInOrder
void Order::setItemsInOrder(unique_ptr<OrderItem> anItem)
{
	ItemsInOrder.push_back(move(anItem));
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
	while (inFile.good())
	{
			string tempOrderNumber;
			string tempItemNumber;
			string tempItemDescription;
			int tempQuantity;
			double tempCustomerCost;
			double tempVendorCost;
			char tempTaxExempt;

			int tempExpirationYear;
			int tempExpirationMonth;
			int tempExpirationDay;
			int tempCalories;
			int tempFat;

			inFile >> tempOrderNumber >> tempItemNumber >> tempItemDescription
			>> tempQuantity >> tempCustomerCost >> tempVendorCost >> tempTaxExempt
			>> tempExpirationYear >> tempExpirationMonth >> tempExpirationDay
			>> tempCalories >> tempFat;

			if (tempOrderNumber == this->OrderNumber)
			{
				unique_ptr<FoodItem> tempFoodItem(new FoodItem());
				for (int i = 0; i < tempQuantity; i++)
				{
					tempFoodItem->setOrderNumber(tempOrderNumber);
					tempFoodItem->setItemNumber(tempItemNumber);
					tempFoodItem->setItemDescription(tempItemDescription);
					tempFoodItem->setQuantity(tempQuantity);
					tempFoodItem->setCustomerCost(tempCustomerCost);
					tempFoodItem->setVendorCost(tempVendorCost);
					tempFoodItem->setTaxExempt(tempTaxExempt);

					tempFoodItem->setExpirationDate(tempExpirationYear, tempExpirationMonth, tempExpirationDay);
				}//for
				ItemsInOrder.push_back(move(tempFoodItem));
			}//if
	}//while
}//readFoodItems

//
// Reads data from MediaItems.txt; ONLY adds items with the same OrderNumber
//
void Order::readMediaItems(ifstream &inFile)
{
	while (inFile.good())
	{
			string tempOrderNumber;
			string tempItemNumber;
			string tempItemDescription;
			int tempQuantity;
			double tempCustomerCost;
			double tempVendorCost;
			char tempTaxExempt;

			string tempAuthor;
			int tempMonth;
			int tempDay;
			int tempYear;
			string tempISBN;

			inFile >> tempOrderNumber >> tempItemNumber >> tempItemDescription
			>> tempQuantity >> tempCustomerCost >> tempVendorCost
			>> tempTaxExempt >> tempYear >> tempMonth >> tempDay
			>> tempAuthor >> tempISBN;

			if (tempOrderNumber == this->OrderNumber)
			{
				unique_ptr<MediaItem> tempMediaItem(new MediaItem());

				for (int i = 0; i < tempQuantity; i++)
				{
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

				}//for

				ItemsInOrder.push_back(move(tempMediaItem));
			}//if
	}//while
}//readMediaItems
void Order::readElectronicItems(ifstream &inFile)
{
	while (inFile.good())
	{
			string tempOrderNumber;
			string tempItemNumber;
			string tempItemDescription;
			int tempQuantity;
			double tempCustomerCost;
			double tempVendorCost;
			char tempTaxExempt;

			int tempWarrantyMonths;
			string tempType;

			inFile >> tempOrderNumber >> tempItemNumber >> tempItemDescription
			>> tempQuantity >> tempCustomerCost >> tempVendorCost
			>> tempTaxExempt >> tempWarrantyMonths >> tempType;

			if (tempOrderNumber == this->OrderNumber)
			{
				unique_ptr<ElectronicItem> tempElectronicItem(new ElectronicItem());

				for (int i = 0; i < tempQuantity; i++)
				{
					tempElectronicItem->setOrderNumber(tempOrderNumber);
					tempElectronicItem->setItemNumber(tempItemNumber);
					tempElectronicItem->setItemDescription(tempItemDescription);
					tempElectronicItem->setQuantity(tempQuantity);
					tempElectronicItem->setCustomerCost(tempCustomerCost);
					tempElectronicItem->setVendorCost(tempVendorCost);
					tempElectronicItem->setTaxExempt(tempTaxExempt);

					tempElectronicItem->setElectronicType(tempType);
					tempElectronicItem->setWarrantyMonths(tempWarrantyMonths);

				}//for

				ItemsInOrder.push_back(move(tempElectronicItem));
			}//if
	}//while
}//readElectronicItems

double Order::getTotalOfOrder(void)
{
	double total;

	cout << setprecision(2) << showpoint << fixed;

	for (unsigned int i = 0; i < ItemsInOrder.size(); i++)
	{
		total += ItemsInOrder[i]->getCustomerCost() * ItemsInOrder[i]->getQuantity();
	}//for
	return total;
}//getTotalOfOrder
