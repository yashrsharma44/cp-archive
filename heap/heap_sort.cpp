#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
	int k = *x;
	*x = *y;
	*y = k;
}

// Function performing the heapify
void heapify(int *A, int n, int i)
{
	int larg = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	// If left child is larger than root
	if(l < n && A[l] > A[larg])
		larg = l;

	if(r < n && A[r] > A[larg])
		larg = r;

	if(larg!=i)
	{
		swap(A[i], A[larg]);
		heapify(A, n, larg);
	}
}

// Main function to do heap sort
void heapsort(int *A, int n)
{
	// Build Heap
	for(int i=n/2 -1; i>=0;i--)
		heapify(A, n, i);

	for (int i=n-1; i>=0; i--) 
    {
		// One by one extract an element from heap
		swap(A[0], A[i]);
		
		// Call heapify on the reduced heap
		heapify(A,i,0);
	}
}

void printArray(int *A, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << A[i] <<" ";
	}

	cout << endl;
}

int main()
{
	// Function to demonstrate the heapsort
	int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapsort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
}