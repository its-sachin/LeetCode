#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        char a[s.size()];

        for (int i = 0; i < s.size(); i++){
        
            a[indices[i]] = s[i];
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++){
        
            ans.push_back(a[i]);
        }

        return ans;

    }
};

int main(int argc, char const *argv[])
{
    return 0;
}