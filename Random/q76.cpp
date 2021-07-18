#include<bits/stdc++.h>
#include <algorithm>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:

    long long int get(char c, unordered_map<char,long long int> &power){
        if(power.find(c)==power.end()){
            return 0;
        }
        return power[c];
    }

    string hash(string &s, int level, long long int key, unordered_map<char,long long int> &power){

        long long int hPat=0;
        for (int i = 0; i < level; i++){
            hPat = (hPat + get(s[i],power))%mod;
        }
        int start=0;

        if(hPat==key)
            return s.substr(0,level);

        while(start<s.size()-level){

            hPat = (hPat -(get(s[start],power))%mod + mod)%mod;
            start+=1;
            hPat = (hPat + (get(s[start+level-1],power))%mod)%mod;

            if(hPat==key)
                return s.substr(start,level);

        }
        return "";
    }

    string minWindow(string s, string t) {

        unordered_map<char,long long int> power;
        for (int i = 0; i < t.size(); i++){
        
            power[t[i]] =0;    
        }

        int base = 100007;
        long long int mt=1;

        for (auto& p: power){
            p.second = mt;
            mt=base*(mt)%mod;
        }

        long long int hPat=0;
        for (int i = 0; i < t.size(); i++){
            hPat = (hPat + get(t[i],power))%mod;
        }

        int l = t.size();
        int h = s.size();

        string ans = "";
        while(l<=h){
            int mid = l+(h-l)/2;
            string temp = hash(s,mid,hPat,power);
            if(temp=="")
                l=mid+1;
            else{
                h=mid-1;
                ans = temp;
            }
        }
        return ans;
    }
        
};

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    
    string t;
    cin>>t;
    
    Solution o ;
    cout<<o.minWindow(s,t)<<endl;
    return 0;
}