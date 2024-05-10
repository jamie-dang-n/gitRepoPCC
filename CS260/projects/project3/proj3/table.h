#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include "website.h"

using namespace std;

class Table {
	public:
		// Constructors and destructors
		Table();
		Table(const Table& aTable);
		~Table();

		// Public Methods
		void add(const Website& aSite);
		void find();
		void edit();
		void remove();
		void displayTopic();
		void display() const;
		void monitor();
		void loadFromFile(const char * fileName);

		// Operators
		const Table& operator= (const Table& srcTable);
		//friend ostream& operator<< (ostream& out, const Table& aTable);	
	private:
		// Constants
		const static int INIT_CAP = 5;
		// Data Members
		struct Node {
			// Node Constructor
			Node(const Website& aSite) {
				data = aSite;
				next = nullptr;
			}

			// Node data members
			Website data;
			Node * next;
		};
		Node ** aTable;
		int currCapacity;
		int size;
		// Private Methods
		int calculateIndex(const char * key) const; // hashing function
		void destroy();
		void destroyChain(Node *& currHead);
		void copyChain(Node * srcHead, Node *& destHead);
		void displayChain(Node * currHead) const;
		int countChain(Node * currHead) const;
};
