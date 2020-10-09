/*
Problem link :- https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/signal-range/
*/

#include <bits/stdc++.h>

using namespace std;

int search(int key,int a[],int i)
{
    for(int j=i-1;j>=0;j--)
    {
        if(a[j]==key)
        return j;
    }
}

void previous_greater_equal(int a[],int n)
{
    stack <int> s;
    int ans[n],i;
    
    ans[0]=1;
    s.push(a[0]);
    for(i=1;i<n;i++)
    {
        while(s.empty()==false && s.top()<=a[i])
        s.pop();
        
        if(s.empty())
        ans[i]=i+1;
        else
        ans[i]=i-search(s.top(),a,i);
        
        s.push(a[i]);
        
        
    }
    for(i=0;i<n;i++)
    {
        
    cout<<ans[i]<<" ";

    
    }
}

int main() {
	int n,i,j,k,t;
	cin >> t;	
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	previous_greater_equal(a,n);
	    
	    cout<<endl;
	}
	
	
	return 0;
}