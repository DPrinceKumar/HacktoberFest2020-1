#include <bits/stdc++.h>
using namespace std;
bool bin_search(int a[],int n,int k)
{
    int lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(a[mid]==k)
        return 1;
        if(a[mid]>k)
        hi=mid-1;
        else
        lo=mid+1;
    }
    return -1;
}
int main() {
	    int arr[] = { 1000, 11, 445,  
                  1, 330, 3000 }; 
    int arr_size = 6; 
    int k=330;
       if(bin_search(arr,arr_size,k))
       cout<<"Element Found";
       else
       cout<<"Element Not Found";
	return 0;
}