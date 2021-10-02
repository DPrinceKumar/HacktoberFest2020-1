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
        all element in array repeted  twice and one is not repeated 
        find that no repeted unoque number
        0011
        0000
     ^  ----
        0011   
    */
   int unique(int a[],int n){
       int xsum = 0;
       for (int i = 0; i < n; i++)
       {
           xsum ^= a[i];
           cout<<xsum<<" ";
       }
       return xsum;
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
    cout<<unique(a,n);
    return 0;
}