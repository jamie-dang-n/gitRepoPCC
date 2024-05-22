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


// **** Public Methods

// Purpose: display the entire tree in alphabetical order.
// 			calls displayInorder() to help
void BST::display() {
	cout << left << setw(KEY_WIDTH) << "Key" << ';';
   	cout << setw(TOPIC_WIDTH) << "Topic" << ';';
	cout << setw(ADDRESS_WIDTH) << "Address" << ';';
	cout << setw(SUMMARY_WIDTH) << "Summary" << ';';
	cout << setw(REVIEW_WIDTH) << "Review" << ';';
	cout << setw(RATING_WIDTH) << "Rating" << endl;	
	displayInorder(root);
}

// Purpose: add a node to the tree, using the overloaded
// 			recursive add() function to help.
void BST::add(const Website& aSite) {
	add(this->root, aSite);
	size++;
}

// Purpose: remove a site from the tree, using the 
// 			recursive removeSiteR() function to help.
bool BST::removeSite(const char * keyword) {
	bool success = false;
	int temp = size;

	removeSiteR(keyword, root);

	if (temp > size) {
		// item was removed
		success = true;
	}

	return success;

}

// Purpose: remove all sites with a particular topic from
// 			the tree, using the recursive removeTopicR() 
// 			function to help.
bool BST::removeTopic(const char * topic) {
	bool success = false;
	int temp = size;

	removeTopicR(topic, root);
	
	if (temp > size) {
		// item was removed
		success = true;
	}

	return success;
}


// Purpose: retrieve a site from the tree by reference, 
// 			using the recursive retrieveR() function to help.
bool BST::retrieve(const char * keyword, Website& aSite) {
	Node * temp = nullptr;
	temp = retrieveR(keyword, aSite, root);
	if (!temp) {
		return false;
	} else {
		aSite = temp->data;
		return true;
	}
}

// Purpose: load in data to the tree from the file fileName.txt
void BST::loadFromFile(const char * fileName) {
	ifstream inFile;
	Website currSite; // website to read data into

	// data members to read into
	char topic[MAX_CHAR] = {'\0'};
	char key[MAX_CHAR] = {'\0'};
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
		inFile.getline(key, MAX_CHAR, ';');
		inFile.getline(address, MAX_CHAR, ';');
		lowercase(address);
		inFile.getline(summary, MAX_CHAR, ';');
		inFile.getline(review, MAX_CHAR, ';');
		inFile >> rating;
		inFile.ignore(5, '\n');

		// Set up currSite object
		currSite.setTopic(topic);
		currSite.setKey(key);
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

// Purpose: returns the height of the tree using the 
// 			recurisve function, heightR()
int BST::height() {
	return heightR(root);
}

// **** Private Methods (helpers & recurisve functions)

// Purpose: recursive helper function to insert a note into the BST based on key
void BST::add(Node *& currRoot, const Website& aSite) {
	if (!currRoot) { // add as a leaf
		currRoot = new Node(aSite);
	} else if (strcmp(aSite.getKey(), currRoot->data.getKey()) < 0) {
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


// Assumes that the target node does exist in the tree
void BST::deleteNode(Node *& target) {
	if (!target->left && !target->right) {
		// Target node is a leaf
		delete target;
		target = nullptr;
	} else if(!target->right) {
		// Target node only has left child
		Node * temp = target;
		target = target->left;
		delete temp;
		temp = nullptr;
	} else if (!target->left) {
		// Target node only has right child
		Node * temp = target;
		target = target->right;
		delete temp;
		temp = nullptr;
	} else {
		// Target node has 2 children
		
		// Find inorder successor of the target node
		// Inorder successor is the leftmost node of the right subtree
		Node * prev = nullptr;
		Node * curr = target->right; // start in right subtree
		if (!curr->left) {
			// Not possible to traverse left, so the right child is the inorder successor
			target->right = curr->right;
		} else {
			// traverse leftward as far as we can
			while(curr->left) {
				prev = curr;
				curr = curr->left;
			}
			prev->left = curr->right; // relink
		}
		target->data = curr->data;
		delete curr;
		prev = nullptr;
		curr = nullptr;
	}
	size--;
}


void BST::removeSiteR(const char * keyword, Node *& currRoot) {
	if (currRoot) {
		int temp = strcmp(keyword, currRoot->data.getKey());
		if (temp == 0) {
			deleteNode(currRoot);
		} else if (temp < 0) {
			removeSiteR(keyword, currRoot->left);
		} else {
			removeSiteR(keyword, currRoot->right);
		}
	}
}


void BST::removeTopicR(const char * topic, Node *& currRoot) {
	if (currRoot) { 
		// postorder: start at the ends, then return to the root
		removeTopicR(topic, currRoot->left);
		removeTopicR(topic, currRoot->right);

		// go through the entire tree and remove all nodes with a matching topic
		char temp[MAX_CHAR] = {'\0'};	
		strcpy(temp, topic);
		lowercase(temp);

		if (strcmp(currRoot->data.getTopic(), temp) == 0) {
			// if the topic matches, remove the target node
			deleteNode(currRoot);
		} 		
	}
}



void BST::displayInorder(Node * currRoot) const {
	if (currRoot) {
		displayInorder(currRoot->left);
		cout << currRoot->data;
		displayInorder(currRoot->right);
	}	
}

int BST::heightR(Node * currRoot) const {
	if (!currRoot) {
		return 0;
	} else {
		int left = heightR(currRoot->left);
		int right = heightR(currRoot->right);

		if (left > right) {
			return left + 1;
		} else {
			return right + 1;
		}
	}
}

BST::Node* BST::retrieveR(const char * keyword, Website& aSite, Node * currRoot) {
	if (!currRoot) {
		return nullptr; 
	} else if (strcmp(keyword, currRoot->data.getKey()) == 0) {
		return currRoot; // item found
	} else if (strcmp(keyword, currRoot->data.getKey()) < 0) {
		// search left subtree
		return retrieveR(keyword, aSite, currRoot->left);
	} else {
		// search right subtree
		return retrieveR(keyword, aSite, currRoot->right);
	}
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





