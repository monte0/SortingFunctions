#include <iostream>
#include <vector>

using namespace std;

// combines two sorted lists A and B into R.
// displays comparison every time it is done.
// The size of A and B are the same or A is 1 element shorter
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
			cout << "comparison between " << A[x] << " and " << B[y] << endl;
			R[z] = A[x];							//if A is less than B then store A into R
			x++;									//increment A to check next number
			z++;									//increment index of R so you can place next number
		}
		else
		{
			cout << "comparison between " << A[x] << " and " << B[y] << endl;
			R[z] = B[y];						//B is less than A then store B into R
			y++;								//increment B to check next number
			z++;								//increment index of R so you can place next number
		}
	//here means one array deoesnt have any more numbers to check
	cout << "The rest of the second sublist is copied to R" << endl;
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

int main()
{
	vector<int> L1;
	vector<int> L2;
	vector<int> L3;
	int N;  // number of elements in each of L1 and L2
	int e;  // to enter each element

	cout << "How many elements would you like to enter into each sublist?" << endl;
	cin >> N;

	cout << "Please enter elements of List1 in ascending order:" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << "element :";
		cin >> e;												//user enters a number
		L1.push_back(e);
	}

	cout << "Please enter elements of List2 in ascending order:" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << "element :";
		cin >> e;
		L2.push_back(e);
	}

	// call combine here to combine L1 and L2 into L3
	combine(L1, L2, L3);

	cout << "The combined list is: " << endl;
	for (int i = 0; i < N * 2; i++)
	{
		cout << L3[i] << endl;
	}
	cout << endl;
}// end of main
