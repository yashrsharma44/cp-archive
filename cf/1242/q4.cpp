#include<bits/stdc++.h>

using namespace std;

long long int getDiv(long long int n)
{
	long long int val = sqrtl(n);
	long long int count =0;
	long long int i=1;
	for(;i<=val;i++)
	{
		if (n % i == 0) { 
            
            if (n / i == i) 
                count++; 
  
            else 
                count = count + 2; 
        } 
	}

	return count-1;
}

void SieveOfEratosthenes(long long int n, bool prime[], 
                         bool primesquare[], long long int a[]) 
{ 
    // Create a boolean array "prime[0..n]" and 
    // initialize all entries it as true. A value 
    // in prime[i] will finally be false if i is 
    // Not a prime, else true. 
    for (long long int i = 2; i <= n; i++) 
        prime[i] = true; 
  
    // Create a boolean array "primesquare[0..n*n+1]" 
    // and initialize all entries it as false. A value 
    // in squareprime[i] will finally be true if i is 
    // square of prime, else false. 
    for (long long int i = 0; i <= (n * n + 1); i++) 
        primesquare[i] = false; 
  
    // 1 is not a prime number 
    prime[1] = false; 
  
    for (long long int p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then 
        // it is a prime 
        if (prime[p] == true) { 
            // Update all multiples of p 
            for (long long int i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    long long int j = 0; 
    for (long long int p = 2; p <= n; p++) { 
        if (prime[p]) { 
            // Storing primes in an array 
            a[j] = p; 
  
            // Update value in primesquare[p*p], 
            // if p is prime. 
            primesquare[p * p] = true; 
            j++; 
        } 
    } 
} 
  
// Function to count divisors 
long long int countDivisors(long long int n) 
{ 
    // If number is 1, then it will have only 1 
    // as a factor. So, total factors will be 1. 
    if (n == 1) 
        return 1; 
  
    bool prime[n + 1], primesquare[n * n + 1]; 
  
    long long int a[n]; // for storing primes upto n 
  
    // Calling SieveOfEratosthenes to store prime 
    // factors of n and to store square of prime 
    // factors of n 
    SieveOfEratosthenes(n, prime, primesquare, a); 
  
    // ans will contain total number of distinct 
    // divisors 
    long long int ans = 1; 
  
    // Loop for counting factors of n 
    for (long long int i = 0;; i++) { 
        // a[i] is not less than cube root n 
        if (a[i] * a[i] * a[i] > n) 
            break; 
  
        // Calculating power of a[i] in n. 
        long long int cnt = 1; // cnt is power of prime a[i] in n. 
        while (n % a[i] == 0) // if a[i] is a factor of n 
        { 
            n = n / a[i]; 
            cnt = cnt + 1; // incrementing power 
        } 
  
        // Calculating number of divisors 
        // If n = a^p * b^q then total divisors of n 
        // are (p+1)*(q+1) 
        ans = ans * cnt; 
    } 
  
    // if a[i] is greater than cube root of n 
  
    // First case 
    if (prime[n]) 
        ans = ans * 2; 
  
    // Second case 
    else if (primesquare[n]) 
        ans = ans * 3; 
  
    // Third casse 
    else if (n != 1) 
        ans = ans * 4; 
  
    return ans; // Total divisors 
} 

bool checkPrime(long long int n)
{
	long long int i=2;
	if(n==2||n==3)
		return true;

	long long int val = sqrtl(n);
	if (n%2 == 0 || n%3 == 0) return false; 
  
    for (long long int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false;
  
    return true;
}

int main()
{
	long long int n;
	cin>>n;
	bool bb = checkPrime(n);



	if(checkPrime(n))
	{
		cout<<n<<endl;
	}
	else
	{
		cout<<getDiv(n)<<endl;
	}

}