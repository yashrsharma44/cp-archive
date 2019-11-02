#include<bits/stdc++.h>
using namespace  std;

string getVal(string t, int a,int b,int c, int n)
{
	int rc=0;
	int pc=0;
	int sc=0;
	for (int i = 0; i < t.length(); i++)
	{
		if (t[i]=='R') rc++;
		if (t[i]=='P') pc++;
		if (t[i]=='S') sc++;
	}
	int ans= 0;
	int r1, p1, s1;
	int r2, p2, s2;

	r1 = min(sc, a);
	p1 = min(b, rc);
	s1 = min(c, pc);
	//cout << "r1 = " << r1 << " p1 = " << p1 << " s1 = " << s1 << endl;
	ans= r1+p1+s1;
	r2 = r1;
	p2 = p1;
	s2 = s1;
	vector<char> res(t.length(), 'x');

	if (ans >= (n+1)/2)
	{
		for (int i = 0; i < t.length(); i++)
		{
			if (t[i]=='R' && b > 0)
			{
				res[i]='P';
				b--;
			}
			if (t[i]=='P' && c > 0)
			{
				res[i]='S';
				c--;
			}
			if (t[i]=='S' && a > 0)
			{
				res[i]='R';
				a--;
			} 
		}

		//cout << "r1 = " << r1 << " p1 = " << p1 << " s1 = " << s1 << endl;
		for (int i =0; i < t.length();i++)
		{
			if (res[i]=='x')
			{
				if (b > 0)
				{
					res[i] = 'P';
					b--;
				}else if (a > 0)
				{
					res[i] = 'R';
					a--;
				}else if (c > 0)
				{
					res[i] = 'S';
					c--;
				}
			}
		}

		string ansfinal;
		for (int i = 0; i < t.length() ; i++)
			ansfinal += res[i];
		return ansfinal;

	}else
	{
		return "";
	}

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