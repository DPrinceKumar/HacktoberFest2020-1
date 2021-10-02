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
    ll r,c;
    cin>>r>>c;

    ll arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    int sch;
    bool f = false;
    cin>>sch;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == sch)
            {
                f = true;
            }
            
        }
        
    }
    if (f)
    {
        cout<<"Elemet is Found";
    }
    else{
        cout<<"Elemet is not Found";
    }
    
    
    
    return 0;
}