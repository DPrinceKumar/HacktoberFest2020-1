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
    int n,idx;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            /* code */
            for (int k = i; k <= j; k++)
            {
                /* code */
                cout<<a[k]<<" ";
                sum+=a[k];    
            }

            cout<<endl;
            
        }
        
    }
    cout<<"SUM : "<<sum <<endl;
    return 0;
}