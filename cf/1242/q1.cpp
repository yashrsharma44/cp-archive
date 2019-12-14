#include<bits/stdc++.h>

using namespace std;

bool cmp(int i1, int i2)
{
	return i1<i2;
}

int main()
{
	int k;
	cin>>k;

	for(int i=0;i<k;i++)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int j=0;j<n;j++)
		{
			int a;
			cin>>a;
			arr.push_back(a);
		}

		sort(arr.begin(), arr.end(), greater<int>());

		// for(int j=0;j<n;j++)
		// 	cout<<arr[j]<<" ";
		// cout<<endl;

		int mn=9999;
		int max=-1;
		for(int j=0;j<n;j++)
		{
			int val = min(arr[j], j+1);

			if(max < val)
				max = val;
		}

		cout << max<<endl;
	}
}