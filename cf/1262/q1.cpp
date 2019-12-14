#include <bits/stdc++.h>
using namespace std;

bool checkIntersection(vector<pair<long long int, long long int> > &arr, long long int l, long long int r)
{
	long long int count=0;
	for(long long int i=0;i<arr.size();i++)
	{
		if(l >= arr[i].first && r <= arr[i].second)
		{
			count+=1;
		}
	}

	if(count == arr.size())
		return true;

	return false;
}

int main()
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		long long int n;
		cin>>n;
		long long int mx=INT_MIN,mn=INT_MAX;

		if(n>1){
			vector<pair<long long int, long long int> > arr;
			for(long long int j=0;j<n;j++)
			{
				long long int l,r;
				cin>>l>>r;
				arr.push_back(make_pair(l,r));
				mx = max(l, mx);
				mn = min(r,mn);
			}

			// cout<<checkIntersection(arr,min(mx,mn), max(mx,mn))<<"L"<<endl;
			

			if(checkIntersection(arr,min(mx,mn), max(mx,mn)))
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<abs(mx-mn)<<endl;
			}
		}
		else
		{
			long long int l,r;
			cin>>l>>r;
			cout<<0<<endl;
		}
	}
}