#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi (3.141592653589)
#define dd double
#define ff first
#define Y "YES"
#define N "NO"
long int gcd(long a, long b){return (b == 0) ? a : gcd(b,a%b);}
int first_occurance(int a[], int n,int key,int i){
    if (i == n)
    {
        return -1;
    }
    
    // cout<<i<<endl;
    if (a[i] == key )
    {
        return i;
    }
    return first_occurance(a,n,key,i+1);

    
}
int last_occurance(int a[], int n,int key,int i){
    if (i == n)
    {
        return -1;
    }
    int res_arr = last_occurance(a,n,key,i+1);
    if (res_arr!= -1)
    {
        return res_arr; 
    }
    if (a[i] == key )
    {
        return i;
    }
    
    // cout<<i<<endl;
    return -1;

     
}
int main()
{
    int t;
    cin>>t;
    
    int a[t];
    for (int i = 0; i < t; i++)
    {
        cin>>a[i];
    }
    int n;
    cin>>n;
    int k = last_occurance(a,t,n,0);
    cout<<k<<endl;
    return 0;
}