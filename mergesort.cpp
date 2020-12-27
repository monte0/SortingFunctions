#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> X)
{
	cout << "[ ";
	for (int i = 0; i < X.size(); i++)
		cout << X[i] << " ";
	cout << "]" << endl;
}

void combine(vector<int> A, vector<int> B, vector<int>& R)
{
	int x = 0;										//INDEX of A
	int y = 0;										//INDEX of B
	int z = 0;										//INDEX of R
	int r = A.size() + B.size();					//combines L1 and L2 arrays to find the max size
	R.resize(r);									//reserves the total size for L3 array
	while (x < A.size() && y < B.size())			//STOP when one of the array is empty
		if (A[x] < B[y])							//checks to see if the element in A is less than the element in B
		{
			R[z] = A[x];							//if A is less than B then store A into R
			x++;									//increment A to check next number
			z++;									//increment index of R so you can place next number
		}
		else
		{
			R[z] = B[y];						//B is less than A then store B into R
			y++;								//increment B to check next number
			z++;								//increment index of R so you can place next number
		}
	//here means one array deoesnt have any more numbers to check
	if (x < A.size())					//check if A is empty	
	{
		for (int i = x; i < A.size(); i++, z++)				//if A not empty then copy rest of A into R
			R[z] = A[i];
	}
	else//here means B still has elements to copy into R
	{
		for (int i = y; i < B.size(); i++, z++)					//copies the rest of B into R
			R[z] = B[i];
	}
}//end of function

// sort N into R
void MergeSort(vector<int> N, int first, int last, vector<int>& R)
{
	vector<int> L1, L2, L1R, L2R;
	// if there is only one element, already sorted, so done.
	if (N.size() == 1)
	{
		R.push_back(N[0]);
		return;
	}

	cout << "Merge sort called on: "; 
	display(N);
	if (first < last)
	{
		// divide N into L1 and L2
		for (int i = 0; i < N.size() / 2; i++)
			L1.push_back(N[i]);
		for (int i = N.size() / 2; i < N.size(); i++)
			L2.push_back(N[i]);

		cout << "1st half:" << endl;
		display(L1);
		cout << "2nd half:" << endl;
		display(L2);

		// sort the first half and produce L1R
		MergeSort(L1, 0, N.size() / 2, L1R);
		// sort the second half and produce L2R
		MergeSort(L2, (N.size() / 2) + 1, N.size(), L2R);

		// combine the sorted halves into sorted R
		cout << "Combining them..." << endl;
		combine(L1R, L2R, R);
		cout << "Combined: " << endl;
		display(R);
	}
}

int main()
{
	vector<int> initialArray, sortedArray;
	int a;
	cout << "Enter the elements one per line." << endl;
	cout << "Enter -1 to stop." << endl;
	cout << "Element:"; cin >> a;
	while (a != -1)
	{
		initialArray.push_back(a);
		cout << "Element:"; cin >> a;
	}
	MergeSort(initialArray, 0, initialArray.size(), sortedArray);  // produce sortedArray

	cout << "Sorted array:" << endl;
	display(sortedArray);
}
