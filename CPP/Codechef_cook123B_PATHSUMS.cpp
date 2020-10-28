/*

PROBLEM LINK : https://www.codechef.com/COOK123B/problems/PATHSUMS
SOLUTION LINK : https://www.codechef.com/viewsolution/39021258
THIS SOLUTION IS SUBMITTED BY markMahesh (Mahesh Vaishnav)


*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j;
	    cin>>n;
	    bool arr[n+1][n+1]={0};
	    int u,v;
	    for(i=0;i<n-1;i++)
	    {
	        cin>>u>>v;
	        arr[u][v]=1;
	        arr[v][u]=1;
	        
	    }
	   // for(i=1;i<=n;i++)
	   // {
	   //     for(j=1;j<=n;j++)
	   //     {
	   //         cout<<arr[i][j]<<" ";
	   //     }
	   //     cout<<"\n";
	   // }
	    int sol[n+1]={-1},temp=2,vt;
	    sol[1]=1;
	    bool visited[n+1]={0};
	    visited[1]=1;
	    stack <int> s; 
	    s.push(1);
	    temp=1;
	    sol[v]=1;
	    while(!s.empty())
	    {
	        vt=s.top();
	        //sol[v]=temp;
	        s.pop();
	        for(j=1;j<=n;j++)
	        {
	            if(visited[j]==0 && arr[vt][j]==1)
	            {
	                s.push(j);
	                if(sol[vt]==1)
	                {
	                    sol[j]=2;
	                }
	                else
	                {
	                    sol[j]=1;
	                }
	                visited[j]=1;
	            }
	        }
	    }
	    
	    
	   
	    for(i=1;i<=n;i++)
	    {
	        cout<<sol[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
