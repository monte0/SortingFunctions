#include<iostream>

using namespace std;

// This function partitions the array a into two sections
// for elements smaller than pivot and larger than pivot.
// first is the index of first element in the section to be partitioned.
// last is the index of last element in the section to be partitioned
// The function returns the index of pivot.
int partition1(int a[], int first, int last)
{
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
}	//end of function

int main()
{
	int x;  // number of elements
	int nums[10];
	cout << "How many elements would you like to enter into the array? (must be less than 10): ";
	cin >> x;
	cout << "Enter the elements one per line" << endl;
	for (int i = 0; i < x; i++)
	{
		cin >> nums[i];
	}

	int pivot_index = partition1(nums, 0, x - 1);

	cout << "The array was partitioned" << endl;
	// display up to the pivot without endl
	for (int i = 0; i < pivot_index; i++)
		cout << nums[i] << " ";

	// display the pivot
	cout << "| " << nums[pivot_index] << " | ";

	// display from the pivot without endl
	for (int i = pivot_index + 1; i < x; i++)
		cout << nums[i] << " ";

	cout << endl;
}