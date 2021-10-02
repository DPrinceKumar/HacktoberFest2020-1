#include<bits/stdc++.h>
using namespace std;
    
int main()
{
    int arr[] = {1,-1,-2,4,5,6,-8,9,-10,2,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int c = 0;
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i <  n; i++)
    {
        if (!dq.empty() &&  dq.front() == i-k-1)
        {
            dq.pop_front();
        }
        while (i < k)
        {
            if (arr[i] < 0)
            {
                dq.push_back(i);
            }
            // cout<<arr[i]<<" ";   
            i++;
        }

        if (!dq.empty())
        {
         ans.push_back( arr[dq.front()]);;
        }
        else{
         ans.push_back( 0);
            // cout<<0<<" ";
        }
        if (arr[i]< 0)
        {
            dq.push_back(i);
        }
        
        
        
    }
    
    return 0;
}