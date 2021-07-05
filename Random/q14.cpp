#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i=0;
        while(true){
            char add = 'a';
            for(int j=0;j<strs.size(); j++){
                if(i>=strs[j].size())
                    return ans;
                if(j==0)
                    add = strs[j][i];
                else{
                    if(strs[j][i]!=add)
                        return ans;
                }
            }
            ans.push_back(add);
            i+=1;
        }
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}