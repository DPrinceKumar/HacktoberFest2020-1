#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
 /*
    n = 6 = (0110)
    n-1 = 5 = (0101)
    0110 & 0101 = 0100


    n = 8 = (1000) 
    n-1 = 7 = (0111)
    1000 & 0111 = 0000;
    if(n is pow of 2 then ((n & n-1) = 0))
 */   
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
            int n;
    cin>>n;
    int ans = ( n )&  (n-1);
    cout<<ans<<endl;
    }
    return 0;
}