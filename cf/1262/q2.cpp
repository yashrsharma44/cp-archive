#include <bits/stdc++.h>

using namespace std;

void getVal(long long int val, set<long long int> &st, vector<long long int> &res)
{
	set<long long int> :: iterator itr;
	for(itr=st.begin();itr!=st.end();itr++)
	{
		if((*itr)<=val)
		{
			res.push_back(*itr);
			st.erase(*itr);
			return;
		}
	}
}

int main()
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		long long int n;
		cin>>n;
		vector<long long int> arr;
		for(long long j=0;j<n;j++)
		{
			long long int val;
			cin>>val;
			arr.push_back(val);
		}

		vector<long long int> res;
		set<long long int> st;
		for(long long j=1;j<=n;j++)
		{
			st.insert(j);
		}
		for(long long j=0;j<n;j++)
		{
			long long int val =arr[j];
			getVal(val, st, res);
		}

		for(long long j=0;j<n;j++)
		{
			cout<<res[j]<<" ";
		}
		cout<<endl;
	}
}