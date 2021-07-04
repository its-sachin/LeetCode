#include <iostream>
#include <vector>

using namespace std;

string lcSubstrPrint(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();

    int dp[n+1][m+1];

    for(int i=0; i<=n; i++){
        dp[i][0]=0;
    }
    for(int i=1; i<=m; i++){
        dp[0][i]=0;
    }

    pair<int,int> dest = {0,0};
    for (int i=1; i<=n; i++){
        for (int j=1; j <=m; j++){
        
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                if(dp[dest.first][dest.second]<dp[i][j]){
                    dest = {i,j};
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    string ans = "";
    int i=dest.first;
    int j=dest.second;

    while(i>0 and j>0){
        if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i-=1;
            j-=1;
        }
        else{
            break;
        }
    }

    i=0;
    j=ans.size()-1;

    while(i<j){
        swap(ans[i],ans[j]);
        i+=1;
        j-=1;
    }
    return ans;
}

int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int l = paths.size();
        vector<string> path;
        for (int i = 0; i < l; i++){
            string a;
            for(int j=0;j<paths[i].size();j++){
                char c= '0'+paths[i][j];
                a.push_back(c);
            }
            path.push_back(a);
        }

        string s = path[0];
        int len = s.size();

        string res = "";

        for (int i = 0; i < len; i++) {
            for (int j = 1; j <= len-i; j++) {
                string stem = s.substr(i, j);
                int k = 1;
                for (k = 1; k < l; k++) {
                    if (path[k].find(stem) == std::string::npos)
                        break;
                }

                if (k == l && res.length() < stem.length())
                    res = stem;
            }
        }   
        return res.length();

    }

int main(int argc, char const *argv[])
{

    return 0;
}