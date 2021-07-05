#include<bits/stdc++.h>

using namespace std;

#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=-1;
        int i=1;
        while(i<nums.size()){
            
            if(k==-1){
                if(nums[i-1]==nums[i]){
                    k=i;
                    i+=1;
                }
                else   
                    i+=1;
            }
            else{
                if(nums[k-1]==nums[i]){
                    while(i<nums.size() and nums[i]==nums[k-1]){
                        i+=1;
                    }
                }
                else{
                    swap(nums[k],nums[i]);
                    k+=1;
                    i+=1;
                }
            }
        }
        if(k==-1)
            return nums.size();
        return k;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}