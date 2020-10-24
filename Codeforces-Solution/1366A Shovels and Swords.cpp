//Author Tejas K Mukherjee
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define FOR(a,b) for(int i=a;i<b;i++)
#define FORE(a,b) for(int i=a;i<=b;i++)
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<min((a+b)/3,min(a,b))<<'\n';
    }
}