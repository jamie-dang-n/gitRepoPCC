/*This is the starter file for Midterm Practice 2.
  You will write a function name keepUnique that accepts an array of integers
  numbers and it's length as parameters and removes multiple occurences of an element
  in the array and returns the count of unique values that occur in the array.
  An element is "removed" by shifting all subsequent elements one index to the left 
  to cover it up, placing a 0 into the last index.  
  The original ordering of number's elements should be retained or remain the same.
  Please see examples in the midterm practice 2 document.*/

#include <iostream>

using namespace std;

void keepUnique(int numbers[], int count);

int main()
{

	// Sample 1
	int numbers[] = {7, 7, 2, 2, 1, 2, 2, 7};
	keepUnique(numbers, 8);

	// Sample 2
	// int numbers[] = {42, 3, 9, 42};
	// keepUnique(numbers, 4);

	// Sample 3
	// int numbers[] = {3, 3, 3, 3};
	// keepUnique(numbers, 4);

	// Sample 4
	// int numbers[] = {42};
	// keepUnique(numbers, 1);	

	cout << "Array Numbers After: " << endl;
	for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	return 0;
}

// Name:         keepUnique
// Description:  This function removes all repeated values in a list,
//               keeping the first unique instance. It also tracks the 
//               count of the unique numbers in the list.
// Input:        int numbers[], int count
// Output:       none
// Return:       none
void keepUnique(int numbers[], int count) {
	int uniqueCount = 0;
	int i = 0;
	int j = count - 1;
	for (i = 0; i < count; i++) {
		for (j = count - 1; j >= 0; j--) {
			if (numbers[i] == numbers[j] && j != i) {
				for (int k = j; k < count - 1; k++) {
					numbers[k] = numbers[k + 1];
				}
				count = count - 1;
				numbers[count] = 0;
			}
		}
	}
	uniqueCount = count;
	cout << "Unique Values = " << uniqueCount << endl;
}

