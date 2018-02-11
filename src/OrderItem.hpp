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
	double getCustomerCost(void);
	void setCustomerCost(double);
	double getVendorCost(void);
	void setVendorCost(double);
	bool getTaxExempt(void);
	void setTaxExempt(char);

private:
	string OrderNumber;
	string ItemNumber;
	string ItemDescription;
	int Quantity;
	double CustomerCost;
	double VendorCost;
	bool TaxExempt;
};

#endif /* ORDERITEM_HPP_ */
