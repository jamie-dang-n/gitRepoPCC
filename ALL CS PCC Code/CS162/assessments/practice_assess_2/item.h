#pragma once
#include <iostream>
using namespace std;
#include <cstring>
#include "date.h"

const int MAX_CHAR = 101;
class InventoryItem
{
private:
	char *	itemName;
	float	itemPrice;
	Date *	expDate;

public:
	InventoryItem();
	InventoryItem(const InventoryItem& anItem);
	InventoryItem(InventoryItem&& anItem);
	InventoryItem(const char name[], float price, const Date &aDate);
	~InventoryItem();

	const InventoryItem& operator= (const InventoryItem& anItem);
	InventoryItem& operator= (InventoryItem&& anItem);	

	void setItemName(const char name[]);
	const char* getItemName() const;

	void setItemPrice(float price);
	float getItemPrice() const;

	void setExpDate(const Date& aDate);
	const Date * getExpDate() const;

	void print() const;
};

