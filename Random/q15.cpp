#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        // for(int x:nums){
        //     cout<<x<<" ";
        // }
        // cout<<""<<endl;
        vector<vector<int>> ans;
        int n = nums.size();

        int i=0;
        while(i<n-2){
            // cout<<i<<endl;
            int left = i+1;
            int right = n-1;

            while(left<right){
                // cout<<left<<" "<<right<<endl;
                int sum = nums[left]+nums[right]+nums[i];
                if(sum==0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    int temp = nums[left];
                    while(left<n && nums[left]==temp){
                        left+=1;
                    }
                    temp = nums[right];
                    while(right>=0 && nums[right]==temp){
                        right-=1;
                    }

                }
                else if(sum >0){
                    int temp = nums[right];
                    while(right>=0 && nums[right]==temp){
                        right-=1;
                    }
                }
                else{
                    int temp = nums[left];
                    while(left<n && nums[left]==temp){
                        left+=1;
                    }
                }
            }

            int temp = nums[i];
            while(i<n-2 && nums[i]==temp){
                i+=1;
            }
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> m =  {0,0,0};
    vector<vector<int>> ans = a.threeSum(m);

    for (auto& x: ans){
        for(int i: x){
            cout<<i<<" ";
        }
        cout<<""<<endl;
    }
    return 0;
}