#include "itemList.h"
ItemList::ItemList()
{
	size = 0;
	capacity = INIT_CAPACITY;
	list = new InventoryItem[capacity];
}

ItemList::ItemList(const ItemList& aList)
{
	size = aList.size;
	capacity = aList.capacity;
	list = new InventoryItem[capacity];
	int index;
	for(index = 0; index < size; index++)
	{
		list[index] = aList.list[index];
	}
}

ItemList::ItemList(ItemList&& aList)
{
	this->size = aList.size;
	this->capacity = aList.capacity;
	this->list = aList.list;
	aList.list = nullptr;
	aList.size = 0;
	aList.capacity = 0;
}

ItemList::~ItemList()
{
	if(this->list)
	{
		delete [] this->list;
		this->list = nullptr;
	}
}
ItemList& ItemList::operator= (ItemList&& aList)
{
	if (this == &aList)
	{
		return *this;
	}
	this->size = aList.size;
	this->capacity = aList.capacity;
	if (this->list)
	{
		delete [] this->list;
	}
	this->list = aList.list;
	aList.list = nullptr;
	aList.size = 0;
	aList.capacity = 0;
	return *this;
}

const ItemList& ItemList::operator= (const ItemList& aList)
{
	if(this == &aList)
	{
		return *this;
	}
	size = aList.size;
	capacity = aList.capacity;
	if(list != nullptr)
	{
		delete [] list;
	}
	list = new InventoryItem[capacity];
	int index;
	for(index = 0; index < size; index++)
	{
		list[index] = aList.list[index];
	}
	return *this;
}

int ItemList::getSize() const
{
	return size;
}

InventoryItem& ItemList::operator[] (int index)
{
	return list[index];
}

const InventoryItem& ItemList::operator[] (int index) const
{
	return list[index];
}

void ItemList::expandArray()
{
	capacity = capacity * GROWTH_FACTOR;
	InventoryItem * tempList = new InventoryItem[capacity];
	int index;
	for(index = 0; index < size; index++)
	{
		tempList[index] = list[index];
	}
	delete [] list;
	list = tempList;
}

void ItemList::append(const InventoryItem& anItem)
{
	if(size == capacity)
	{
		expandArray();
	}
	list[size] = anItem;
	size++;
}

void ItemList::readList(istream& in)
{
	char			itemName[MAX_CHAR];
	float			itemPrice;
	Date			expDate;
	int				year;
	int				month;
	int				day;
	InventoryItem	anItem;

	in.get(itemName, MAX_CHAR, ':');
	while (!in.eof())
	{
		in.get();
		in >> itemPrice;
		in.get();
		in >> year;
		in.get();
		in >> month;
		in.get();
		in >> day;
		in.ignore(MAX_CHAR, '\n');

		anItem.setItemName(itemName);
		anItem.setItemPrice(itemPrice);
		expDate.setDate(year, month, day);
		anItem.setExpDate(expDate);

		append(anItem);

		in.get(itemName, MAX_CHAR, ':');
	}
}

void ItemList::printList() const
{
	int index;
	for(index = 0; index < size; index++)
	{
		list[index].print();
	}
}

int ItemList::getItemNames(char **& itemNames) const {
	itemNames = new char *[capacity];
	int count = 0;
	for (int i = 0; i < capacity; i++) {
		count++;
		itemNames[i] = new char[strlen(list[i].getItemName()) + 1];
		strcpy(itemNames[i], list[i].getItemName());
	}	
	return count;
}

int ItemList::getPriceList(float *& priceList, char **& itemNames) const {
	int count = 0;
	int nameCount = 0;
	float priceTarget = 0.0;
	float tempArray[100];
	cout << "Enter a price to generate a list below that range: ";
	cin >> priceTarget;
	while (!cin || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Error: Please enter a valid price." << endl;
		cout << "Enter a price to generate a list below that range: ";	
		cin >> priceTarget;
	}

	// Filling tempArray with valid prices
	for (int i = 0; i < size; i++) {
		if (list[i].getItemPrice() < priceTarget) {
			tempArray[count] = list[i].getItemPrice();
			count++;
		}	
	}

	// Allocating Memory
	priceList = new float[count];
	itemNames = new char*[count];

	// Copying over price values
	for (int i = 0; i < count; i++) {
		priceList[i] = tempArray[i];
	}
	
	// setting up names list
	for (int i = 0; i < size; i++) {
		if ((list[i].getItemPrice() < priceTarget) && (nameCount <= count)) {
			itemNames[nameCount] = new char[strlen(list[i].getItemName()) + 1];
			strcpy(itemNames[nameCount], list[i].getItemName());
			nameCount++;
		}	
	}

	return count;
}

