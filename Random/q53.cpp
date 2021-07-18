#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans = INT32_MIN;

        for (int i = 0; i < nums.size(); i++){
        
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}