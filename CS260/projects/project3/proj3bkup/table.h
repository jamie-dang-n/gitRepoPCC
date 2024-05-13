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
		bool retrieve(char * topicKeyword, Website matches[], int & numFound);
		bool edit(char * topicKeyword, char * targetAddress, char * userReview, int userRating);
		bool remove();
		bool displayTopic(char * topicKeyword);
		void display() const;
		void monitor();
		void loadFromFile(const char * fileName);

		// Operators
		const Table& operator= (const Table& srcTable);
		//friend ostream& operator<< (ostream& out, const Table& aTable);	
	private:
		// Constants
		const static int INIT_CAP = 5;
		const static int MAX_CHAR = 200l;

		// Data Members
		struct Node {
			// Node Constructor
			Node() {
				next = nullptr;
			}

			Node(const Website& aSite) {
				data = aSite;
				next = nullptr;
			}

			// Node data members
			Website data;
			Node * next;
		};
		Node ** aTable;
		int currCapacity; // holds the maximum capacity of the table
		int size; 		  // holds the current number of entries in the table
		// Private Methods
		int calculateIndex(const char * key) const; 		// hashing function
		void destroy(); 									// destroys the table
		void destroyChain(Node *& currHead); 				// helper function for destroy()
		void copyChain(Node * srcHead, Node *& destHead); 	// helper function to copy chains
		void displayChain(Node * currHead) const; 			// helper function to display chains
		int countChain(Node * currHead) const; 				// counts number of entries in a chain
		void lowercase(char * temp); 						// sets temp char array to lowercase
};
