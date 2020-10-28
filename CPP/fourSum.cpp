/*  Given an array nums of n integers and an integer target,
    find all unique quadruplets in the array which gives the sum of target.
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>result;
        if(n < 4)
            return {};
        int i = 0;
        sort(nums.begin(),nums.end());
        while( i < n-3){
            int targetSum = target - nums[i];
            int j = i+1;
            while( j < n-2){              
                int k = j+1, l = n-1;
                while(k < l){
                    int sum = nums[j] + nums[k] + nums[l];
                    if(sum == targetSum){
                        result.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                    }
                    else if(sum > targetSum){
                        l--;
                    }
                    else
                        k++;
                }
                j++;
            }
            i++;
        }
        return vector<vector<int>>(result.begin(),result.end());
}
int main(){
    vector <int> nums;
    vector <vector<int>> result;
    int n,target;
    cin>>n;
    for(int i = 0; i<n; i++){
        int in;
        cin>>in;
        nums.push_back(in);
    }
    cin>>target;
    result = fourSum(nums,target);
    for(int i = 0; i<result.size();i++){
        cout<<"[ ";
        for(int j = 0; j< result[0].size(); j++){
            cout<<result[i][j]<<"  ";
        }
        cout<<"]\n";
    }
}
