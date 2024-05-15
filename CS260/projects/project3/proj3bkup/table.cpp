// Author: Jamie Dang
// Date: 5/14/2024
// Program Number: CS260 Project 3
// Purpose: Implementation file for table class. The table class is implemented
// using a hash table.
// Module name: table.cpp

#include "table.h"

// Default Constructor; sets everything to null
Table::Table() : size(0) { // initialize size to 0
	currCapacity = INIT_CAP; // initailize capacity
	aTable = new Node*[currCapacity]; // allocate new array of node pointers
	for (int i = 0; i < currCapacity; i++) { // initialize each array element to nullptr)
		aTable[i] = nullptr;
	}
}


// Copy Constructor
Table::Table(const Table& aTable) : aTable(nullptr), size(0) {
	*this = aTable; // copy constructor uses assignment overload operator		
}



// Cestructor; calls destroy function to help
Table::~Table() {
	destroy();
}



// **** Public Methods



// Name: 	add
// Purpose: adds an entry to the hash table, at the top of a chain
// 			at the array location it is hashed to.
void Table::add(const Website& aSite) {
	int index = calculateIndex(aSite.getTopic());
	Node * newNode = new Node(aSite);
	newNode->next = aTable[index];
	aTable[index] = newNode;
	size++;
}



// Name: 	retrieve
// Purpose: retrieves all entries with a topic keyword and stores them in the matches[] array.
bool Table::retrieve(char * topicKeyword, Website matches[], int & numFound) { 
	bool success = false;
	lowercase(topicKeyword);
	Node * currHead = nullptr;
	Node * curr = nullptr;
	char currTopic[MAX_CHAR];

	numFound = 0;

	for (int i = 0; i < currCapacity; i++) {
		currHead = aTable[i];
		curr = currHead;
		if (currHead) { // check that we've hashed into a non-null array entry
			while (curr) { // check the chain, save the right entries to matches[]
				strcpy(currTopic, curr->data.getTopic());
				if (strstr(currTopic, topicKeyword)) {
					matches[numFound] = curr->data;
					numFound++;
					success = true; // only true if we actually output data
				}
				curr = curr->next;
			}	
		}
	}
	return success;
}

// Name: 	edit
// Purpose: searches the table for a matching entry of topic "topicKeyword" and address "targetAddress".
// 			if the entry is found, change the review of the website to userReview and the rating
// 			to userRating.
bool Table::edit(char * topicKeyword, char * targetAddress, char * userReview, int userRating) { 
	bool success = false;
	lowercase(topicKeyword);
	lowercase(targetAddress);
	Node * currHead = nullptr;
	Node * curr = nullptr;
	char currAddress[MAX_CHAR] = {'\0'};
	char currTopic[MAX_CHAR] = {'\0'};

	for (int i = 0; i < currCapacity; i++) {
		currHead = aTable[i];
		curr = currHead;
		if (currHead) { // check that we've hashed into a non-null array entry to find entry to edit
			while (curr) { // check the chain, look for the entry with the right address and topic
				strcpy(currAddress, curr->data.getAddress());
				strcpy(currTopic, curr->data.getTopic());
				if (strstr(currAddress, targetAddress) && strstr(currTopic, topicKeyword)) {
					success = true; // entry has been found in the list
					// edit data
					curr->data.setReview(userReview);
					curr->data.setRating(userRating);
					break;
				}
				curr = curr->next;
			}
		}
	}
	return success;
}

// Name: 	remove
// Purpose: removes all table entries that have a rating of 1
bool Table::remove() { 
	bool success = false;
	Node * currHead = nullptr;
	Node * curr = nullptr;
	Node * prev = nullptr;
	Node * toDel = nullptr;

	for (int i = 0; i < currCapacity; i++) { // check through each array entry
		currHead = aTable[i];
		if (aTable[i]) { // check that the head pointer for an array entry exists
			// check the chain and remove
			curr = currHead;
			prev = nullptr;
			while (curr) {
				if (curr->data.getRating() == 1) {
					// if there is a match, remove from the linked list
					toDel = curr; // save entry to remove
					if (!prev) {
						// remove from start of the chain
						aTable[i] = aTable[i]->next;
						
						// increment to next part
						curr = curr->next;
					}
				   	else {
						// remove from middle or end of the chain
						// FIXME: getting an error here right now
						prev->next = curr->next;
						
						// increment to next part
						prev = curr; 
						curr = curr->next;
					}
					// delete the entry
					delete toDel;
					toDel = nullptr;
					success = true;
				} else {
					// increment to next part
					prev = curr;
					curr = curr->next;
				}
			}
		}		
	}
	return success;	
}



// Name: 	displayTopic
// Purpose: display all table entries with the matching topic. Partial searches 
// 			for topics are allowed, so we do not use the hashing function.  
bool Table::displayTopic(char * topicKeyword) {
	bool success = false;
	lowercase(topicKeyword);
	Node * currHead = nullptr;
	Node * curr = nullptr;
	char currTopic[MAX_CHAR] = {'\0'};

	for (int i = 0; i < currCapacity; i++) {
		currHead = aTable[i];
		curr = currHead;
		if (currHead) { // check that we've hashed into a non-null array entry
			while (curr) { // check the chain, print out the right entries
				strcpy(currTopic, curr->data.getTopic());
				if (strstr(currTopic, topicKeyword)) {
					cout << curr->data;
					success = true; // only true if we actually output data
				}
				curr = curr->next;
			}	
		}
	}
	return success;
}



// Name: 	display
// Purpose: display the entire table, calling displayChain() for help
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



// Name: 	monitor
// Purpose: displays the length of each chain in the table
void Table::monitor() {
	cout << "There are " << currCapacity << " chains in the table." << endl;
	for (int i = 0; i < currCapacity; i++) {
		cout << i + 1 << "st Chain: " << countChain(aTable[i]) << " entries." << endl;
	}
}




// Name: 	loadFromFile
// Purpose: load in data to a table from a file, fileName.txt
void Table::loadFromFile(const char * fileName) {
	ifstream inFile;
	Website currSite; // website to read data into

	// data members to read into
	char topic[MAX_CHAR] = {'\0'};
	char address[MAX_CHAR]= {'\0'};
	char summary[MAX_CHAR]= {'\0'};
	char review[MAX_CHAR]= {'\0'};
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
	inFile.getline(topic, MAX_CHAR, ';');
	lowercase(topic);
	while (!inFile.eof()) {
		inFile.getline(address, MAX_CHAR, ';');
		lowercase(address);
		inFile.getline(summary, MAX_CHAR, ';');
		inFile.getline(review, MAX_CHAR, ';');
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
		inFile.getline(topic, MAX_CHAR, ';');
		lowercase(topic);
	}	

	inFile.close(); // close file
}

// **** Operators

// Assignment operator overload
const Table& Table::operator= (const Table& srcTable) {
	if (this == &srcTable) 
		return *this;

	if (this->aTable)
		destroy();

	this->size = srcTable.size;
	this->currCapacity = srcTable.currCapacity;
	this->aTable = new Node*[currCapacity];

	for (int i = 0; i < currCapacity; i++) {
		this->aTable[i] = nullptr;
		copyChain(srcTable.aTable[i], this->aTable[i]);
	}
	return *this;
}




// *** Private Methods



// Name: 	displayChain
// Purpose: helper function for display(); displays all data in each chain
void Table::displayChain(Node * currHead) const {
	if (currHead) {
		cout << currHead->data;
		displayChain(currHead->next);
	}
}



// Name: 	calculateIndex
// Purpose: Hashing function, using topic as the key 
int Table::calculateIndex(const char * topic) const {
	int hash = 0;
	int length = strlen(topic);
	for (int i = 0; i < length; i++) {
		if (isalpha(topic[i])) 
			hash += topic[i];	
	}
	return hash % currCapacity;	
}




// Name: 	destroy
// Purpose: calls destroyChain() to destroy the table 
void Table::destroy() {
	for (int i = 0; i < currCapacity; i++) {
		destroyChain(aTable[i]);
	}
	if(aTable)
		delete[] aTable;
}




// Name: 	destroyChain
// Purpose: deletes data from an entire chain
void Table::destroyChain(Node *& currHead) { 
	if (currHead) {
		destroyChain(currHead->next);
		delete currHead;
		currHead = nullptr;
	}
}




// Name: 	copyChain
// Purpose: helper function to copy over entire chains
void Table::copyChain(Node * srcHead, Node *& destHead) {
	if (srcHead) {
		destHead = new Node(srcHead->data);
		copyChain(srcHead->next, destHead->next);
	}
}




// Name: 	lowercase
// Purpose: turn the given char array to a lowercase
// 			version of itself
void Table::lowercase(char * temp) {
	int length = strlen(temp);
	for (int i = 0; i < length; i++) {
		temp[i] = tolower(temp[i]);
	}
}



// Name: 	countChain
// Purpose: counts the number of entries in a chain recursively
int Table::countChain(Node * currHead) const{
	if (currHead) {
		return countChain(currHead->next) + 1;
	}
	return 0;
}
