#include <bits/stdc++.h>
#include <unordered_map> 

using namespace std;

// void print_map(unordered_map<int,int> map)
// {
// 	for(auto x: map)
// 		cout<<"{"<<x<<"}";
// 	// cout<<map<<endl;
// 	cout<<endl;

// }

int getSeq(int N)
{	
	int i;
	int a[N];
	for(int i=0;i<N;i++)
		a[i]=0;
	for(i=0;i<N-1;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]==a[i])
			{
				a[i+1] = i - j;
				break;
			}
			
		}
	}
	// int val = a[i+1];
	// int ind = i+1;
	int count=0;
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	int val = a[N-1];
	for(int i=0;i<N;i++)
	{
		if(val == a[i])
			count++;
	}

	return count;
}

int main()
{
	int N, T;

	cin>>T;

	for(int i=0;i<T;i++)
	{
		int N;
		cin>>N;

		cout<<getSeq(N)<<endl;
	}


}