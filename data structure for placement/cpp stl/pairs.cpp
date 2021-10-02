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

    // pair<int,int> p;
    // p = make_pair(5,6);
    // p = {34,96};


// coppy pair
    // pair<int,int> &p1 = p;
    // p.first = 55;
    // cout<<p1.first<<" "<<p1.second<<endl;
    

    pair<int,int> p[3];
    p[0] = make_pair(1,2);  
    p[1] = make_pair(3,4);  
    p[2] = make_pair(5,6);  

    for (int i = 0; i < 3; i++)
    {
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    
    return 0;
}