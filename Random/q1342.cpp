#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int numberOfSteps(int num) {
        int k=0;
        while(num>0){
            if(num%2==0)
                num=num/2;
            else
                num-=1;
            k+=1;
        }
        return k;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}