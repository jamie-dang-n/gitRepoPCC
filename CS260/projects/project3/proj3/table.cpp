#include "table.h"
Table::Table() : size(0) { // initialize size to 0
	currCapacity = INIT_CAP; // initailize capacity
	aTable = new Node*[currCapacity]; // allocate new array of node pointers
	for (int i = 0; i < currCapacity; i++) { // initialize each array element to nullptr)
		aTable[i] = nullptr;
	}
}
Table::Table(const Table& aTable) {

}

Table::~Table() {
	destroy();
}

// Public Methods
void Table::add() {
}

void Table::find() {
}
void Table::edit() { 
}
void Table::remove() { 

}
void Table::displayTopic() {
}
void Table::monitor() {
}
void Table::loadFromFile(const char * fileName) {
	ifstream inFile;
	Website currSite; // website to read data into
	
	// data members to read into
	const int MAXCHAR = 101;
	char topic[MAXCHAR];
	char address[MAXCHAR];
	char summary[MAXCHAR];
	char review[MAXCHAR];
	int index = -1;
	int rating = -1;

	// open file
	inFile.open(fileName); 
	if(!inFile){
		cerr << "Failed to open " << fileName << " for reading!" << endl;
		exit(1);
	}

	// start reading loop
	

}

// Operators
const Table& Table::operator= (const Table& srcTable) {
	if (this == &srcTable) 
		return *this;
	
	if (this->aTable)
		destroy();

	size = srcTable.size;
	currCapacity = srcTable.currCapacity;
	aTable = new Node*[currCapacity];
	
	for (int i = 0; i < currCapacity; i++) {
		aTable[i] = nullptr;
		copyChain(srcTable.aTable[i], this->aTable[i]);
	}
	return *this;
}



// Private Methods
// Hashing function
int Table::calculateIndex(const char * key) const {
}
void Table::destroy() {
	for (int i = 0; i < currCapacity; i++) {
		destroyChain(aTable[i]);
	}
	if(aTable)
		delete[] aTable;
}
void Table::destroyChain(Node *& currHead) { 
	if (currHead) {
		destroyChain(currHead->next);
		delete currHead->data;
		delete currHead;
		currHead = nullptr;
	}
}

void Table::copyChain(Node * srcHead, Node *& destHead) {
	if (srcHead) {
		destHead = new Node(*(srcHead->data));
		copyChain(srcHead->next, destHead->next);
	}
}

