#include<bits/stdc++.h>

using namespace std;

#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        int i=0;
        while(i<haystack.size()){
            if(haystack[i]==needle[0] and i+needle.size()<=haystack.size()){
                int j=1;
                int k=-1;
                while(j<needle.size() and haystack[i+j]==needle[j]){
                    if(k==-1 and haystack[i+j]==haystack[i])
                        k=j;
                    j+=1;
                }
                if(j==needle.size())
                    return i;
                i+=max(1,k);
            }
            else{
                i+=1;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    string c;
    cin>>c;

    Solution o;
    cout<<o.strStr(s,c)<<endl;
    return 0;
}