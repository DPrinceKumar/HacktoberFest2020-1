#include <iostream> 

using namespace std; 

  

bool solve(int par,int a[],int n,int mid) 

{ 

    int paratha =0; 

    int time=0; 

    for(int i=0;i<n;i++) 

    { 

        time=a[i]; 

        int j=2; 

        while(time<=mid) 

        { 

            paratha++; 

            time=time+a[i]*j; 

            j++; 

        } 

        if(paratha>=par) 

        return 1; 

    } 

    return 0; 

} 

void binarySearch(int par,int a[],int n,int low,int high) 

{ 

    int ans=0; 

    while(low<=high) 

    { 

        int mid =(high+low)/2; 

        if(solve(par,a,n,mid)) 

        { 

            ans=mid; 

            high=mid-1; 

        } 

        else low=mid+1; 

    } 

    cout<<ans<<"\n"; 

} 

int main() { 

// your code goes here 

int t;cin>>t; 

while(t--) 

{ 

    int x;cin>>x; 

    int p;cin>>p; 

    int a[p]; 

    for(int i=0;i<p;i++) 

    cin>>a[i]; 

    binarySearch(x,a,p,0,1e8); 

} 

return 0; 

} 
