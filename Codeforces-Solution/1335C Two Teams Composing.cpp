#include<bits/stdc++.h>
using namespace std;
void solve(){
int n;
cin>>n;
map<int,int> m;
int val;
for(int i=0;i<n;i++){
	cin>>val;
	m[val]++;
}
int ans=-1;
for(auto x:m){
	ans=max(ans,x.second);
}
int b=min(ans-1,(int)m.size());
int c=min((int)m.size()-1,ans);
cout<<max(b,c)<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}