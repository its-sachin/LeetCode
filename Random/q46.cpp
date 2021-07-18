#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0)
            return ans;

        if(nums.size()==1){
            ans.push_back({nums[0]});
            return ans;
        }

        int k = nums.back();
        nums.pop_back();
        vector<vector<int>> a = permute(nums);

        for (int l = 0; l < a.size(); l++){
        
            int i=0;
            while(i<=a[l].size()){
                vector<int> v;

                for (int j = 0; j < i; j++){
                
                    v.push_back(a[l][j]);
                }
                v.push_back(k);
                for (int j = i; j < a[l].size(); j++){
                
                    v.push_back(a[l][j]);
                }
                ans.push_back(v);
                i+=1;
                
            }
        }

        return ans;
        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3};

    Solution o;
    vector<vector<int>> a = o.permute(v);

    for (int i = 0; i < a.size(); i++){
    
        for (int j = 0; j < a[i].size(); j++){
        
            cout<<a[i][j]<<" ";    
        }
        cout<<""<<endl;

    }
    
    
    return 0;
}