#include <bits/stdc++.h>

using namespace std;

void checkValid(long long int n, long long int k, vector<long long int> &arr)
{
	int i;
	for(i=0;i<arr.size()-1;i++)
	{
		if(arr[i] < k)
		{
			cout <<"NO "<<(i+1)<<endl;
			return;
		}
		else
		{
			arr[i+1] += arr[i] - k;
		}
	}
	if(arr[i] < k)
	{
		cout<<"NO "<<(i+1)<<endl;
		return;
	}
	cout<<"YES"<<endl;
	return;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long n,k;
		cin>>n>>k;
		vector<long long int> arr(n);

		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
		}

		checkValid(n,k,arr);
	}
}