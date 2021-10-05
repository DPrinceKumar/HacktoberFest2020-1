#include <bits/stdc++.h> 

using namespace std; 

  

bool solve(int a[],int n,int mid,int cow) 

{ 

    int x=1; 

    int prev=a[0]; 

    for(int i=1;i<n;i++) 

    { 

      if(a[i]-prev>=mid){ 

      x++; 

      prev=a[i]; 

      } 

    } 

    if(x<cow) 

    return 0; 

    else return 1; 

} 

void binarySearch(int a[],int n,int low,int high,int cow) 

{ 

    int ans; 

    while(low<=high) 

    { 

        int mid=(low+high)/2; 

        if(solve(a,n,mid,cow)) 

        { 

            ans=mid; 

            low=mid+1; 

        } 

        else high=mid-1; 

    } 

    cout<<ans<<"\n"; 

} 

int main() { 

// your code goes here 

int t;cin>>t; 

while(t--) 

{ 

    int n,c;cin>>n>>c; 

    int a[n]; 

    for(int i=0;i<n;i++) 

    { 

        cin>>a[i]; 

    } 

    sort(a,a+n); 

    binarySearch(a,n,0,1e9,c); 

} 

return 0; 

} 
