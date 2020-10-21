#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		long long int m=0,ans=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='1')
			{
				m++;
			}
		}
		ans=((m*(m+1))/2);
		cout<<ans<<endl;
	}
}
