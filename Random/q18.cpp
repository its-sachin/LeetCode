#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        // for(int x:nums){
        //     cout<<x<<" ";
        // }
        // cout<<""<<endl;
        vector<vector<int>> ans;
        int n = nums.size();

        int j=0;
        
        while(j<n-3){
            cout<<"j "<<j<<endl;
            int i=j+1;
            while(i<n-2){
                cout<<"i "<<i<<endl;
                int left = i+1;
                int right = n-1;


                while(left<right){
                    
                    int sum = nums[j]+nums[left]+nums[right]+nums[i];
                    cout<<left<<" "<<right<<" "<<sum<<endl;
                    if(sum==target){
                        ans.push_back({nums[j],nums[i],nums[left],nums[right]});
                        int temp = nums[left];
                        while(left<n && nums[left]==temp){
                            left+=1;
                        }
                        temp = nums[right];
                        while(right>=0 && nums[right]==temp){
                            right-=1;
                        }

                    }
                    else if(sum >target){
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
            int temp = nums[j];
            while(j<n-3 && nums[j]==temp){
                j+=1;
            }
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> m =  {1,0,-1,0,-2,2};
    vector<vector<int>> ans = a.fourSum(m,0);

    for (auto& x: ans){
        for(int i: x){
            cout<<i<<" ";
        }
        cout<<""<<endl;
    }
    return 0;
}