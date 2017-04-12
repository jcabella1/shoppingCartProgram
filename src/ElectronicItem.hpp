/*
 * ElectronicItem.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Jenny
 */

#ifndef ELECTRONICITEM_HPP_
#define ELECTRONICITEM_HPP_

#include "OrderItem.hpp"

enum Type
{
	TV,
	PS4,
	DVDPLAYER,
	PHONE
};

class ElectronicItem: public OrderItem {
public:
	ElectronicItem();
	virtual ~ElectronicItem();
	virtual string whoAmI(void);

	int getWarrantyMonths(void);
	void setWarrantyMonths(int);
	Type getElectronicType(void);
	void setElectronicType(Type);
private:
	int WarrantyMonths;
	Type ElectronicType;
};

#endif /* ELECTRONICITEM_HPP_ */
