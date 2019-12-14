#include <bits/stdc++.h>

using namespace std;
  
void SieveOfEratosthenes(long long int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    vector<long long int> arr;
    memset(prime, true, sizeof(prime)); 
  
    for (long long int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (long long int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (long long int p=2; p<=n; p++) 
       if (prime[p]) 
          arr.push_back(p);

    set<long long int> res;
    res.insert(n);
    for(long long int i=0;i<arr.size();i++)
    {
    	long long int k = arr[i];
    	long long int v = n/k;
    	res.insert(v);
    }		
    res.insert(0);

    cout<<res.size()<<endl;

    // set <long long int> :: iterator itr;
    for(auto elem : res){
    	cout<<elem<<" ";
    }

    cout<<endl;
    return;


} 

void getFactors(long long int n)
{
	vector<long long int> arr;
	arr.push_back(0);
	arr.push_back(1);
	if(n<=2)
	{
		cout<<arr.size()<<endl;
		for(long long int i=0;i<arr.size();i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return;
	}

	for(long long int i=3;i<=sqrt(n);i+=2)
	{
		if(n%i!=0)
		{

		}

	}
}

int main()
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		long long int n;
		cin>>n;
		SieveOfEratosthenes(n);	

	}
}