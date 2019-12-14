#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}

int main()
{
	int n;
	cin>>n;

	vector< vector<int> > arr(n-2);

	for(int i=0;i<n-2;i++)
	{
		vector<int> a(3);
		cin>>a[0]>>a[1]>>a[2];
		arr.push_back(a);
	}

	set<int> ans;

	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<arr[i].size();j++)
		{
			ans.insert(arr[i].at(j));
		}
	}

	for(int val: ans)
	{
		cout<<val<<" ";
	}
}