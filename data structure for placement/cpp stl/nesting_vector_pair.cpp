#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
void printvect(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<vector<int>> vv;
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        vector<int> t;
        int x ;
        cin>>x;
        for (int j = 0; j < x; j++)
        {
            int temp;
            cin>>temp;
            t.push_back(temp);
        }
        vv.push_back(t);        
    }
    for (int i = 0; i < n; i++)
    {
        printvect(vv[i]);
    }
       
    return 0;
}