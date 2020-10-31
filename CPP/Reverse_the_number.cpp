// problem link https://www.codechef.com/LRNDSA01/problems/FLOW007/
// solution link https://www.codechef.com/viewsolution/31855573

#include<bits/stdc++.h>
#define ll long int
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
	    ll n,rem=0,rev=0;
	    cin>>n;
	    while(n){
	        rem=n%10;
	        rev =rev*10+rem;
	        n=n/10;
	    }
	    cout<<rev<<endl;
    }
	return 0;
}
