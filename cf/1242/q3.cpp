#include<bits/stdc++.h>

using namespace std;

int check(string s1, string s2)
{
	vector<char> a1, a2;
	for(int i=0;i<s1.length();i++)
	{
		char c1 = s1.at(i);
		char c2 = s2.at(i);

		if((c1-'a') == (c2-'a'))
			
			continue;
		else
		{
			a1.push_back(c1);
			a2.push_back(c2);
		}
	}

	vector<int> count1, count2;

	for(int i=0;i<a1.size();i++)
	{
		count1.push_back(a1.at(i) - 'a');
		count2.push_back(a2.at(i) - 'a');
	}

	vector < pair<int,int> > ans();

	for(int i=0;i<a1.size();i++)
	{
		for(int j=0;j<a1.size();j++)
		{
			if(count1[i] > count2[j])
				vect.push_back( make_pair(i,j));
		}
	}

	

	// vector<int> count1, count2;

	// int alpha1[26], alpha2[26];
	// for(int i=0;i<26;i++)
	// {
	// 	alpha1[i]=0;
	// 	alpha2[i]=0;
	// }
	// for(int i=0;i<a1.size();i++)
	// {
	// 	char c1 = a1.at(i);
	// 	char c2 = a2.at(i);

	// 	alpha1[c1 - 'a']+=1;
	// 	alpha2[c2-'a']+=1;
	// }

	// for(int i=0;i<26;i++)
	// {
	// 	if(alpha1[i]>0)
	// 		count1.push_back(alpha1[i]);
	// 	if(alpha2[i]>0)
	// 		count2.push_back(alpha2[i]);
	// }

	// sort(count1.begin(), count1.end());
	// sort(count2.begin(), count2.end());


	// for(int i=0;i<count1.size();i++)
	// {
	// 	if(count1[i]!=count2[i])
	// 		return 0;

	// }

	// return 1;

}

int main()
{
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int n;
		cin>>n;

		string s1, s2;
		cin>>s1;
		cin>>s2;
		if(check(s1,s2)==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}	