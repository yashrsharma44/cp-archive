#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> &A, int val, int l, int r)
{
	if(l<=r)
	{
		int m = (l+r)/2;

		if(A[m] > val)
		{
			return binary_search(A, val, l, m-1);
		}
		else if(A[m] < val)
		{
			return binary_search(A,val, m+1, r);
		}
		else if(A[m]==val)
		{
			return m;
		}
	}
	else
		return -1;
}

int main()
{
	// Binary Search
	// Recursive
	int n;
	cin>>n;
	int i;

	vector <int> list(n,0);

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}
	int val;
	cout<<"Enter Val to be searched";
	cin>>val;
	cout<<binary_search(list, val, 0, n-1);
}