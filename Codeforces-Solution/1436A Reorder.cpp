// problem link: https://codeforces.com/contest/1436/problem/A
// solution is created and submitted by Amit Kumar
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
int main() {
    IO;
	li t;
	cin>>t;
	W(t--){
	    li n,m;
	    cin>>n>>m;
	    li a[n],sum=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	        
	    }
	        if(sum==m){
	            cout<<"YES"<<endl;
	        }
	        else{
	            cout<<"NO"<<endl;
	        }
	}
	return 0;
}
