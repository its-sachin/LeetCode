#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {

public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        int n = nums.size();

        int i=0;
        int ans = -1;
        while(i<n-2){
            // cout<<i<<endl;
            int left = i+1;
            int right = n-1;

            while(left<right){
                // cout<<left<<" "<<right<<endl;
                int sum = nums[left]+nums[right]+nums[i];
                if(sum==target){
                    return target;
                }
                else if(sum >target){
                    if(ans==-1 or abs(target-ans)>abs(target-sum)){
                        ans=sum;
                    }
                    int temp = nums[right];
                    while(right>=0 && nums[right]==temp){
                        right-=1;
                    }
                }
                else{
                    if(ans==-1 or abs(target-ans)>abs(target-sum)){
                        ans=sum;
                    }
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
    vector<int> m =  {0,1,0};
    cout<<a.threeSumClosest(m,1)<<endl;
    return 0;
}