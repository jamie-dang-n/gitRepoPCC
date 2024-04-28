#pragma once
#include "item.h"

class ItemList
{
private:
	//node for the linked list
	struct Node
	{
		InventoryItem 	data;
		Node *			next;
		Node(const InventoryItem& aData)
		{
			data = aData;
			next = nullptr;
		} 
	};

	//data members for ItemList
	Node *	head;
	int		size;

	//helper functions 
	void destroy();
	void copy(const ItemList& aList);
	void append(const InventoryItem& anItem);
	
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

	void printList() const;
	void readList(istream& in);
	// Task 1
	int getLowerCostItems(float maxPrice, InventoryItem *& lowerCostItems) const;
	// Task 2
	void swapFirstAndLast();
};
