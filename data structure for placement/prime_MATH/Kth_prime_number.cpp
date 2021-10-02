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
vector<int> v;
bool arr[90000001];
void siev()
{
    int mx = 90000001;
    arr[0]  = arr[1] = true;

    for (int i = 2; i*i <= mx; i++)
    {
      if (arr[i] == false)
      {
         for (int j = i*i; j <= mx; j+=i)
          {
              arr[j] = true;
          }
          
      }
        
    }
    for (int i = 2; i <= mx; i++)
    {
        if (!arr[i])
        {
            v.push_back(i);
        }
        // cout<<arr[i]<<" ";
    }
    
}
int main()
{
      
    siev();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<v[n-1]<<endl; 
    }
    return 0;
}