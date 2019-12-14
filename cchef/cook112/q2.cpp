#include <bits/stdc++.h>

using namespace std;

int getFlip(int dr, int dc, vector<int> &A, vector<int> &B, int n, int m)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if
		}
	}
}

int getDiff(int n,int m, vector<int> &A, vector<int> &B)
{
	int dr=0, dc=0;

	int minFlip = 999;

	for(dr=(-n+1);dr<n;dr++)
	{
		for(dc=(-m+1);dc<m;dc++)
		{
			minFlip = min(minFlip, getFlip(dr, dc, A, B));
		}
	}

	return minFlip;
}

int main()
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		int n,m;
		cin>>n>>m;

		vector< vector <int> >A(n, vector<int>(n));
		vector< vector <int> >B(n, vector<int>(n));

		for(int j=0;j<n;j++)
		{
			for(int k=0k<m;k++)
			{
				cin>>A[j][k];
			}
		}

		for(int j=0;j<n;j++)
		{
			for(int k=0k<m;k++)
			{
				cin>>B[j][k];
			}
		}

		cout<<getDiff(n,m,A,B)<<endl;
	}
}