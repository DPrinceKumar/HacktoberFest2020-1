#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
int sum_till(int n)
{
    if (n ==0)
    {
        return 0;
    }
    
    return n+=sum_till(n-1);
}

int main()
{
    int n;
    cin>>n;
    cout<<sum_till(n);
    return 0;
}