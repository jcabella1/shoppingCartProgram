/*
 * FoodItem.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Jenny
 */

#include "FoodItem.hpp"

FoodItem::FoodItem() {
	cout << "Creating food item" << endl;
	Calories = 0;
	Fat = 0;
	ExpirationDate.setDay(1);
	ExpirationDate.setMonth(1);
	ExpirationDate.setYear(1970);
}//default constructor

FoodItem::~FoodItem() {
	cout << "Deleting food item" << endl;
}//destructor

string FoodItem::whoAmI(void)
{
	return "fooditem";
}//whoAmI
Date FoodItem::getExpirationDate(void)
{
	return ExpirationDate;
}//getExpirationDate
void FoodItem::setExpirationDate(int month, int day, int year)
{
	ExpirationDate.setMonth(month);
	ExpirationDate.setDay(day);
	ExpirationDate.setYear(year);
}//setExpirationDate
int FoodItem::getCalories(void)
{
	return Calories;
}//getCalories
void FoodItem::setCalories(int anInt)
{
	Calories = anInt;
}//setCalories
int FoodItem::getFat(void)
{
	return Fat;
}//getFat
void FoodItem::setFat(int anInt)
{
	Fat = anInt;
}//setFat
