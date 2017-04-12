/*
 * OrderItem.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Jenny
 */

#include "OrderItem.hpp"

OrderItem::OrderItem() {
	OrderNumber = "0";
	ItemNumber = "0";
	ItemDescription = "Unknown";
	Quantity = 0;
	CustomerCost = 0.0;
	VendorCost = 0.0;
	TaxExempt = false;

}//default constructor

OrderItem::~OrderItem() {
	OrderNumber = "X";
	ItemNumber = "X";
	ItemDescription = "X";
	Quantity = 0;
	CustomerCost = 0.0;
	VendorCost = 0.0;
	TaxExempt = false;

}//destructor

string OrderItem::getOrderNumber(void)
{
	return OrderNumber;
}//getOrderNumber
void OrderItem::setOrderNumber(string aString)
{
	OrderNumber = aString;
}//setOrderNumber
string OrderItem::getItemNumber(void)
{
	return ItemNumber;
}//getItemNumber
void OrderItem::setItemNumber(string aString)
{
	ItemNumber = aString;
}//setItemNumber
string OrderItem::getItemDescription(void)
{
	return ItemDescription;
}//getItemDescription
void OrderItem::setItemDescription(string aString)
{
	ItemDescription = aString;
}//setItemDescription
int OrderItem::getQuantity(void)
{
	return Quantity;
}//getQuantity
void OrderItem::setQuantity(int anInt)
{
	Quantity = anInt;
}//setQuantity
float OrderItem::getCustomerCost(void)
{
	return CustomerCost;
}//getCustomerCost
void OrderItem::setCustomerCost(float aFloat)
{
	CustomerCost = aFloat;
}//getCustomerCost
float OrderItem::getVendorCost(void)
{
	return VendorCost;
}//getVendorCost
void OrderItem::setVendorCost(float aFloat)
{
	VendorCost = aFloat;
}//setVendorCost
bool OrderItem::getTaxExempt(void)
{
	return TaxExempt;
}//getTaxExempt
void OrderItem::setTaxExempt(bool aBool)
{
	TaxExempt = aBool;
}//setTaxExempt
