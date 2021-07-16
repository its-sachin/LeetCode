#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int j=nums.size()-1;

        while(j>=0){
            if(nums[j]>0 and nums[j]<n){
                if(nums[nums[j]-1]==nums[j])
                    j-=1;
                else{
                    swap(nums[j],nums[nums[j]-1]);
                }
            }
            else{
                j-=1;
            }
        }

        for (int i = 0; i < n; i++){
        
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4};
    Solution o;
    cout<<o.firstMissingPositive(v)<<endl;
    
    return 0;
}