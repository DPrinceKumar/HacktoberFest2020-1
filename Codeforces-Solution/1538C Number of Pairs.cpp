#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long  t,n,l,r;
	cin>>t;
	while(t--)
	{
	    cin>>n>>l>>r;
	    long long s=0;
	    vector<int> v(n,0);
	    for(int i=0;i<n;i++)
	          cin>>v[i];
	    sort(v.begin(),v.end());
	    for(int i=0;i<n-1;i++)
	      {
	          long long j = lower_bound(v.begin()+i+1,v.end(), l - v[i]) - v.begin();
	          if(j==n)
	            continue;
	          long long k = upper_bound(v.begin()+i+1,v.end(), r - v[i]) - v.begin();
	          if(k==n)
	            k=n-1;
	           else
	            --k;
	          s+=(k - j + 1);
	      }
	    cout<<s<<"\n";
	}
	return 0;
}
