#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &A, int p, int n, int c)
{
    if(p<0)
    {
        if(A[c] == A[n])
    }
    if(A[p] == A[n])
        return true;
    else
    return false;
}

int main()
{
    // Prob B

    int n;
    cin>>n;
    
    vector<int> list(n);

    int i;
    for(i=0;i<n;i++)
    {
        cin>>list[i];
    }

    int prev=-1,next=-1, curr;
    int count=0;
    for(i=0;i<n;i++)
    {
        prev = i-1;
        curr = i;
        next = i+1;

        if(comp(list, prev, next))
        {
            count+=1;
        }

    }

    return count;

}