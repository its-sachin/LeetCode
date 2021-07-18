#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j=0;
        for (int i = 1; i < intervals.size(); i++){
        
            if(intervals[i][0]<=ans[j][1]){
                ans[j][1] = max(ans[j][1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
                j+=1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}