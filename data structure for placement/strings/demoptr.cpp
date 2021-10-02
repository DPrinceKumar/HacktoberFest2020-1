#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
void inc(int *a,int *b)
{
    *a = 22;
    *b = 222;

}    
int main()
{
    int a = 10;
    int b = 20;
    int *ptra = &a;
    int *ptrb = &b;
    inc(&a,ptrb);
    cout<<a<<" "<<b<<endl;
    return 0;
}