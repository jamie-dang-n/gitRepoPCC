#include "itemList.h"
ItemList::ItemList()
{
	size = 0;
	head = nullptr;
}

ItemList::ItemList(const ItemList& aList)
{
	size = aList.size;

	if(!aList.head)
	{
		this->head = nullptr;
		return;
	}

	copy(aList);
}

ItemList::ItemList(ItemList&& aList)
{
	this->size = aList.size;
	this->head = aList.head;
	aList.head = nullptr;
	aList.size = 0;
}

ItemList::~ItemList()
{
	destroy();
}

void ItemList::destroy()
{
	Node *	curr = head;
	while(head)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
}

void ItemList::copy(const ItemList& aList)
{
	//copy the first node
	this->head = new Node((aList.head)->data);
	Node * currSource = (aList.head)->next;
	Node * currDestination = this->head;
		

	//copy the rest of the list
	while(currSource)
	{
		currDestination->next = new Node(currSource->data);
		currSource = currSource->next;
		currDestination = currDestination->next;
	} 	
}

ItemList& ItemList::operator= (ItemList&& aList)
{
	if (this == &aList)
	{
		return *this;
	}
	this->size = aList.size;
	if (this->head)
	{
		destroy();
	}
	this->head = aList.head;
	aList.head = nullptr;
	aList.size = 0;
	return *this;
}

const ItemList& ItemList::operator= (const ItemList& aList)
{
	if(this == &aList)
	{
		return *this;
	}
	size = aList.size;
	if(this->head != nullptr)
	{
		destroy();
	}
	copy(aList);
	return *this;
}

int ItemList::getSize() const
{
	return size;
}

InventoryItem& ItemList::operator[] (int index)
{
	Node *	curr = head;
	int		position;
	for(position = 0; position < index; position++)
	{
		curr = curr->next;
	}
	return curr->data;	
}

const InventoryItem& ItemList::operator[] (int index) const
{
	Node *	curr = head;
	int		position;
	for(position = 0; position < index; position++)
	{
		curr = curr->next;
	}
	return curr->data;	
}

void ItemList::append(const InventoryItem& anItem)
{
	Node *	newNode = new Node(anItem);
	if(!head)
	{
		head = newNode;
		size++;
		return;
	}
	Node * prev = nullptr;
	Node * curr = head;
	while(curr)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = newNode;
	
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
	Node * curr;
	for(curr = head; curr; curr = curr->next)
	{
		curr->data.print();
	}
}

int ItemList::getOlderItems(const Date& expDate, InventoryItem *& olderItems) const {
	Node * curr = head;
	int numItems = 0;
	int i = 0;

	// Finding size of array
	while (curr) {
		if (*(curr->data.getExpDate()) < expDate) {
			numItems++;
		}
		curr = curr->next;
	}

	// Allocating the array
	olderItems = new InventoryItem[numItems];

	// adding items to the dynamic array
	curr = head; // reset curr pointer
	while (curr) {
		if (*(curr->data.getExpDate()) < expDate) {
			olderItems[i] = curr->data;
			i++;
		}
		curr = curr->next;
	}	

	return numItems;
}

void ItemList::removeFirstAndLast() {
	Node * curr = head;
	Node * prev = nullptr;
	if (!(size < 2)) {
		// size isn't less than 2, so remove first and last
		head = curr->next;
		delete curr;

		// find the end of the list
		curr = head; // reset curr to new head
	   	while (curr->next != nullptr) {
			prev = curr;
			curr = curr->next;
		}	

		// Once found, break out of loop
		// deleting end node
		delete curr;
		prev->next = nullptr;
	} else {
		cout << "There are not enough items in the list to remove first and last. There's only 1 or 0 nodes, so no changes made." << endl;
	}
}

