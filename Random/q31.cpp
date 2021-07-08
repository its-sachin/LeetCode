#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back


class Solution {
public:
    void nextPermutation(vector<int>& A) {

        int k= A.size()-2;
        while(k>=0){
            if(A[k+1]>A[k])
                break;
            k-=1;
        }

        if(k<0){
            sort(A.begin(),A.end());
        }

        else{

            int j=k;
            while(j<A.size()-1){
                if(A[j+1]<=A[k]){
                    break;
                }
                j++;
            }

            swap(A[k],A[j]);
            sort(A.begin()+k+1,A.end());
        } 
        
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}