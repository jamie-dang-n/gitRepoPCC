#pragma once
#include <iostream>
using namespace std;
#include <cstring>

const int MAX_CHAR = 101;

class InventoryItem
{
private:
	char	itemName[MAX_CHAR];
	float	itemPrice;

public:
	InventoryItem();
	InventoryItem(const char name[], float price);
	void setItemName(const char name[]);
	const char* getItemName() const;

	void setItemPrice(float price);
	float getItemPrice() const;

	void print() const;
};

