#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
void printvect(vector<pair<int,int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    
}
int main()
{
    vector<pair<int,int>> vp;
    for (int i = 0; i < 3; i++)
    {
        int a,b;
        cin>>a>>b;
        // vp[i].first = a;
        // vp[i].second = b;
        vp.push_back({a,b});
    }
    printvect(vp);
    
    return 0;
}