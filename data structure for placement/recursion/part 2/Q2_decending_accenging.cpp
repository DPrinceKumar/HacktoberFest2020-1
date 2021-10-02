#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
    
void dec(int n){
    if (n == 0)
    {
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}
void inc(int n)
{
    static int i = 0;
    if (n == 0)
    {
    // cout<<"static i : "<<++i<<endl;

        return;
    }
    inc(n-1);
    cout<<n<<endl;
    cout<<"static i : "<<++i<<endl;
    
}
int main()
{
    int t;
    cin>>t;
    dec(t);
    cout<<endl;
    inc(t);
    return 0;
}