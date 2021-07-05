#include<bits/stdc++.h>

using namespace std;


#define inf 1e18
#define mod 1000000007
#define pb push_back
#define fo(i,n) for(int i=0; i<n; i++)
#define fe(i,n) for(int i=0; i<=n; i++)
#define fi(i,n,k) for(int i=k; i<n; i++)

class Solution {
public:
    int minPartitions(string n) {
        int ans = -1;
        fo(i,n.size()){
            if(n[i]-48>ans)
                ans = n[i]-48;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}