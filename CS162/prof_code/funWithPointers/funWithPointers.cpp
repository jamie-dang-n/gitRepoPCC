/* Robert Martin
 * Pointer examples.
 * Summer 23, PCC */

#include <iostream>
#include <cstring>
using namespace std;
const int ARRAY_SIZE = 20;

class Thing {
	int num;
	public:
	Thing() { num = 0; } // in-line functions to save space
	void setNum(int number) { num = number; }
	int getNum() { return num; }
};

int main() {
	int num = 10, num2 = 15;
	
	int& numRef = num; // contains address of num
	
	Thing t2;
	Thing* t1; // created uninitialized, might be random or set to 0
	t1 = &t2;
	cout << (*t1).getNum() << endl; // you need to use (*t1)  to dereference here, since dot takes precedence over dereference * 
	cout << t1->getNum() << endl;	// or, you can use ->, which means the same thing as (*). -> is the dereference operator

	int *iPtr; // integer pointer
	iPtr = nullptr; // the NULL pointer
	iPtr = &num; // iPtr contains the address of num
	iPtr = &num2; // &: "Address of" operator
	
	long long address = 0; // must be "long long" in visual studio (VS: long is 32 bits, long long is 64 bits) 
	char str[ARRAY_SIZE] = "Hello";
	int numArray[ARRAY_SIZE] = {0}; // set all values in the array to 0
	char * cPtr = str;

	// Initialize number array
	for(int i = 0; i < ARRAY_SIZE; i++) {
		numArray[i] = i + 1;
	}

	// set iPtr to the first element's address of numArray
	// remember that the name of an array is a pointer, which points to the first value of the array
	iPtr = numArray; // iPtr points to location 0 of the array
	for(int i = 0; i < ARRAY_SIZE; i++) {
		cout << "Each Pointer Address: " << iPtr << endl;
		cout << "Values at each address: " << *iPtr << endl; // use *iPtr to get the value stored at iPtr. if you use just iPtr, you'll just see the addresses themselves 
		iPtr++; // pointer arithmetic
	}
	cout << endl;

	do {
		cout << cPtr << " ";
		address = (long)cPtr;
		cout << address << " ";
		cPtr++;
	} while(*cPtr != '\0');
	return 0;
}
