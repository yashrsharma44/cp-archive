#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll xoor(ll a,ll b,ll n,ll dd[])
{
if(dd[n] > 0)
return dd[n];
if(n == 0)
{
dd[0] = a;
return dd[0];
}
if(n == 1)
{
dd[1] = b;
return dd[1];
}
dd[n] = xoor(a,b,n-1,dd) ^ xoor(a,b,n-2,dd);
return dd[n];
}
int main()
{	

int T;
int ans[T];
cin >> T;
for( int i = 0;i<T;i++)
{
ll a,b,n;
cin >> a >> b >> n;
}
}
