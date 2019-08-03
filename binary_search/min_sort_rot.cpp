#include <bits/stdc++.h>
using namespace std;
int min_ele(vector <int> &A, int l,int r)
{
	while(l<=r)

	{
		int m = l + (r-l)/2;
		if(A[l]< A[r])
		{
			return A[l];
		}
		else if(A[m] > A[r])
		{
			l=m+1;
		}
		else if(A[m]<A[r])
		{
			r=m;
		}
		else if(l==r)
		{
			return A[l];
		}
	}
	return -1;
}

int main()
{
	// Binary search to find the minimum element
	// from the sorted rotated array

	int i,val,n;
	cin>>n;
	vector <int> list(n,0);

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	cout<<min_ele(list, 0, n-1);
}