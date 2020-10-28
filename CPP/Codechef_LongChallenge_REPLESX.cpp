/*

  Problem Link : https://www.codechef.com/OCT20B/problems/REPLESX
  Solution Link : https://www.codechef.com/viewsolution/38771708
  This solution was submitted by me(mark_mahesh).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long int n,x,p,k;
	    cin>>n>>x>>p>>k;
	    long int a[n],i,found=0;
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]==x)
	            found++;
	    }
	    sort(a,a+n);
	    if(a[p-1]==x)
	    {
	        cout<<"0\n";
	    }
	    else
	    {
	        if(found==0)
	        {
	            long int xpos,ff=0;
	            for(i=0;i<n;i++)
	            {
	                if(a[i]>x)
	                {
	                    xpos=i+1;
	                    ff=1;
	                    break;
	                }
	            }
	            if(ff==0)
	            {
	                xpos=n+1;
	            }
	            if(p==k )
	            {
	                if(k<xpos)
	                    cout<<abs(p-xpos)<<"\n";
	               else 
	                    cout<<abs(p-xpos) + 1<<"\n";
	            }
	            else if(k<xpos)
	            {
	                xpos=xpos-1;
	                if(p>=k && p<=xpos)
	                {
	                    cout<<xpos-p + 1<<"\n";
	                }
	                else
	                {
	                    cout<<"-1\n";
	                }
	            }
	            else
	            {
	                if(p>=xpos && p<=k)
	                {
	                    cout<<p-xpos + 1<<"\n";
	                }
	                else
	                    cout<<"-1\n";
	            }
	        }
	        else
	        {
	            if(a[k-1]==x)
	                cout<<"-1\n";
	            else
	            {
	                long int xl,xr;
	                for(i=0;i<n;i++)
	                {
	                    if(a[i]==x)
	                    {
	                        xl=i+1;
	                        break;
	                    }
	                }
	                xr=xl+found-1;
	                if(k<xl)
	                {
	                    if(p>=k && p<xl)
	                    {
	                        cout<<xl-p<<"\n";
	                    }
	                    else
	                    {
	                        cout<<"-1\n";
	                    }
	                }
	                else
	                {
	                    if(p<=k && p>xr)
	                    {
	                        cout<<p-xr<<"\n";
	                    }
	                    else
	                    {
	                        cout<<"-1\n";
	                    }
	                }
	            }
	        }
	    }
	}
	return 0;
}
