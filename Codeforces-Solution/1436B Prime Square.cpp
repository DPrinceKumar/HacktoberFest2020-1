// problem link: https://codeforces.com/contest/1436/problem/B
// code is submitted by me during contest
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define li long int
#define ld long double
#define W while
#define endl "\n"
#define For(i,s,x) for(i=s;i<x;i++)
#define FOR(i,x) for(i=0;i<x;i++)
#define FoR(i,x) for(i=1;i<=x;i++)
#define fr(i,x) for(i=x;i>=0;i--)
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pb push_back
#define pp pop_back
#define mp make_pair
#define F first
#define S second
#define mod 1000000007

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(v) v.begin(),v.end()
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
 
const int N = 1e5+5;
const int M = 1e5+5;
const int inf = INT_MAX;
const int MOD = 1e7+9;

bool isPrime(int n) 
{ 
    
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 

    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  

    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 

    return true; 
} 
  
int findSmallest(int N) 
{ 
    if (N == 0) 
        return 2; 
    if (N == 1) 
        return 1; 
  
    int prime = N, counter = 0; 
    bool found = false; 
    while (!found) { 
        if (isPrime(prime)) 
            found = true; 
        else { 
            prime++; 
            counter++; 
        } 
    } 
  
    return counter; 
} 
int main() {
    IO;
	li t;
	cin>>t;
	W(t--){
	    li n;
	    cin>>n;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(i==j)
	            cout<<"1 ";
	            else if(i==j-1)
	            cout<<"1 ";
	            else if(j==i-1)
	            cout<<"1 ";
	            else
	            cout<<"0 ";
	        }
	        cout<<endl;
	    }
	     
	}
	return 0;
}
