#include <bits/stdc++.h>

using namespace std;

unsigned long long int get_sum(unsigned long long int m, unsigned long long int n)
{
	unsigned long long int sum=0;
	unsigned long long int sum1=0;
	unsigned long long int k = (m/n);

	for(int i=1;i<=9;i++)
	{
		sum1 += (n*i)%10;
	}

	for(int i=1;i<=(k%10);i++)
	{
		sum += (n*i)%10;
	}

	if(k<10)
	{
		return sum;
	}
	else
	{
		return sum1 * (k/10) + sum;
	}
	// return sum + (k - 10);
}

int main()
{
	int q;
	cin>>q;

	int i;
	for(i=0;i<q;i++)
	{
		unsigned long long int n,m;
		cin>>m>>n;
		cout << get_sum(m,n)<<endl;

	}
}