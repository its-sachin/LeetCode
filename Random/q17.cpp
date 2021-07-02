#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>> phone = {{50,{'a','b','c'}},{51,{'d','e','f'}},{52,{'g','h','i'}},{53,{'j','k','l'}},{54,{'m','n','o'}},{55,{'p','q','r','s'}},{56,{'t','u','v'}},{57,{'w','x','y','z'}}};
        vector<string> ans;
        if(digits=="")
            return ans;
        for(int k=0;k<phone.at(int(digits[0])).size();k++){
            ans.push_back(string(1,phone.at(int(digits[0]))[k]));
        }
        for(int i=1; i<digits.size(); i++){
            int s = ans.size();
            for(int j=0;j<s;j++){
                for(int k=1;k<phone.at(int(digits[i])).size();k++){
                    ans.push_back(ans[j]+phone.at(int(digits[i]))[k]);
                }
                ans[j].push_back(phone.at(int(digits[i]))[0]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string str;
    cin>>str;
    
    Solution s;
    vector<string> a = s.letterCombinations(str);

    for(string ans:a){
        cout<<ans<<" ";
    }
    cout<<""<<endl;
    return 0;
}