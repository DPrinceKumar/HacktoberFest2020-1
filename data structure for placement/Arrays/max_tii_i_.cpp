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
    int n,idx;
    cin>>n>>idx;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int mx = INT_MIN;
    for (int i = 0; i < idx; i++)
    {
        mx = max(mx,a[i]);
    }
    
    cout<<mx;
    return 0;
}