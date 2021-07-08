#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int subtractProductAndSum(int n) {
        
        long int sum=0;
        long int prod = 1;

        while(n>0){
            int k=n%10;
            sum+=k;
            prod*=k;
            n=n/10;
        }
        return prod-sum;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}