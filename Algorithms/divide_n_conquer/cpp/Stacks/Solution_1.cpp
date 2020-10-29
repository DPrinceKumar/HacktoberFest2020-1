//Link to question no 1 =>  https://www.codechef.com/LRNDSA04/problems/STACKS
// this is solution to the first question

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	
	while(t--){
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	       cin>>arr[i]; 
	    }

	    vector<int> top;
	    vector<int> :: iterator it;
	    for(int i=0;i<n;i++){
	        it=top.end();
	            --it;
	        if( i==0 || *it<=arr[i] ){
	            top.push_back(arr[i]);
	        }
	        else{
	           auto it1=upper_bound(top.begin(),top.end(),arr[i]);
	           *it1=arr[i];
	        }
	    }
	    cout<<top.size()<<" ";
	    for(auto &v:top){
	        cout<<v<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
