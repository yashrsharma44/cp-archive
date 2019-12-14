#include <bits/stdc++.h>

using namespace std;

int getWeight(int a, int b, int *arr)
{
	return (arr[a] + arr[b]);
}

bool comp(const pair< pair< int, int>, int > &a, const pair< pair< int, int>, int> &b)
{
	return a.second < b.second;
}

void getMin(int a, int b, int *arr)
{
	// If number of edges in less than number of nodes 
	if(b < a)
	{
		cout<<-1<<endl;
		return;
	}

	if(b==2 && a<=b)
	{
		cout<<-1<<endl;
		return;
	}

	vector< pair< pair<int, int> , int > > edgeList;


	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(i<j)
			{
				edgeList.push_back(make_pair(make_pair(i,j), arr[i-1]+arr[j-1]));
			}

		}
	}

	
	vector< pair<int, int> > ans;
	int sum=0;
	int counter = 1;
	for(int i=1;i<a;i++)
	{

		ans.push_back(make_pair(i, i+1));
		sum+= arr[i-1] + arr[i];
		
	}
	ans.push_back(make_pair(a,1));
	sum+= arr[0]+arr[a-1];


	sort(edgeList.begin(), edgeList.end(), comp);


	int j=0;
	while(j<(b-a))
	{
		ans.push_back(edgeList[j].first);
		sum+= edgeList[j].second;
		j++;
	}
	

	cout << sum << endl;

	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}

}

int main()
{

	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		int n,m;
		cin>>n>>m;

		int a[n];
		for(int j=0;j<n;j++)
			cin>>a[j];

		getMin(n,m,a);
	}
}
