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
const int mx = 10000000 + 7;
int arr[mx];
void siev()
{
    for (int i = 0; i < mx; i++)
    {
        arr[i] = i;
    }
    
    for (int i = 2; i * i < mx; i++)
    {
        if (arr[i] == i)
        {
            for (int j = i * i; j < mx; j += i)
            {
                arr[j] = i;
            }
        }
    }
       
}
int main()
{   
    siev();
    int n;
    cin>>n;
    while (n!=1)
    {
        cout<<arr[n]<<"  ";
        n/=arr[n];
    }
    
    
    return 0;
}