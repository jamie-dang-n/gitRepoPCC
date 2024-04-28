#include "item.h"

InventoryItem::InventoryItem()
{
	itemName = nullptr;
	itemPrice = 0;
	expDate = nullptr;
}

InventoryItem::InventoryItem(const InventoryItem& anItem):InventoryItem()
{
	*this = anItem;
}

InventoryItem::InventoryItem(InventoryItem&& anItem):InventoryItem()
{
	*this = move(anItem);
}

InventoryItem::InventoryItem(const char name[], float price, const Date& aDate) {
	itemName = nullptr;
	expDate = nullptr;
	setItemName(name);
	setItemPrice(price);
	setExpDate(aDate);	
}


InventoryItem::~InventoryItem()
{
	if(this->itemName)
	{
		delete [] this->itemName;
		this->itemName = nullptr;
	}
	if(this->expDate)
	{
		delete this->expDate;
		this->expDate = nullptr;
	}
}


const InventoryItem& InventoryItem::operator=(const InventoryItem& anItem)
{
	if(this == &anItem)
	{
		return *this;
	}
	if(itemName)
	{
		delete [] itemName;
	}
	itemName = new char[strlen(anItem.itemName)+1];
	strcpy(itemName, anItem.itemName);
	itemPrice = anItem.itemPrice;
	if(expDate)
	{
		delete expDate;
	}
	expDate = new Date(*(anItem.expDate));
	
	return *this;
}

InventoryItem& InventoryItem::operator= (InventoryItem&& anItem)
{
	if(this == &anItem)
	{
		return *this;
	}
	if(itemName)
	{
		delete [] itemName;
	}
	itemName = anItem.itemName;
	anItem.itemName = nullptr;
	itemPrice = anItem.itemPrice;
	anItem.itemPrice = 0;
	if(expDate)
	{
		delete expDate;
	}
	expDate = anItem.expDate;
	anItem.expDate = nullptr;
	
	return *this;
}

void InventoryItem::setItemName(const char name[])
{
	if(this->itemName)
		delete [] this->itemName;
	this->itemName = new char[strlen(name)+1];
	strcpy(this->itemName, name);
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

void InventoryItem::setExpDate(const Date& aDate)
{
	if(this->expDate)
		delete expDate;
	this->expDate = new Date(aDate);
}

const Date * InventoryItem::getExpDate() const
{
	return this->expDate;
}

void InventoryItem::print() const
{
	cout << fixed;
	cout.precision(2);
	cout << itemName << "\t" << itemPrice 
		<< "\t" << *expDate << endl;
}

istream& operator>> (istream& in, InventoryItem& anItem)
{
	//assuming data input format "itemName:itemPrice:year/month/day"
	char	itemName[MAX_CHAR];
	float 	itemPrice;
	Date	expDate;
	int		year;
	int		month;
	int 	day;

	//read value in temporary variables
	in.get(itemName, MAX_CHAR, ':');
	in.get(); 					//throw away ':'
	in >> itemPrice;
	in.get();					//throw away ':'
	in >> year;					
	in.get();					//throw away '/'
	in >> month;				
	in.get();					//throw away '/'
	in >> day;

	in.ignore(MAX_CHAR, '\n'); 	//throw away '\n'

	//populate anItem with the temporary variables
	anItem.setItemName(itemName);
	anItem.setItemPrice(itemPrice);
	expDate.setDate(year, month, day);
	anItem.setExpDate(expDate);
	return in;
}
