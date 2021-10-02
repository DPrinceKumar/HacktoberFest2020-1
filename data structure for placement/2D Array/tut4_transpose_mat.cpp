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
    
    for (int i = 0; i < r; i++)
    {
        for (int j = i; j < c; j++)
        {
            int temp    = arr[i][j];
            arr[i][j]   = arr[j][i];
            arr[j][i]   = temp;
        }
        
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    


    return 0;
}

/*

*/