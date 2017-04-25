/*
 * MediaItem.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Jenny
 */

#include "MediaItem.hpp"

MediaItem::MediaItem() {
//	cout << "Creating media item" << endl;
	AuthorName = "Unknown";
	PublicationDate.setMonth(1);
	PublicationDate.setDay(1);
	PublicationDate.setYear(1970);
	ISBNNumber = "Unknown";
}

MediaItem::~MediaItem() {
//	cout << "Deleting media item" << endl;
}//destructor

string MediaItem::whoAmI(void)
{
	return "mediaitem";
}//whoAmI

string MediaItem::getAuthorName(void)
{
	return AuthorName;
}//getAuthorName
void MediaItem::setAuthorName(string aString)
{
	AuthorName = aString;
}//setAuthorName
Date MediaItem::getPublicationDate(void)
{
	return PublicationDate;
}//getPublicationDate
void MediaItem::setPublicationDate(int month, int day, int year)
{
	PublicationDate.setMonth(month);
	PublicationDate.setDay(day);
	PublicationDate.setYear(year);
}//setPublicationDate
string MediaItem::getISBNNumber(void)
{
	return ISBNNumber;
}//getISBNNumber
void MediaItem::setISBNNumber(string aString)
{
	ISBNNumber = aString;
}//setISBNNumber
