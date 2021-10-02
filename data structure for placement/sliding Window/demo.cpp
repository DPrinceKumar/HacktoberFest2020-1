#include<bits/stdc++.h>
using namespace std;
    
int main()
{
    vector<int> arr = {1,2,0,1,0,0,0,1,1,1,2,2,2,0,1,0};
    int l = 0;
    int mid = 0;
    int r = arr.size()-1;

    while (r > mid)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid],arr[l]);
            l++;
        }
        if (arr[mid] == 2)
        {
           swap(arr[mid],arr[r]);
           r--;
           continue; 
        }
        mid++;
        
    }
    

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}