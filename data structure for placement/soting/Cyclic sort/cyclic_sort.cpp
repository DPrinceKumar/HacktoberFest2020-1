#include<bits/stdc++.h>
using namespace std;
void cyclicSort(vector<int> &nums){
         int i = 0;
    while (i<nums.size())
    {
        int crr = nums[i]-1;
        if ((nums[i] > 0 && nums[i] <= nums.size() ) &&(nums[crr])!= i )
        {
            swap(nums[i],nums[crr]);
        }
        else{
            i++;
        }       
    }
     for (int i = 0; i < nums.size(); i++)  
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> v = {2147483647,2147483646,2147483645,3,2,1,-1,0,-2147483648};
    cyclicSort(v);
    for (int i = 0; i < v.size(); i++)  
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int> ans;
      for(int i = 0; i<v.size(); ++i){
            if(i != v[i]-1){
                cout<< i+1;
            }
      }
        
    return 0;
}