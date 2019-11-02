#include <bits/stdc++.h>
using namespace std;


bool del(int x, int y)
{
	return x > y ? true : false;
}
int main()
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector<long long> val(n);
		
		for(int i=0;i<n;i++)
		{
			cin >> val[i];
		}

		int count=0;
		int prev = 0;
		int min=val[n-1];
		for(int i=n-1;i>=0;i--)
		{	
			if(val[i] < min)
			{
				min = val[i];

			}
			else if(val[i] > min)
			{
				count+=1;
			}

		}

		cout << count<<endl;

	}
}