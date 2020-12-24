#include<iostream>
using namespace std;

// copy your partition function from partition.cpp
int partition1(int a[], int first, int last)
{
	cout << "Partition was called with " << "first " << first << " and last " << last << endl;
	int i = first + 1; // pointer from the left
	int j = last; // pointer from the right
	swap(a[first], a[(first + last) / 2]);			//finds the middle index and swaps it with the first element
	int pivot = a[first];							//pivot is now whatever is in the first index
	while (i <= j)									// while i and j havent crossed yet keep going
	{
		while (a[i] < pivot)						//checks to see if whatever is at i is smaller than pivot
			i++;									//if it is then increment i and test next number
		while (pivot < a[j])						//chekcs to see if whatever is at j is greater than pivot
			j--;									// if it is then decrement j and test next number
		if (i < j)									//check if the number at i is lest than the number at j
			swap(a[i++], a[j--]);					//swap both nubers
		else
			i++;
	}
	swap(a[j], a[first]);							//swap the pivot with the number a j
	return j;										//the numbers to left of j are less than pivot an the numbers right of j are greater than pivot
}

// sorting a section starting at first and ending at last
void quicksort(int a[], int first, int last)
{
	if (first >= last) 
		return;

	cout << "QuickSort: first is " << first << " and last is " << last << endl; 

	int pivotIndex = partition1(a, first, last);

	cout << " ..The pivot element is " << a[pivotIndex] << endl;

	// sort the first section in place
	if (first < last - 1)
		quicksort(a, first, pivotIndex - 1);
	// sort the second section in place
	if (first + 1 < last)
		quicksort(a, pivotIndex + 1, last);
}


int main()
{
	int x;
	int nums[10];
	cout << "How many elements would you like to enter into the array? (must be less than 10) ";
	cin >> x;
	cout << "Enter elements one per line.." << endl;
	for (int i = 0; i < x; i++)
	{
		cin >> nums[i];
	}

	quicksort(nums, 0, x - 1);

	cout << "Sorted array:" << endl;
	for (int i = 0; i < x; i++) // up to the partition
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}
