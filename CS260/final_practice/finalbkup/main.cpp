#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */

	cout << "\nJamie's Code Solutions\n" << endl;
	cout << "Result of Call to numberOfNodes: " << numberOfNodes(root) << endl << endl;

	cout << "Result of Call to removeSmallest: ";
	removeSmallest(root);
    display(root);


	cout << "Result of Call to removeEven: " << endl;
	cout << "Number of nodes removed: " << removeEven(root);
	display(root);


    destroy(root);
    return 0;
}
