#include <bits/stdc++.h>

using namespace std;

void count_sort(vector<int> &A)
{
	vector<int> bucket(256, 0);

	int i;
	for(i=0;i<A.size();i++)
	{
		bucket[A[i]]+=1;
	}	

	for(i=1;i<256;i++)
	{
		bucket[i]+=bucket[i-1];
	}

	vector<int> res(A.size(),0);

	for(i=0;i<A.size();i++)
	{
		res[bucket[A[i]]-1] = A[i];
		bucket[A[i]] -=1;
	}

	for(i=0;i<A.size();i++)
		A[i] = res[i];
}
void print(vector<int> &A)
{
	for(int i=0;i<A.size();i++)
		cout<<A[i]<<endl;
}
int main()
{  
    vector<int>arr = {10,1,9,2,8,3,7,4,6,5}; 
  
    count_sort(arr);  
  
    cout<< "Sorted character array is " << endl;
    print(arr);  
    return 0;  
}  