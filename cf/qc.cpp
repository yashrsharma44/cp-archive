#include <bits/stdc++.h>

using namespace std;

bool recur(string s1)
{
	if(s1.length() == 1 || s1=="")
		return false;

	int n=s1.length();

	int j=n-1;
	string s2="";
	for(;j>=0;j--)
	{
		s2 += s1.at(j);
	}
	j=n-1;
	int left=0,right=0;
	int flag=0;
	for(int i=0;i<s1.length();i++)
	{
		if(s1.at(i) != s2.at(j))
		{
			left=i;
			right=j;
			flag=1;
		}
		j--;
	}
	cout << "S1" << s1;
	cout << "S2" << s2;

	if(flag)
		return recur(s1.substr(left, right+1));
	else
		return true;
}

int main()
{
	int n;
	cin>>n;

	string s1="";
	cin>>s1;
	
	int size = s1.length();

	if(size%2==1)
	{
		cout << "No";
	}
	else
	{
		int left=0, right=0;
		for(int i=0;i<size;i++)
		{
			if(s1.at(i) == '(')
			{
				left+=1;
			}
			if(s1.at(i) == ')')
			{
				right+=1;
			}
		}

		if(abs(left-right)%2==0)
		{
			cout << "Yes";						
		}
		else
		{
			cout <<"No";
		}
	}
}