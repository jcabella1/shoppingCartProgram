/*
 * FoodItem.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Jenny
 */

#ifndef FOODITEM_HPP_
#define FOODITEM_HPP_

#include "OrderItem.hpp"
#include "Date.hpp"

class FoodItem: public OrderItem {
public:
	FoodItem();
	virtual ~FoodItem();
	virtual string whoAmI(void);

	Date getExpirationDate(void);
	void setExpirationDate(int month, int day, int year);
	int getCalories(void);
	void setCalories(int);
	int getFat(void);
	void setFat(int);
private:
	Date ExpirationDate;
	int Calories;
	int Fat;
};

#endif /* FOODITEM_HPP_ */
