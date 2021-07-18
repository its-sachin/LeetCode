#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    long long int hash(string &s,long long int* power){
        long long int hPat=0;
        for (int i = 0; i < s.size(); i++){
            hPat = (hPat + power[s[i]-'a'+1])%mod;
        }
        return hPat;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int base = 100007;
        long long int power[27];
        long long int mt=1;
        int i=0;
        while(i<27){
            power[i]=mt;
            mt=base*(mt)%mod;
            i+=1;
        }
        
        unordered_map<int,int> m;
        vector<vector<string>> ans;
        
        int j=0;
        for (int i = 0; i < strs.size(); i++){

            long long h = hash(strs[i],power);
            if(m.find(h) == m.end()){
                m.insert({h,j});
                ans.push_back({strs[i]});
                j+=1;
            }
            else{
                ans[m[h]].push_back(strs[i]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> aa = {"eat","tea","tan","ate","nat","bat"};
    Solution o;
    vector<vector<string>> a = o.groupAnagrams(aa);

    for (int i = 0; i < a.size(); i++){
    
        for (int j = 0; j < a[i].size(); j++){
        
            cout<<a[i][j]<<" ";    
        }
        cout<<""<<endl;
    }


    return 0;
}