#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    int a[5] = {0} ;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >>x;
        a[x]++;
    }

    int sum = 0;
    sum+=a[4];

    sum+=a[3];

    a[1] = a[1] - a[3];

    if (a[1]<0)
    {
        a[1] = 0;
    }

    sum= sum + a[2]/2;
    // int tem = ;
    if ( a[2] % 2 == 0)
    {
        a[2] = 0;
    }
    else{
        a[2] = 1;
    }

    a[1] = a[1] + a[2]*2;
    if (a[1]%4 == 0)
    {
        sum = sum +  a[1]/4;
    }
    else{
        sum+=((a[1]/4)+1);
    }
    cout<<sum<<endl;
    
    
}
int main()
{

    solve();

    return 0;
}