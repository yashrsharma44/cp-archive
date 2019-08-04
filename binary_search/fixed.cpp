#include <bits/stdc++.h>

using namespace std;

int search(vector <int> &A, int l, int r)
{
	while(l<=r)
	{
		int m = l + (r-l)/2;

		if(A[m]==m)
		{
			return m;
		}
		else if(A[m]>m)
		{
			r=m-1;
		}
		else if(A[m]<m)
			{
				l=m+1;
			}
	}
	return -1;
}

int main()
{
	// Finding an elem such that a[i] == i
	// Using Binary search
	int i,n;
	cin>>n;
	vector <int> list(n,0);

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	cout<<search(list,0,n-1);
}