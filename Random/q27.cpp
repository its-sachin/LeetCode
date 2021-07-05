#include<bits/stdc++.h>

using namespace std;

#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=nums.size()-1;
        int i=0;
        while(i<j){
            if(nums[i]==val){
                nums[i]=nums[j];
                j-=1;
            }
            else{
                i+=1;
            }
        }
        if(nums[j]==val)
            return j;
        return j+1;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}