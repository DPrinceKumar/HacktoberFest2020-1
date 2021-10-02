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
    int n,p;
    cin>>n;
    cin>>p;

//simple linear time complecity ans. 
// O(n);

    // int res = 1;
    // for (int i = 0; i < p; i++)
    // {
    //     res = res * n;
    // }
    // cout<<res;


// O(logn)
int res = 1;
while (p)
{
    if (p%2 ==  1)
    {
        p--;
        res*=n;
    }
    else{
        n*=n;
        p/=2;
    }
    
}
    cout<<res<<endl;
    // cout<<pow(2,13)< <endl;
    


    
    
    return 0;
}