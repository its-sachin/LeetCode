#include<bits/stdc++.h>

using namespace std;

typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> u;
        for (int i = 0; i < jewels.size(); i++){
        
            if(u.find(jewels[i])==u.end())
                u.insert({jewels[i],i});            
        }

        int ans=0;
        for (int i = 0; i < stones.size(); i++){
        
            if(u.find(stones[i]) != u.end())
                ans++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}