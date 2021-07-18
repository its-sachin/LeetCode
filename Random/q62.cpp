#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < n; i++){
        
            dp[m-1][i] =1;
        }

        for (int i = 0; i < m; i++){
        
            dp[i][n-1] =1;
        }

        for (int i = m-2; i >=0; i--){
        
            for (int j = n-2; j>=0; j--){
            
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};

int main(int argc, char const *argv[])
{
    Solution o;
    int n;
    cin>>n;
    
    int m;
    cin>>m;
    
    cout<<o.uniquePaths(n,m)<<endl;
    return 0;
}