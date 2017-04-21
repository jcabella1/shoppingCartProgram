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
#include "FoodItem.hpp"
#include "ElectronicItem.hpp"
#include "MediaItem.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Order {
public:
	Order();
	Order(Customer *);
	virtual ~Order();

	void readFoodItems(ifstream &);
	void readMediaItems(ifstream &);
	void readElectronicItems(ifstream &);
	double getTotalOfOrder(void);

	string getOrderNumber(void);
	void setOrderNumber(string);
	Date getOrderDate(void);
	void setOrderDate(int month, int day, int year);
	vector<OrderItem*> getItemsInOrder(void);
	void setItemsInOrder(OrderItem *);
	Customer* getOrderCustomer(void);
	void setOrderCustomer(Customer*);

private:
	string OrderNumber;
	Date OrderDate;
	vector<OrderItem*> ItemsInOrder;
	Customer *OrderCustomer;

};

#endif /* ORDER_HPP_ */
