#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++){
            
            ans.push_back(ans[i-1]+nums[i]);
            
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}