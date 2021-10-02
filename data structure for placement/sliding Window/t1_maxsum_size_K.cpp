#include <bits/stdc++.h>
using namespace std;
int max_sum_K_window(vector<int> v, int k)
{
    int i = 0;
    int j = 0;
    double mx = -9999999999999999;
    double sum = 0;
    int c = 0;
    int n = v.size();
    
    // while(j<n){
    //     if (j-i != (k))
    //     {
    //         sum+=v[j];
    //         j++;
    //         mx = max(mx,sum);
    //         cout<<"MX " << mx<<endl;
    //     }
    //     else{
    //         sum-=v[i];
    //         i++;
    //         // cout<<v[i]<<" "<<v[j]<<" "<<endl;

    //         sum+=v[j];
    //         j++;
    //         mx = max(mx,sum);
    //         cout<<"MX " << mx<<endl;
    //     }
    //     c++;
        
    // }



    for (int i = 0; i < k; i++)
    {
        sum+=v[i];
    }
    mx = max(sum,mx);

    for (int i = k; i < n; i++)
    {
        /* code */
        sum+=v[i];
        sum-=v[i-k];

    mx = max(sum,mx);
        
    }
    
    
    // cout<<i<<" "<<j<<endl;
    // cout<<c<<endl;
    return mx;
}
int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    vector<int> v = {1,2,3,5,5,5,1,2,5,3,3,5,4};
    cout<<v.size()<<endl;
    int k = 3;

    cout<<fixed<<setprecision(5) << max_sum_K_window(v, k);
    return 0;
}