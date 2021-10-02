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
    ll c = 0 ; // count number of days

    ll mx = INT_MIN;
    for (int i = 0; i < n-1; i++)
    {
        if ((a[i] >  mx )&& (a[i] > a[i+1]))
        {
            c++;
            // sum = 0;
        }        
        mx = max(mx,a[i]);
    }
    if ((a[n-1] > mx )&&(a[n-1] > a[n-2]))
    {
        c++;
    }
    
    cout<<c<<endl;
    
    
    return 0;
}

 