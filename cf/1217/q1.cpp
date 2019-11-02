#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long t;
	cin>>t;
	long long i;
	for(i=0;i<t;i++)
	{
		long long str,intel,exp;
		long long count=0;
		cin>>str>>intel>>exp;
		
		
		if(str < intel)
		{
			count = (2*(str-intel) +exp +1)/2 + 1;
		}
		else
		{
			count = (2*(str-intel) + exp + 1)/2 - 1;
		}

		if (count<0)
		{
			count=0;
		}
		if(exp==0)
		{
			if(str>intel)count=1;
			else count=0;
		}

		cout << count << endl;

	}
}