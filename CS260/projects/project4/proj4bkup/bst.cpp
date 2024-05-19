#include "bst.h"

// Constructor
BST::BST() : root(nullptr), size(0) {}

// Copy Constructor
BST::BST(const BST& aTree) : root(nullptr), size(0) {
	*this = aTree;
}

// Destructor
BST::~BST() {
	destroy(root);
}


// Public Methods
void BST::add(const Website& aSite) {
	add(this->root, aSite);
	size++;
}

void BST::loadFromFile(const char * fileName) {
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

		// Add to the BST
		add(currSite);

		// Continue reading
		inFile.getline(topic, MAX_CHAR, ';');
		lowercase(topic);
	}	

	inFile.close(); // close file
}


// Private Methods (helpers)
void BST::add(Node *& currRoot, const Website& aSite) {
	if (!currRoot) { // add as a leaf
		currRoot = new Node(aSite);
		// FIXME: change from the topic to the keyword, implement website keyword first
	} else if (strcmp(aSite.getTopic(), currRoot->data.getTopic()) < 0) {
		// enter left side
		add(currRoot->left, aSite);
	} else {
		// enter right side
		add(currRoot->right, aSite);
	}
}

void BST::copy(Node * srcRoot, Node *& destRoot) {
	if (srcRoot) {
		destRoot = new Node(srcRoot->data);
		copy(srcRoot->left, destRoot->left);
		copy(srcRoot->right, destRoot->right);
	} else {
		destRoot = nullptr;
	}
}

void BST::destroy(Node *& currRoot) {
	if (currRoot) {
		destroy(currRoot->left);
		destroy(currRoot->right);
		delete currRoot;
		currRoot = nullptr;
	}
}

void BST::deleteNode(Node *& target) {

}


// Operator Overloads
const BST& BST::operator= (const BST& treeSrc) {
	if (this == &treeSrc) 
		return *this;
	if (this->root) {
		destroy(this->root);
	}	
	size = treeSrc.size;
	copy(treeSrc.root, this->root);
	return *this;
}

// Name: 	lowercase
// Purpose: turn the given char array to a lowercase
// 			version of itselfvoid Table::lowercase(char * temp) {
void BST::lowercase(char * temp) {
	int length = strlen(temp);	
	for (int i = 0; i < length; i++) {
		temp[i] = tolower(temp[i]);
	}
}
