#include <bits/stdc++.h>

using namespace std;

int main(){

	long long int n;
	cin>>n;

	// vector<long long int> arr;

	long long int count[10005];

	for(long long int i=0;i<n;i++){
		long long int a;
		cin>>a;
		count[a]+=1;
		// arr.push_back(a);
	}

	long long int dp[10005];

	dp[0] = 0;
	dp[1] = count[1];

	for(long long int i=2;i<10005;i++){
		dp[i] = max(dp[i-1], dp[i-2]+i*count[i]);
	}

	cout<<dp[10005-1]<<endl;


}