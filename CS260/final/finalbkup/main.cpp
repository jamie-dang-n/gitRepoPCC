#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */

	cout << "\nJamie's Code Solutions" << endl;
	cout << "\nCalled sumOfLeafNodes: The sum of all the values in the leaf nodes is " << sumOfLeafNodes(root) << endl;

	node * newRoot = NULL; // empty tree
	cout << "\nCalled copyEven on an empty tree: " << endl;
	copyEven(root, newRoot);
	cout << "Displaying the copied tree:";
	display(newRoot);

	cout << "\nDisplaying original tree:";
    display(root);
    
	// destroy both trees
	destroy(root);
	destroy(newRoot);
    return 0;
}
