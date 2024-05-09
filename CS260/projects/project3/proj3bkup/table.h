#include "website.h"


class Table {
	public:
		// Constructors and destructors
		Table();
		Table(const Table& aTable);
		~Table();

		void add();
		void find();
		void edit();
		void remove();
		void displayTopic();
		void display();
		void monitor();
	private:
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
		const static int INIT_CAP = 5;
		int currCapacity;
		int size;
		int calculateIndex(const char * key) const; // hashing function
		void destroy();
		void destroyChain(Node *& currHead);
		void copyChain(Node * srcHead, Node *& destHead);
};
