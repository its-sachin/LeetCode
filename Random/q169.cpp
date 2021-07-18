#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int majorityElement(vector<int>& A) {
        if(A.size()==0)
        return 0;

    int ans = A[0];
    int c=1;
    for (int i = 1; i < A.size(); i++){

        if(ans==A[i])
            c+=1;
        else
            c-=1;

        if(c==0){
            ans=A[i];
            c=1;
        }
    }
    return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}