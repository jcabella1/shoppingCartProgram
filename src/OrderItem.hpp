/*
 * OrderItem.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Jenny
 */

#ifndef ORDERITEM_HPP_
#define ORDERITEM_HPP_

#include <iostream>
#include <vector>

using namespace std;

class OrderItem {
public:
	OrderItem();
	virtual ~OrderItem();
	virtual string whoAmI(void) = 0;

	string getOrderNumber(void);
	void setOrderNumber(string);
	string getItemNumber(void);
	void setItemNumber(string);
	string getItemDescription(void);
	void setItemDescription(string);
	int getQuantity(void);
	void setQuantity(int);
	float getCustomerCost(void);
	void setCustomerCost(float);
	float getVendorCost(void);
	void setVendorCost(float);
	bool getTaxExempt(void);
	void setTaxExempt(bool);

private:
	string OrderNumber;
	string ItemNumber;
	string ItemDescription;
	int Quantity;
	float CustomerCost;
	float VendorCost;
	bool TaxExempt;
};

#endif /* ORDERITEM_HPP_ */
