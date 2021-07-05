#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:

    vector<int> smallerNumbersThanCurrent1(vector<int>& nums) {

        //O(n^2)
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            ans.push_back(0);
            for (int j = 0; j < nums.size(); j++){
            
                if(nums[j]<nums[i]){
                    ans[i]++;
                }
            }
        }
        return ans;
    }

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        //O(n)
        
        int temp[101] ={0};
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            temp[nums[i]]++;
        }
        for (int i = 1; i < 101; i++){
        
            temp[i]+=temp[i-1];
        }
        for (int i = 0; i < nums.size(); i++){
            if(nums[i]==0){
                ans.push_back(0);
            }
            else
                ans.push_back(temp[nums[i]-1]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}