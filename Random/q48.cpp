#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int k = 0; k <n/2; k++){
        
            for (int j = k; j < n-1-k; j++){
            
                int t = matrix[k][j];
                matrix[k][j] = matrix[n-1-j][k];
                matrix[n-1-j][k] = matrix[n-1-k][n-1-j];
                matrix[n-1-k][n-1-j] = matrix[j][n-1-k];
                matrix[j][n-1-k] = t;
                
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> a = {
        {1,2,3,12},
        {4,5,6,11},
        {7,8,9,10},
        {13,14,15,16}
    };

    Solution o;
    o.rotate(a);

    for (int i = 0; i < a.size(); i++){
    
        for (int j = 0; j < a[i].size(); j++){
        
            cout<<a[i][j]<<" ";    
        }
        cout<<""<<endl;

    }
    return 0;
}