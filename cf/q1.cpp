#include <bits/stdc++.h>
using namespace std;



int main()
{
    // Recursive XORinacci :P

    long long t;
    cin>>t;

    vector< vector<long long> > list(t);
    long long i;
    for(i=0;i<t;i++)
    {
        vector<long long> l(3);
        long long a,b,n;
        cin>>a>>b>>n;
        l[0] = a;
        l[1] = b;
        l[2] = n;

        list[i] = l;
    }

    vector<long long> output(t,-1);


    for(i=0;i<t;i++)
    {

        int a = list[i][0];
        int b = list[i][1];
        int n = list[i][2];

        int x = n%3;
        if(x==0)
        {
            output[i] = a;
        }
        else if(x==1)
        {
            output[i] = b;
        }
        else if(x==2)
        {
            output[i] = a^b;
        }
        
        // res = 0;
    }

    // Prrlong long the result
    for(long long j=0;j<t;j++)
    {
        cout<<output[j]<<endl;
    }

}