#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
    
int main()
{
    int n;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

     
    int NS = 1000;
    int idx[NS];
    for (int i = 0; i < NS; i++)
    {
        idx[i] = -1;
    }
    // for (int i = 0; i < NS; i++)
    // {
    //     cout<<idx[i]<<" ";
    // }
    
    int minidx  = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (idx[a[i]] != -1)
        {
            minidx = min(minidx,idx[a[i]]);
        }
        else{
            // cout<<"dsa";
            idx[a[i]] = i; 
        }
        
    }
    if (minidx == INT_MAX)
    {
        cout<<-1<<endl;
    }
    else{
    
    cout<<"dsadsad "<<minidx+1;

    }
    //     for (int i = 0; i < NS; i++)
    // {
    //     cout<<idx[i]<<" ";
    // }
 
    
    return 0;
}