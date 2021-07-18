#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:

    bool check(int k, bool* dp, vector<int>& nums){

        if(k>=nums.size()-1)
            return true;
            
        if(!dp[k] or nums[k]==0)
            return false;

        int i=1;
        while(i<=nums[k]){
            if(check(k+i,dp,nums))
                return true;
            i+=1;
        }
        dp[k]=false;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        
        bool* dp = new bool[nums.size()];
        memset(dp,true,nums.size()*sizeof(bool));

        return check(0,dp,nums);
    }
};

int main(int argc, char const *argv[])
{
    Solution o;
    vector<int> v = {0,2,3};
    cout<<o.canJump(v)<<endl;
    
    return 0;
}