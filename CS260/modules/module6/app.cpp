#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

const int CAP = 100;
void populateSortedList(int list[]);
void insert(int list[], int size, int val);
void displayList(int list[]);

int linearSearch(int list[], int target, int& count);
int binarySearch(int list[], int target, int& count);

int main()
{
	int		list[CAP];
	int 	target;
	int		count;
	int		index;

	populateSortedList(list);
	displayList(list);
	target = rand() % 100;
	count = 0;
	index = linearSearch(list, target, count);
	if(index >= 0)
	{
		cout << "Linear search found " << target << " at list[" << index << "]" 
			<< " after " << count << " iteration" << endl;
	}
	else
	{
		cout << target << " is not in the list after " << count << " iterations!"
			 << endl;
	}

	count = 0;
	index = binarySearch(list, target, count);
	if(index >= 0)
	{
		cout << "Binary search found " << target << " at list[" << index << "]" 
			<< " after " << count << " iteration" << endl;
	}
	else
	{
		cout << target << " is not in the list after " << count << " iterations!"
			 << endl;
	}

	return 0;
}

int linearSearch(int list[], int target, int& count)
{
	int index;
	for(index=0; index<CAP; index++)
	{
		if(list[index] == target)	
		{
			count = index + 1;
			return index;
		}
		if(list[index] > target)
		{
			count = index + 1;
			return -1;
		}
	}
	count = CAP;
	return -1;
}

int binarySearch(int list[], int target, int& count)
{
	int 	first = 0;
	int 	last = CAP-1;
	int	 	mid;
	count = 0;
	while(first <= last)
	{
		count++;
		mid = (first + last) / 2;
		if(list[mid] == target)
		{
			return mid;
		}
		else if(list[mid] < target)
		{
			first = mid + 1;
		}
		else
		{
			last = mid - 1;
		}
	}
	return -1;
}
			
void populateSortedList(int list[])
{
	srand(time(nullptr));
	for(int i=0; i<CAP; i++)
	{
		insert(list, i, rand()%100);
	}
}

void insert(int list[], int size, int val)
{
	int i;
	for(i=0; i<size; i++)
	{
		if(list[i] >= val)
		{
			for(int j=size; j>i; j--)
			{
				list[j] = list[j-1];
			}
			break;
		}
	}
	list[i] = val;
	size++;
	return;
}

void displayList(int list[])
{
	cout << "The list ..." << endl;
	for(int i=0; i<CAP; i++)
		cout << list[i] << ' ';
	cout << endl;
}
