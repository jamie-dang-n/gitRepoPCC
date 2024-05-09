#include "itemList.h"
ItemList::ItemList()
{
	size = 0;
	capacity = CAPACITY;
}

InventoryItem& ItemList::get (int index)
{
	return list[index];
}

void ItemList::append(const InventoryItem& anItem)
{
	list[size] = anItem;
	size++;
}

void ItemList::readList(istream& in)
{
	char 			itemName[MAX_CHAR];
	float 			itemPrice;
	InventoryItem 	anItem;

	in.get(itemName, MAX_CHAR, ':');
	while (!in.eof())
	{
		in.get();
		in >> itemPrice;
		in.get();
		
		anItem.setItemName(itemName);
		anItem.setItemPrice(itemPrice);
		append(anItem);

		in.get(itemName, MAX_CHAR, ':');
	}
}
	
void ItemList::printList() const
{
	int index;

	cout << fixed;
	cout.precision(2);
	for(index = 0; index < size; index++)
	{
		list[index].print();
	}
}

int ItemList::length() const {
	return size;	
}

void ItemList::changePrice(int index, float price) {
	list[index].setItemPrice(price);	
}

