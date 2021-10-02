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
    string s;
    cin>>s;
    int mx = -2222;
    for (int i = 0; i < s.size(); i++)
    {
        int x = s[i] - '0';
        mx = max(x,mx);
        // cout<<x<<endl;
    }
    cout<<mx<<endl;

    return 0;
}