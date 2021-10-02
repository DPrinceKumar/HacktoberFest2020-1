#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
bool check(int a[], int n){
    if (n==1)
    {
        return true;
    }
    
    bool rest_array = check(a+1,n-1);
   return (a[0] < a[1] && rest_array);
    
    
    return false;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<< (check(a,n));

    
    
    return 0;
}