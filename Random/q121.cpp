#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> v;
        for (int i = 0; i < prices.size()-1; i++){
        
            v.push_back(prices[i+1]-prices[i]);
        }

        int sum=0;
        int ans=0;
        for (int i = 0; i < prices.size()-1; i++){
        
            sum+=v[i];
            if(sum<0)
                sum=0;
            ans=max(sum,ans);
        }
        return ans;
        
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}