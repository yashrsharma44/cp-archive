#include <bits/stdc++.h>

using namespace std;
string getVal(string t, int a,int b,int c, int n)
{
	int rc=0;
	int pc=0;
	int sc=0;
	char res[t.length()];
	for (int i = 0; i < t.length(); ++i)
	{
		res[i]='\0';
	}
	for(int i=0;i<t.length();i++)
	{
		if(t.at(i)=='R')
			rc+=1;
		else if(t.at(i)=='P')
			pc+=1;
		else if(t.at(i)=='S')
			sc+=1;
	}
	int maxSum = min(rc, a) + min(pc, b) + min(sc,c);
	if(maxSum < (n+1)/2)
	{
		string n1="";
		return n1;
	}
	int res_r=0,res_p=0,res_s=0;
	for(int i=0;i<t.length();i++)
	{
		res_r = max(rc, a) - min(rc, a);
		res_p = max(pc, b) - min(pc, b);
		res_s = max(sc, c) - min(sc, c);

	}

	for(int i=0;i<t.length();i++)
	{
		char c1 = t.at(i);
		if(c1=='R' && c>0)
		{
			res[i] = 'P';
			a-=1;
		}
		else if(c1=='P' && b>0){
			res[i] = 'S';
			b-=1;
		}
		else if(c1=='S' && a>0){
			res[i] = 'R';
			c-=1;
		}
	}
	int i=0;
	while(res_r>0 && i<t.length())
	{
		char c1=res[i];
		if(c1=='\0'){
			res[i]='R';
			res_r-=1;
		}
		i++;
	}

	i=0;
	while(res_p>0 && i<t.length())
	{
		char c1=res[i];
		if(c1=='\0'){
			res[i]='P';
			res_p-=1;
		}
		i++;
	}
	i=0;
	while(res_s>0 && i<t.length())
	{
		char c1=res[i];
		if(c1=='\0'){
			res[i]='S';
			res_s-=1;
		}
		i++;
	}

	string r(res);
	return r;
}
int main()
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int a,b,c;
		cin>>a>>b>>c;

		string s;
		cin>>s;

		string res=getVal(s,a,b,c,n);
		if(res=="")
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<res<<endl;
		}



	}

}