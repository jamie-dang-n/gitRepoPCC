#ifndef BST_H
#define BST_H

#include <fstream>
#include "website.h"

using namespace std;

class BST {
	public:
		// Constructor
		BST();
		
		// Copy Constructor
		BST(const BST& aTree);
		
		// Destructor
		~BST();

		// Public Methods
		void loadFromFile(const char * fileName);
		void add(const Website& aSite);
		bool removeTopic(const char * topic);
		bool removeSite(const char * keyword);
		bool retrieve(const char * keyword, Website& aSite);
		void display();
		int height();

		// Operator Overloads
		const BST& operator= (const BST& aTree);
		friend ostream& operator<< (ostream& out, const BST& aTree);

	private:
		// Node Struct
		struct Node {
			// data members
			Website data;
			Node * left;
			Node * right;
			
			// parameterized constructor
			Node(const Website& aSite) {
				data = aSite;
				left = right = nullptr;
			};
		};

		// Constants
		const static int MAX_CHAR = 101;

		// Data Members
		Node * root;
		int size; // number of nodes in the tree

		// Private Methods (Helpers)
		void add(Node *& currRoot, const Website& aSite);
		void remove(Node *& currRoot, const char * key, Website& aSite);
		void removeTopicR(const char * topic, Node *& currRoot);
		void removeSiteR(const char * keyword, Node *& currRoot);
		void deleteNode(Node *& target);
		void destroy(Node *& currRoot);
		void copy(Node * srcRoot, Node *& destRoot);
		void displayInorder(Node * currRoot) const;	
		int heightR(Node * currRoot) const;
		void lowercase(char * temp);
		Node* retrieveR(const char * keyword, Website& aSite, Node * currRoot);
};

#endif
