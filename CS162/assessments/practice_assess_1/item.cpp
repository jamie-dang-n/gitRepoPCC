#include "item.h"

InventoryItem::InventoryItem()
{
	strcpy(itemName, "no item");
	itemPrice = 0;
}

InventoryItem::InventoryItem(const char name[], float price) {
	strcpy(itemName, name);
	itemPrice = price;	
}

void InventoryItem::setItemName(const char name[])
{
	strcpy(itemName, name);
}

const char* InventoryItem::getItemName() const
{
	return itemName;
}

void InventoryItem::setItemPrice(float price)
{
	itemPrice = price;
}

float InventoryItem::getItemPrice() const
{
	return itemPrice;
}

void InventoryItem::print() const
{
	cout << itemName << "\t" << itemPrice << endl;
}
