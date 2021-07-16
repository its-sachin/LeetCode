#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:

    int bsr(vector<int>& nums, int target, int l, int r, bool isr){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                if(isr){
                    if(mid==nums.size()-1 or nums[mid+1]!=target)
                        return mid;

                    l=mid+1;
                }
                else{
                    if(mid==0 or nums[mid-1]!=target)
                        return mid;

                    r=mid-1;
                }
            }
            else if (nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size()-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                cout<<low<<" "<<mid<<endl;
                int on = mid;
                int tw = mid;
                if(mid!=0 and nums[mid-1]==target){
                    on=bsr(nums,target,low,mid-1,false);
                }
                if(mid!=nums.size()-1 and nums[mid+1]==target){
                    tw = bsr(nums,target,mid+1,high,true);
                }

                return {on,tw};
            }
            else if (nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {5,7,7,8,8,10};
    int a =8;

    Solution p;
    vector<int> s = p.searchRange(v,a);

    cout<<s[0]<<" "<<s[1]<<endl;
    
    return 0;
}