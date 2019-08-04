#include <bits/stdc++.h>

using namespace std;

int search_peak(vector <int> &A, int l, int r, int n)
{
	while(l<=r)
	{
		int m = l + (r-l)/2;

		if((m==n-1||A[m]>=A[m+1]) && (m==0||A[m]>=A[m-1]))
		{
			
			return A[m];
		}
		else if(m>0 &&A[m]<A[m-1])
		{
			r = m-1;
		}
		else
		{
			l = m+1;
		}
	}
	return -1;
}

int main()
{
	// Searching the peak element in an array
	// Peak element is one which is NOT smaller than its neighbours

	int n,i;
	cin>>n;

	vector <int> list(n,0);

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	cout<<search_peak(list,0,n-1, n);
}