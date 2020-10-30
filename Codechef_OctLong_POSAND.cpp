#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
using namespace __gnu_pbds;
using namespace std;
#define tezi                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define fo(i, n) for (int i = 0; i < n; i++)
#define fo1(i, n) for (int i = 1; i < n; i++)
#define endl "\n"
#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a > b) ? b : a
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mod 1000000007


int fn( ll x)
{
    return x!=0 && ((x&(x-1))==0);
};

int main()
{
    tezi;
    ll y; cin>>y;
    while(y--)
    {
        ll a;
        cin>>a;
        if(a==1)
            {cout<<1<<endl; continue;}
        else if(a==3)
            {cout<<1<<" "<<3<<" "<<2<<endl;
            continue;}
        else if(a==5)
        {
            cout<<2<<" "<<3<<" "<<1<<" "<<5<<" "<<4<<endl;
            continue;
        }
        else if(fn(a))
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            cout<<2<<" "<<3<<" "<<1<<" "<<5<<" "<<4<<endl;
            ll i=6;
            while(i<=a)
            {
                if(fn(i))
                {
                    cout<<i+1<<" "<<i<<" ";
                    i+=2;
                }
                else
                {
                    cout<<i<<" ";
                    i++;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
