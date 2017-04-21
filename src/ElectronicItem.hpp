/*
 * ElectronicItem.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Jenny
 */

#ifndef ELECTRONICITEM_HPP_
#define ELECTRONICITEM_HPP_

#include "OrderItem.hpp"

enum ElectronicType
{
	TV,
	PS4,
	DVDPlayer,
	PHONE
};

class ElectronicItem: public OrderItem {
public:
	ElectronicItem();
	virtual ~ElectronicItem();
	virtual string whoAmI(void);

	int getWarrantyMonths(void);
	void setWarrantyMonths(int);
	ElectronicType getElectronicType(void);
	void setElectronicType(ElectronicType);
	void setElectronicType(string);
private:
	int WarrantyMonths;
	ElectronicType Type;
};

#endif /* ELECTRONICITEM_HPP_ */
