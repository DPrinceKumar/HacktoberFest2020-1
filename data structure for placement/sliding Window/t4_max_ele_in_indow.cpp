#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq;
    int arr[] = {1, 2, -1, 5, -2, 1, 8, 3, 41};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int i = 0;
    int j = 0;

    int mx = INT_MIN;
    int f_ele_index = -1;
    for (int i = 0; i < k; i++)
    {
        if (arr[i])
        {
            /* code */

        }
        
        
    }
    dq.push_back(f_ele_index);

    for (int i = 1; i < n; i++)
    {
        cout<<arr[dq.front()]<<" ";
        if (!dq.empty() && dq.front() == j-k-1)
        {
            dq.pop_front();
        }
        if (arr[i]>)
        {
            /* code */
        }
        

        
    }
    
    













    // while (j < n)
    // {

 
        

    //     if (j < k)
    //     {
    //         /* code */
    //         if (arr[j] < 0)
    //         {
    //             dq.push_back(j);
    //         }
            
    //         cout<<arr[j]<<" . ";
    //         j++;
    //        continue;
    //     }
    //     if (!dq.empty())
    //     {
    //         cout<<arr[dq.front()]<<" ";
    //     }
    //     else{
    //         cout<<0<<" ";
    //     }
         
    
    //     while (!dq.empty() && dq.front() < ((j+1) - k ))
    //     {
    //         dq.pop_front();
    //     }
    //     if (arr[i]<0)
    //     {
    //         dq.push_back(i);
    //     }
        
        
    //     j++;
        
    // }
    // cout<<dq.front();
    // for (j = 0; j < n; j++)
    // {
    //    if (!dq.empty() && dq.front() == j-k)
    //    {
    //        /* code */
    //        dq.pop_front();
    //    }

    // //    cout<<arr[j]<<" ";

    //     while (!dq.empty() && arr[dq.back()] < arr[j])
    //     {
    //         /* code */
    //         dq.pop_back();
    //     }
    //     dq.push_back(j);

    //     if (j>=k-1)
    //     {
    //         cout<<arr[dq.front()]<<" ";
    //     }

    // }
    // cout<<endl;

    return 0;
}