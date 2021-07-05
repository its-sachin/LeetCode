#include<bits/stdc++.h>

using namespace std;

#define inf 1e18
#define mod 100000000007
#define pb push_back

class Solution {
    
public:

    int base = 100007;

    string rollingHash( vector<string>& paths, int &level,long long int* power){

        string ans = "";

        if(level==0){
            return ans;
        }

        unordered_map<long long int,int> com;

        for(int e=0; e<paths.size(); e++){

            unordered_map<long long int,int> h;

            if(level==1){
                for(int i=0; i<paths[e].size();i++){
                    int hPat = paths[e][i];
                    if(e==0 or com.find(hPat)!=com.end()){
                        if(e==paths.size()-1)
                            return paths[e].substr(i,level);
                        h.insert({hPat,i});
                    }
                }
            }

            else{
                long long int hPat=0;
                for(int i=level-1; i>=0; i--){
                    hPat= (hPat%mod + (power[level-1-i]*(paths[e][i]))%mod)%mod;
                }
                int start=0;

                if(e==0 or com.find(hPat)!=com.end()){
                    if(e==paths.size()-1){
                        return paths[e].substr(start,level);
                    }
                    h.insert({hPat,start});
                }

                while(start<paths[e].size()-level){

                    hPat = (hPat -(power[level-1]*(paths[e][start]))%mod + mod)%mod;
                    hPat= (hPat*base)%mod;
                    start+=1;
                    hPat = (hPat + (paths[e][start+level-1]+1))%mod;

                    if(e==0 or com.find(hPat)!=com.end()){
                        if(e==paths.size()-1){
                            return paths[e].substr(start,level);
                        }
                        h.insert({hPat,start});   
                    }

                }
            }
            com=h;
            if(com.size()==0){
                return "";
            }
            
        }
        return "";
    }


    string longestCommonPrefix( vector<string>& paths) {

        if(paths.size()==0)
            return "";
        
        int minP = INT32_MAX;
        for(int i=0; i<paths.size();i++){
            minP = min(minP,(int)paths[i].size());
        }
        int low=0;
        int high = minP;
        
        if(minP==0)
            return "";

        long long int power[minP];
        long long int mt=1;
        int i=0;
        while(i<minP){
            power[i]=mt;
            mt=base*(mt)%mod;
            i+=1;
        }
        string ma = "";
        while(low<high){
            int mid = (low+high+1)/2;
            string temp = rollingHash(paths,mid,power);
            if(temp.size()!=0){
                ma = temp;
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ma;
        
    }
};

int main(int argc, char const *argv[])
{
    // vector<string> v = {"flower","flow","flight"};
    vector<string> v = {""};
    Solution o;
    cout<<o.longestCommonPrefix(v)<<endl;
    return 0;
}