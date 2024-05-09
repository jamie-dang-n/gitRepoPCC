#include <iostream>
#include <fstream>
#include "website.h"

using namespace std;

class Table {
	public:
		// Constructors and destructors
		Table();
		Table(const Table& aTable);
		~Table();

		// Public Methods
		void add();
		void find();
		void edit();
		void remove();
		void displayTopic();
		void monitor();
		void loadFromFile(const char * fileName);

		// Operators
		const Table& operator= (const Table& srcTable);
		//friend ostream& operator<< (ostream& out, const Table& aTable);	
	private:
		struct Node {
			// Node Constructor
			Node(const Website& aSite) {
				data = new Website(aSite);
				next = nullptr;
			}

			// Node data members
			Website * data;
			Node * next;
		};
		Node ** aTable;
		const static int INIT_CAP = 5;
		int currCapacity;
		int size;
		int calculateIndex(const char * key) const; // hashing function
		void destroy();
		void destroyChain(Node *& currHead);
		void copyChain(Node * srcHead, Node *& destHead);
};
