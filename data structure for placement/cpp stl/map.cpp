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
void printMap(map<int, int> &m)
{
    cout << "size : " << m.size() << endl;

    for (auto &&i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
}
int main()
{
    // map<int, string> m;
    // m[1] = "dipak";
    // m[3] = "patil";
    // m[2] = "hukumchand";
    // printMap(m);

    map<int, int> m;
    m[1] = 1;
    m[3] = 3;
    m[4] = 3;
    printMap(m);

// finding in map;
    // auto it = m.find(4);
    // if (it != m.end())
    // {
    //     cout << "Found : " << (*it).first << " " << (*it).second << endl;
    // }
    // else
    // {
    //     cout << "Not found !" << endl;
    // }

    m.erase(3);
    cout<<"After"<<endl;
    printMap(m);
    return 0;
}