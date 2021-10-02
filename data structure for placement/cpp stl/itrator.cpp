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



// for Vector 

    // vector<int> v = {1,2,3,4,5};
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
   
   
    // // vector<int> :: iterator it = v.begin();
    // while (it != v.end())
    // {
    //     cout<<(*it)<<" " ;   
    //     it++;
    // }


// for vector of pair

    vector<pair<int,int>> vp = {{1,3},{3,5},{4,5}};

    // for (int i = 0; i < vp.size(); i++)
    // {
    //     cout<<vp[i].first<<" "<<vp[i].second<<endl;
    // }
    
    // Using itrators

    vector<pair<int,int>> :: iterator it ; 

    for ( it = vp.begin(); it != vp.end(); it++)
    {
        // cout<<(*it).first<<" "<<(*it).first<<endl;
                        // or
        cout<<it->first<<" "<<it->second<<endl;
    }
    
    return 0;
}