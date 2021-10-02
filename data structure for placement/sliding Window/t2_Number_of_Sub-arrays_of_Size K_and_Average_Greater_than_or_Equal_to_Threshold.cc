#include <bits/stdc++.h>
using namespace std;
int max_sum_K_window(vector<int> v, int k, int threshold)
{
    int i = 0;
    int j = 0;
    int mx = INT_MIN;
    int sum = 0;
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
        sum += v[i];
    }
    mx = max(sum, mx);
    if ((sum/k) >= threshold)
    {
        c++;
    }

    for (int i = k; i < n; i++)
    {
        /* code */
        sum += v[i];
        sum -= v[i - k];

        // mx = max(sum, mx);
        if ((sum/k) >= threshold)
        {
            c++;
        }
    }

    // cout<<i<<" "<<j<<endl;
    // cout<<c<<endl;
    return c;
}
int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    vector<int> v = {11,13,17,23,29,31,7,5,2,3};
    cout << v.size() << endl;
    int k = 3;
    int threshold = 5;

    cout << max_sum_K_window(v, k, threshold);
    return 0;
}