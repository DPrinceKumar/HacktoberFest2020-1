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

int main()
{
    int siev[100000];
    for (int i = 0; i < 100000; i++)
    {
        siev[i] = 1;
    }

    siev[1] = 0;
    for (int i = 2; i*i < 100000; i++)
    {
        if (siev[i] == 1)
        {

            for (int j = i * i; j <= 100000; j += i)
            {
                siev[j] = 0;
            }
        }
    }
    // for (int i = 0; i < 100; i++)
    // {
    // }

     cout << siev[10007] << " ";
    return 0;
}