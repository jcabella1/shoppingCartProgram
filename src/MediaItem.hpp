/*
 * MediaItem.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Jenny
 */

#ifndef MEDIAITEM_HPP_
#define MEDIAITEM_HPP_

#include "OrderItem.hpp"
#include "Date.hpp"

class MediaItem: public OrderItem {
public:
	MediaItem();
	virtual ~MediaItem();

	virtual string whoAmI(void);

	string getAuthorName(void);
	void setAuthorName(string);
	Date getPublicationDate(void);
	void setPublicationDate(int month, int day, int year);
	string getISBNNumber(void);
	void setISBNNumber(string);

private:
	string AuthorName;
	Date PublicationDate;
	string ISBNNumber;
};

#endif /* MEDIAITEM_HPP_ */
