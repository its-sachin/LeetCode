#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back


class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int B) {
        
        vector<int> v;
        int c = 0;
        for (int i = 0; i < A.size(); i++){

            if(A[i]&1){
                v.push_back(i);
            }
        }

        if(v.size()==0){
            if(B!=0) return 0;

            return pow(2,A.size())-1;
        };
        if(v.size()==1){
            if(B>1) return 0;
            return (v[0])*(A.size()-v[0]);
        }

        int i=0;
        int j=B-1;
        if(j>=v.size()) return 0;

        c=0;
        while(j<v.size()){
            int i1=-1;
            if(i>0) i1= v[i-1];
            int j1 = A.size();
            if(j!=v.size()-1) j1=v[j+1];
            c+= (v[i]-i1)*(j1-v[j]);
            i+=1;
            j+=1;
        }
        return c;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}