#pragma once
#include "item.h"

class ItemList
{
private:
	const static int INIT_CAPACITY = 1; //set low for test purpose
	const static int GROWTH_FACTOR = 2;
	InventoryItem *	list;
	int		size;
	int 	capacity;
	
	void expandArray();
public:
	ItemList();
	ItemList(const ItemList& aList);
	ItemList(ItemList&& aList);
	~ItemList();

	const ItemList& operator= (const ItemList& aList);
	ItemList& operator= (ItemList&& aList);

	int getSize() const;
	InventoryItem& operator[] (int index);
	const InventoryItem& operator[] (int index) const;

	void append(const InventoryItem& anItem);
	void printList() const;
	void readList(istream& in);
	int getItemNames(char **& itemNames) const;	
};
