#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    bool isMatch(string A, string B) {
        bool dp[A.size()+1][B.size()+1];
        memset(dp, false, sizeof(dp));

        dp[0][0]=true;

        for (int j = 1; j <= B.size(); j++)
            if (B[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];

        for (int i = 1; i <= A.size(); i++){

            for (int j = 1; j <= B.size(); j++){

                if(B[j-1]=='*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else if(B[j-1]=='?' or A[i-1]==B[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j]=false;

                }
            }
        }
        return dp[A.size()][B.size()];
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}