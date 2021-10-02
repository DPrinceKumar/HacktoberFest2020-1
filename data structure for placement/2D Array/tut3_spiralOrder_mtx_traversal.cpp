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
    
    ll r_start  = 0;
    ll c_start  = 0;
    ll r_end    = r-1;
    ll c_end    = c-1;
    
    while (r_start <= r_end)
    {
        for (int i = c_start; i <= c_end; i++)
        {
            cout<<arr[r_start][i]<<" ";
        }
        cout<<endl;
        r_start++;
        
        for (int i = r_start; i <=r_end ; i++)
        {
            cout<<arr[i][c_end]<<" ";
        }
        cout<<endl;
        c_end--;

        for (int i = c_end; i >=c_start ; i--)
        {
            cout<<arr[r_end][i]<<" ";
        }
        cout<<endl;
        r_end--;

        for (int i = r_end; i >= r_start ; i--)
        {
            cout<<arr[i][c_start]<<" ";
        }
        cout<<endl;
        c_start++;

                
        
        
        
    }
    


    return 0;
}

/*

*/