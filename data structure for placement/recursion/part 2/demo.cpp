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
    int t = 3;
    int a[t] ={1,2,3};
    int res = 0;
    for (int i = 0; i < t; i++)
    {
        res += a[i]  * (i+1) * (t-i); 
    }

    cout<<res;
    
    return 0;
}