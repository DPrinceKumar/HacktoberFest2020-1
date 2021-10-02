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

int main()
{
    ll r, c,ele;
    cin >> r >> c;

    ll arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin>>ele;
    int n = 0;
    int m = c-1;
    bool f = false;

    while (n<c && m>=0)
    {
        if (arr[n][m] == ele)
        {
            f = true;
            break;
        }
        if (arr[n][m] > ele)
        {
            m--;    
        }
        else{
        n++;
        }
        
        
    }
    if (f)
    {
        cout<<Y<<endl;
    }
    else
    {
        cout<<N<<endl;
    }
    

    return 0;
}