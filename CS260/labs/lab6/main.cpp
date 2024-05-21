#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
	cout << "Recursive count: " << count(root) << endl;
	cout << "Recursive sum: " << sum(root) << endl;
	cout << "Height of the tree: " << height(root) << endl;

    display(root);
    destroy(root);
    return 0;
}
