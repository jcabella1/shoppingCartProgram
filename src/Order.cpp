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

}

Order::~Order() {
	for (unsigned int i = 0; i < ItemsInOrder.size(); i++)
	{
		delete ItemsInOrder[i];
	}
	ItemsInOrder.clear();
}

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
