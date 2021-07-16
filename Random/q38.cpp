#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";

        string a = countAndSay(n-1);
        string ans;

        int i=0;

        while(i<a.size()){
            int j=1;
            while(i<a.size() and a[i]==a[i+j]){
                j+=1;
            }

            ans.push_back(j+48);
            ans.push_back(a[i]);
            i+=j;
        }

        return ans;

    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    Solution o;
    cout<<o.countAndSay(n)<<endl;
    return 0;
}