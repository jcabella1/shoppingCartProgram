/*
 * Order.hpp
 *
 *  Created on: Apr 4, 2017
 *      Author: Jenny
 */

#ifndef ORDER_HPP_
#define ORDER_HPP_
#include "Customer.hpp"
#include "OrderItem.hpp"
#include <iostream>
#include <vector>

using namespace std;

class OrderItem;

class Order {
public:
	Order();
	virtual ~Order();

	bool readFoodItems(ifstream &);
	bool readMediaItems(ifstream &);
	bool readElectronicItems(ifstream &);
	double getTotalOfOrder(void);

	string getOrderNumber(void);
	void setOrderNumber(string);
	Date getOrderDate(void);
	void setOrderDate(int month, int day, int year);
	vector<OrderItem*> getItemsInOrder(void);
	void setItemsInOrder(OrderItem *);

private:
	string OrderNumber;
	Date OrderDate;
	vector<OrderItem*> ItemsInOrder;

};

#endif /* ORDER_HPP_ */
