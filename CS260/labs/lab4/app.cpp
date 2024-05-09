#include <iostream>
#include "linkedlist.h"

using namespace std;

static const int	N_RANDS{9};

int* randomArray(int lgth);

int main()
{
	int*		ar{randomArray(N_RANDS)};
	LinkedList	list;
	
	for (int i{0}; i < N_RANDS; i++)
		list.add(ar[i]);

	cout << "sum() =  " << list.sum()  << endl;
	cout << "sumR() = " << list.sumR() << endl;

	delete[] ar;
	return 0;
}
