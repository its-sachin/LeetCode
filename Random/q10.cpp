#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    bool isMatch(string A, string B) {
        vector<pair<char,bool>> C;

        int i=0;
        while(i<B.size()){
            
            if(B[i]=='*'){
            
                C[C.size()-1].second = true;
            }
            else{
                C.push_back({B[i],false});
            }

            i+=1;
        }


        bool dp[A.size()+1][C.size()+1];
        memset(dp,false,(A.size()+1)*(C.size()+1)*sizeof(bool));

        dp[0][0]=true;
        for (int i = 1; i < A.size(); i++){
            dp[i][0]=false;   
        }

        for (int i = 1; i <= C.size(); i++){
        
            if(!C[i-1].second){
                while(i<=C.size()){
                    dp[0][i]=false;
                    i+=1;
                }
            }
            else{
                dp[0][i]=true;
            }
        }

        for (int i = 1; i <= A.size(); i++){
        
            for (int j = 1; j <= C.size(); j++){

            
                if(!C[j-1].second){
                    if(C[j-1].first != '.' and  A[i-1]!=C[j-1].first)
                        dp[i][j] = false;
                    else
                        dp[i][j] =dp[i-1][j-1];
                }
                else{
                    if(C[j-1].first == '.' or C[j-1].first == A[i-1])
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    else
                        dp[i][j] = dp[i][j-1];
                }
            }
        }
        if(dp[A.size()][C.size()])
            return 1;
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}