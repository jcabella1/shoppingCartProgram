/*
 * ElectronicItem.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Jenny
 */

#include "ElectronicItem.hpp"

ElectronicItem::ElectronicItem() {
	WarrantyMonths = 0;
}//default constructor

ElectronicItem::~ElectronicItem() {
	WarrantyMonths = 0;
}//destructor

int ElectronicItem::getWarrantyMonths(void)
{
	return WarrantyMonths;
}//getWarrantyMonths
void ElectronicItem::setWarrantyMonths(int anInt)
{
	WarrantyMonths = anInt;
}//setWarrantyMonths

string ElectronicItem::whoAmI(void)
{
	return "electronicitem";
}//whoAmI
