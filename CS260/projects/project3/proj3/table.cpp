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
// Name: add
// Purpose: adds an entry to the hash table, at the top of a chain
// at the array location it is hashed to.
void Table::add(const Website& aSite) {
	int index = 0;
	Node * newNode = new Node(aSite);
	newNode->next = aTable[index];
	aTable[index] = newNode;
	size++;
}

void Table::find() {
}
void Table::edit() { 
}
void Table::remove() { 

}
void Table::displayTopic() {
}

void Table::display() const{	
	cout << left << setw(TOPIC_WIDTH) << "Topic" << ';';
	cout << setw(ADDRESS_WIDTH) << "Address" << ';';
	cout << setw(SUMMARY_WIDTH) << "Summary" << ';';
	cout << setw(REVIEW_WIDTH) << "Review" << ';';
	cout << setw(RATING_WIDTH) << "Rating" << endl;

	for (int i = 0; i < currCapacity; i++) { 
		displayChain(aTable[i]);
	}
}

// Helper function to display the whole table
void Table::displayChain(Node * currHead) const {
	if (currHead) {
		cout << currHead->data;
		displayChain(currHead->next);
	}
}

void Table::monitor() {
	cout << "There are " << currCapacity << " chains in the table." << endl;
	for (int i = 0; i < currCapacity; i++) {
		cout << i + 1 << "st Chain: " << countChain(aTable[i]) << " entries." << endl;
	}
}

int Table::countChain(Node * currHead) const{
	if (currHead) {
		return countChain(currHead->next) + 1;
	}
	return 0;
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
	int rating = -1;

	// open file
	inFile.open(fileName); 
	if(!inFile){
		cerr << "Failed to open " << fileName << " for reading!" << endl;
		exit(1);
	}

	// ignore header line
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');

	// start reading loop
	inFile.getline(topic, MAXCHAR, ';');
	while (!inFile.eof()) {
		inFile.getline(address, MAXCHAR, ';');
		inFile.getline(summary, MAXCHAR, ';');
		inFile.getline(review, MAXCHAR, ';');
		inFile >> rating;
		inFile.ignore(5, '\n');

		// Set up currSite object
		currSite.setTopic(topic);
		currSite.setAddress(address);
		currSite.setSummary(summary);
		currSite.setReview(review);
		currSite.setRating(rating);

		// Add to the hash table
		add(currSite);

		// Continue reading
		inFile.getline(topic, MAXCHAR, ';');
	}	

	inFile.close(); // close file
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
	// to start, this is a very elementary hashing function
	int hash = 0;
	return hash;	
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
		delete currHead;
		currHead = nullptr;
	}
}

void Table::copyChain(Node * srcHead, Node *& destHead) {
	if (srcHead) {
		destHead = new Node(srcHead->data);
		copyChain(srcHead->next, destHead->next);
	}
}

