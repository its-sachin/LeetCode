#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    
public:

    int mod = 1000000007;

    int rollingHash(string &text, int &level,long long int* power){

        if(level==0){
            return -1;
        }
        long long int hPat=0;
        for(int i=level-1; i>=0; i--){
            hPat= (hPat%mod + (power[level-1-i]*(0+text[i]))%mod)%mod;
        }
        int start=0;

        unordered_map<long long int,int> h;
        h.insert({hPat,start});

        while(start<=text.size()-level){

            hPat = (hPat -(power[level-1]*(0+text[start]))%mod + mod)%mod;
            hPat= (hPat*26)%mod;
            start+=1;
            hPat = (hPat + (0+text[start+level-1]))%mod;
            
            if(h.find(hPat)!=h.end()){
                
                int s2 = h.at(hPat);
                if(text.substr(start,level)==text.substr(s2,level))
                    return start;     
            }
            h.insert({hPat,start});

        }
        return -1;
    }


    string longestDupSubstring(string a) {
        int low=0;
        int high = a.size();

        long long int power[a.size()];
        long long int mt=1;
        int i=0;
        while(i<a.size()){
            power[i]=mt;
            mt=(mt*26)%mod;
            i+=1;
        }

        pair<int,int> m = {-1,-1};
        while(low<=high){
            int mid = low + (high - low) / 2;
            int temp = rollingHash(a,mid,power);
            if(temp!=-1){
                if(mid>m.first){
                    m = {mid,temp};
                }
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(m.first==-1)
            return "";
        return a.substr(m.second,m.first);
        
    }
};

int main(int argc, char const *argv[])
{
    string n;
    cin>>n;

    Solution a;
    cout<<a.longestDupSubstring(n)<<endl;
    return 0;
}