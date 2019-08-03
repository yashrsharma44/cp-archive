#include <bits/stdc++.h>
using namespace std;
int binary_search(vector <int> &A, int l, int r, int val)
{
	while(l<=r)
	{
		int m = (l+r)/2;

		if(A[m] > val)
		{
			r = m-1;
		}
		else if(A[m] < val)
		{
			l = m+1;
		}
		else if(A[m]==val)
		{
			return m;
		}
	}
	return -1;
}

int main()
{
	// Binary search using iteration

	int n,i,val;

	cin>>n;

	vector <int> list(n,0);

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	cin>>val;

	cout<<binary_search(list, 0, n-1, val);
}