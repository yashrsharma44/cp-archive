#include <bits/stdc++.h>

using namespace std;

int getMin(int a, int b)
{
	int count=0;
	if(a==b)
		return 0;
	int diff = b - a;
	if(diff > 0)
	{
		int fcount = diff / 5;

		count += fcount;
		diff -= (5*fcount);
	}
	if(diff > 0)
	{
		int tcount = diff / 2;
		count += tcount;
		diff -= (2*tcount);

		
	}
	if(diff > 0)
	{
		int tcount = diff / 1;
		count += tcount;
		diff -= (1*tcount);
	}

	if(diff <= -5)
	{
		int ffcount = abs(diff / (5));
		count += ffcount;
		diff -= (ffcount*(-5));
	}

	if(diff <= -2)
	{
		int ffcount = abs(diff / (2));
		count += ffcount;
		diff -= (ffcount*(-2));
	}

	if(diff <= -1)
	{
		int ffcount = abs(diff / (1));
		count += ffcount;
		diff -= (ffcount*(-1));
	}

	return count;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a, b;
		cin>>a>>b;

		cout<<getMin(a,b)<<endl;
	}
}