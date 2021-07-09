#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> h;
        for(int i=0;i<n;i++){

            if(h.find(target-nums[i]) != h.end()){
                return {i,h[target-nums[i]]};
            }
            h.insert({nums[i],i});

        }
        return {};
    }
};


int main(int argc, char const *argv[])
{


    
    Solution a;
    vector<int> m =  {3,2,4};
    vector<int> ans = a.twoSum(m,6);

    for (int x: ans){
        cout<<x<<endl;
    }
    return 0;
}