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

};

class ElectronicItem: public OrderItem {
public:
	ElectronicItem();
	virtual ~ElectronicItem();
	virtual string whoAmI(void);

	int getWarrantyMonths(void);
	void setWarrantyMonths(int);
private:
	int WarrantyMonths;
};

#endif /* ELECTRONICITEM_HPP_ */
