#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:


    vector<int> findSubstring(string s, vector<string>& words){

        int level = words[0].size();
        vector<int> ans;
        if(level==0) return ans;

        unordered_map<string,int> u;
        for (int i = 0; i < words.size(); i++){
            
            if(u.find(words[i]) != u.end()){
                u.at(words[i])++;
            }
            else
                u.insert({words[i],1});
        }

        unordered_map<string,int> uT = u;
        int start = -1;

        for (int i = 0; i <= s.size()-level; i+=level){
            
            string temp=s.substr(i,level);
            if(uT.find(temp) != uT.end()){
                uT.at(temp)--;
                if(uT.at(temp)==0)
                    uT.erase(uT.find(temp));

                if(start == -1){
                    start = i;
                }
                if(uT.empty()){
                    ans.push_back(start);
                    uT.insert({s.substr(start,level),1});
                    start+=level;
                }
            }
            else{
                uT=u;
                start=-1;
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution o;
    vector<string> a = {"ch","in","ch"};
    o.findSubstring("sainchchinch",a);
    return 0;
}