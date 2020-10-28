/*
  Link of the Problem : https://codeforces.com/contest/1401/problem/C
  Solution is written and submitted by maheshvaishnav2301(me) .

*/


#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    long int a[n],b[n],i;
	    vector<long int> v2;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        b[i]=a[i];
	    }
	    sort(b,b+n);
	    long int min=b[0];
	    
	    for(i=0;i<n;i++){
	        if(a[i]!=b[i])
	          v2.push_back(a[i]);
	    }
	    int flag=1;
	    for(i=0;i<v2.size();i++){
	        if(v2[i]%min!=0){
	            flag=0;
	            break;
	        }
	    }
	    if(v2.size()==0){
	        flag=1;
	    }
	    if(flag==1){
	        cout<<"YES"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
