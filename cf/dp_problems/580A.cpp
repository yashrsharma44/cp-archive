#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;

	vector<int> res;

	for(int i=0;i<n;i++){

		int a;
		cin>>a;
		res.push_back(a);
	}

	int len_max=1;
	int mx = -1;
	for(int i=1;i<res.size();i++){

		if(res[i-1] <= res[i]){
			len_max+=1;
		} else {

			mx = max(mx, len_max);
			len_max = 1;
		}
	}

	cout << max(len_max, mx)<<endl;

}