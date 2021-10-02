#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
void printSet(set<string> &s)
{
    for (auto &&i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    set<string> s;
    s.insert("Dipak");
    s.insert("Hukumchand");
    s.insert("Patil");
    printSet(s);

    
    return 0;
}