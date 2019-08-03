#include <bits/stdc++.h>

using namespace std;

int find_floor(vector <int> &A, int l, int r, int val)
{
	while(r-l>1)
	{
		int m=l + (r-l)/2;
		if(A[m] <= val)
			l=m;
		else
			r=m;
	}
	// cout<<l;
	return A[l];
}

int main()
{
	int n,i,val;
	cin>>n;

	vector <int> list(n,0);

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}
	cout<<"Enter";
	cin>>val;
	if(val < list[0])
	{
		cout<<"Not Found";
	}
	else
	{
		cout<<find_floor(list,0,n,val);
	}
}