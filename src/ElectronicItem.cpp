/*
 * ElectronicItem.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Jenny
 */

#include "ElectronicItem.hpp"

ElectronicItem::ElectronicItem()
{
//	cout << "Creating electronic item" << endl;
	WarrantyMonths = 0;
	Type = TV;
}//default constructor

ElectronicItem::~ElectronicItem()
{
//	cout << "Deleting electronic item" << endl;

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

ElectronicType ElectronicItem::getElectronicType(void)
{
	return Type;
}//getType
void ElectronicItem::setElectronicType(ElectronicType theType)
{
	Type = theType;
}//setElectronicType
void ElectronicItem::setElectronicType(string theString)
{
	if (theString == "TV")
	{
		Type = TV;
	}//if
	else if (theString == "PS4")
	{
		Type = PS4;
	}//else if
	else if (theString == "DVDPlayer")
	{
		Type = DVDPlayer;
	}//else if
	else if (theString == "Phone")
	{
		Type = PHONE;
	}//else if
}//setElectronicType
