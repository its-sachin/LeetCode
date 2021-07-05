#include<bits/stdc++.h>

using namespace std;

typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++){
        
            if(m.find(nums[i])!=m.end()){
                m.at(nums[i])++;
            }
            else{
                m.insert({nums[i],1});
            }
        }
        int ans=0;
        for (pair<int,int>  i:m){
        
            ans+=(i.second*(i.second-1))/2;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}