/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Assignment 3
# Date:             4/24/2023
# Description:	    This program prompts the user for a list of numbers.
#		    After receiving the list of numbers, the program checks
#		    for the min/max value, the median, the mean, and whether
#		    the array (made from the user's list) is a palindrome or not.
#		    All of this is done after the array is sorted with a selection
#		    sort.
# Input:            int num
# Output:           Prompts for num, error messages, welcome message, thank you
#		    message, and the min/max/median/mean/palindrome responses.
# Sources:          Assignment 3 Specifications, GD Iyer's Sample01 Code
#******************************************************************************/
#include <iomanip>
#include <iostream>
#include <limits> // for cin.ignore
using namespace std;

// Constants
const int MAXINT = 20;
const int MAXCHAR = 100;

// Function Prototypes
void readInput(int list[], int& count);
void validateInput(int list[], int count, const char prompt[]);
void maxmin(int list[], int count, int& max, int& min);
double avgArray(int list[], int count);
bool isPalindrome(int list[], int count);
void sort(int list[], int count);
double median(int list[], int count);


// Main
int main() {
	int userArray[MAXINT] = { 0 };
	int count = 0;
	int max = 0;
	int min = 0;
	double mean = 0.0;
	double userMedian = 0.0;
	bool userPalindrome = true;

	// Input
	cout << "Welcome to my Array Statistics Program!" << endl;
	readInput(userArray, count);

	// Calculate Statistics and Sort
	userPalindrome = isPalindrome(userArray, count);
	sort(userArray, count);
	maxmin(userArray, count, max, min);
	mean = avgArray(userArray, count);
	userMedian = median(userArray, count);

	// Output
	cout << endl; // blank line
	cout << fixed << setprecision(1);
	cout << "Your stats are as below:" << endl;
	cout << "Minimum: " << min << endl;
	cout << "Maximum: " << max << endl;
	cout << "Mean: " << mean << endl;
	cout << "Palindrome: ";
	if (userPalindrome) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	cout << "Median: " << userMedian << endl;

	cout << endl; // blank line
	cout << "Thank you for using my Array Statistics Program!!" << endl;

	return 0;
}

// Function Definitions

//Name:   readInput()
//Desc:   This function reads in input from the user and updates the count variable.
//input:  int list[], int count by reference
//output: prompt for the integer
//return: none
void readInput(int list[], int& count) {
	char prompt[MAXCHAR] = "Please enter the values for the array (negative number to end input): ";
	cout << prompt;
	while (list[count] >= 0 && count <= MAXINT) {
		validateInput(list, count, prompt);
		if (list[count] >= 0) {
			count++;
		}
	}


}

//Name:   validateInput()
//Desc:   This function validates input from the user
//input:  int list[], int count, const char prompt
//output: prompt for the integer, error message
//return: none
void validateInput(int list[], int count, const char prompt[]) {
	char error[MAXCHAR] = "Error: Please enter an integer value or a negative number to quit.";

	cin >> list[count];
	while (!cin || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << error << endl;
		cout << prompt;
		cin >> list[count];
	}

}


//Name:   maxmin()
//Desc:   This function finds the maximum and minimum value of the array.
//input:  int list[], int count, int max and min by reference
//output: none
//return: none
void maxmin(int list[], int count, int& max, int& min) {
	max = list[0];
	min = list[0];
	for (int i = 0; i < count; i++) {
		if (list[i] > max) {
			max = list[i];
		}
		if (list[i] < min) {
			min = list[i];
		}
	}
}

//Name:   avgArray()
//Desc:   This function finds the average value of the array.
//input:  int list[], int count
//output: none
//return: double avg
double avgArray(int list[], int count) {
	int sum = 0;
	double avg = 0.0;
	for (int i = 0; i < count; i++) {
		sum += list[i];
	}
	avg = sum / (count * 1.0);

	return avg;
}

//Name:   isPalindrome()
//Desc:   This function decides if an unsorted array is a palindrome.
//input:  int list[], int count
//output: none
//return: true or false, depending on if the array is a palindrome.
bool isPalindrome(int list[], int count) {
	int j = count - 1;
	for (int i = 0; i < count; i++) {
		if (list[i] != list[j]) {
			return false;
		}
		j--;
	}
	return true;
}


//Name:   sort()
//Desc:   This function sorts the list from least to greatest.
//		  The function uses selection sort.
//input:  int list[], int count
//output: none
//return: none
void sort(int list[], int count) {
	int unsortedMarker = 0;
	int minIndex = 0;
	int currMin = list[0];
	int temp = 0;
	while (unsortedMarker < count) {
		currMin = list[unsortedMarker];
		for (int i = unsortedMarker; i < count; i++) {
			if (list[i] < currMin) {
				currMin = list[i];
				minIndex = i;
			}
		}
		temp = list[unsortedMarker];
		list[unsortedMarker] = list[minIndex];
		list[minIndex] = temp;
		unsortedMarker++;
	}
}

//Name:   median()
//Desc:   This function returns the median of the sorted array.
//input:  int list[], int count
//output: none
//return: double median
double median(int list[], int count) {
	int medianIndex = count / 2;
	double median = 0.0;
	if ((count % 2) != 0) {
		median = list[medianIndex];
	}
	else {
		median = (list[medianIndex] + list[medianIndex + 1]) / 2.0;
	}
	return median;
}
