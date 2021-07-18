#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;
        ans.push_back({1});
    
        for (int i = 1; i < numRows; i++){
            vector<int> v;
            v.push_back(1);
            for (int j = 1; j <ans[i-1].size(); j++){
                
                v.push_back(ans[i-1][j-1]+ans[i-1][j]);
                
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    Solution o;
    vector<vector<int>> v = o.generate(n);

    for (int i = 0; i < v.size(); i++){
    
        for (int j = 0; j < v[i].size(); j++){
        
            cout<<v[i][j]<<" ";
        }
        cout<<""<<endl;
    }
    return 0;
}