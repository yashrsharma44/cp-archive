#include <bits/stdc++.h>
using namespace std;
int binary_search(vector <int> &A, int l, int r, int val)
{
	while(l<=r)
	{
		int m;
		while(r-l>1)
		{
			m = l + (r-l)/2;
			if(A[m] <= val)
				l=m;
			else
				r=m;
		}

		if(A[l] == val)
			return l;
		else if(A[r]==val)
			return m;
		else
			return -1;
	}
}

int main()
{
	// Binary search with least comparison

	int n, i, val;

	cin>>n;

	vector <int> list(n,0);

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	// int val;
	cout<<"Enter Value";
	cin>>val;

	cout<<binary_search(list, 0, n-1, val);

}