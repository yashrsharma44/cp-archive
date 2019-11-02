#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<int> list(n);
	int i;
	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	// Find the diff between max and all elements
	// If diff is even then cost is 0
	// else 1

	int max=-1;

	for(i=0;i<n;i++)
	{
		if(list[i] > max)
		{
			max = list[i];
		}
	}

	int cost=INT_MAX;
	int cost1 =0;
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			
			if(i!=j)
			{
				cost1 += abs(list[i] - list[j])%2;
			}
		}
		// cout << cost1<<endl;
		if(cost1 <= cost)
		{
			cost = cost1;
		}
		cost1=0;
	}

	cout << cost;
}