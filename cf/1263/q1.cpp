#include<bits/stdc++.h>

using namespace std;

bool check(long long int a, long long int b,long long int c)
{
	if(a==b || a==c ||b==c)
		return true;
	else
		return false;
}

bool checkMxRepeat(long long int a, long long int b,long long int c)
{
	long long int mx = max(max(a,b),c);

	if((mx==a && mx==b) || (mx==b && mx==c) || (mx==c && mx==a))
	{
		return true;
	}
	return false;
}

int main()
{
	long long int t;
	cin>>t;

	for(long long int i=0;i<t;i++)
	{
		long long int a,b,c;
		cin>>a>>b>>c;

		long long int mx = max(max(a,b),c);

		if(check(a,b,c))
		{
			long long int mn = min(min(a,b),c);

			if(checkMxRepeat(a,b,c))
			{
				cout<<((mx - (mn+1)/2) + mn)<<endl;
			}
			else
			{
				cout<<((a+b+c)-mx)<<endl;
			}
		}
		else
		{
			

			cout<<(min(mx, (a+b+c)-mx))<<endl;
		}
	}
}
