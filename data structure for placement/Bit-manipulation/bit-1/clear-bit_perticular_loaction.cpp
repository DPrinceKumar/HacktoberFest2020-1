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
    int p; 
    cin>>p;

    int ans  =  (~(1<<p))&n;
    cout<<ans;
    return 0;
}