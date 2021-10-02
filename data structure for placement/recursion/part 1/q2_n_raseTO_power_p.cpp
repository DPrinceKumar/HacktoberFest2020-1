#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
int solve(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    
    return n * solve(n,p-1);
}
int main()
{
    int n,p;
    cin>>n>>p;
    cout<<solve(n,p);
    return 0;
}