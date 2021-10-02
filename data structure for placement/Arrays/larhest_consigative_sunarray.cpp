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
    ll n;
    cin>>n;
    ll a[n];
    ll a1[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    ll lentOf = 2;
    ll prev = a[0] - a[1];
    ll mx = INT_MIN;

    for (int i = 1; i < n-1; i++)
    {
        ll crr = a[i] - a[i+1];
        if (prev == crr)
        {
            lentOf++;        
        }
        else{
            prev = crr;
            lentOf = 2;
        }
        mx = max(mx,lentOf);
    }
    

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a1[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 0; i < n-2; i++)
    // {
        
    //     if (a1[i] == a1[i+1])
    //     {
    //         /* code */
    //         c++;
    //     }
    //     else{
    //         c = 1;
    //     }
    //     mx = max(mx,c);
        
    // }
    
    cout<<mx;
    return 0;
}

