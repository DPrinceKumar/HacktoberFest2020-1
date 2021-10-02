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
    int sieve[10000] = {0};
    int n = 36;
    ll c = 0;
    for (int i = 2; i <= n; i++)
    {
        sieve[i] = i;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                /* code */
                if (sieve[j] == j)
                {
                    sieve[j] = i;
                    c++;
                }
            }
        }
    }
    while (n != 1)
    {
        cout << sieve[n] << " ";
        n = n / sieve[n];
    }

    // cout<<sieve[8];
    return 0;
}