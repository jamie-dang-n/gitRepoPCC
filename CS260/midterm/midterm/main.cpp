#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	// Calling sumEven()
	cout << endl; // blank line
	cout << "Jamie's Solution" << endl;
	cout << "[sumEven()] Count of even numbers is: " << sumEven(head) << endl;
	cout << "[tagEven()] The number of evenly tagged nodes is: " << tagEven(head) << endl;
    cout << "[tagEven()] The list after calling tagEven is:";
	display(head);
    destroy(head);    
    return 0;
}
