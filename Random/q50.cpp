#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    double myPow(double x, int n) {

        if(n==0)
            return 1;

        if(x==0)
            return 0;

        if(n==INT32_MAX){
            if(x>0){
                if(x>1)
                    return INT32_MAX;
                if (x==1)
                    return 1;
                else
                    return 0;
            }
            else{
                if(x<-1)
                    return INT32_MIN;
                if(x==-1)
                    return -1;
                else
                    return 0;
            }
        }

        if(n==INT32_MIN){
            if(x>0){
                if(x>1)
                    return 0;
                if (x==1)
                    return 1;
                else
                    return INT32_MAX;
            }
            else{
                if(x<-1)
                    return 0;
                if(x==-1)
                    return 1;
                else
                    return INT32_MAX;
            }
        }

        
        if(n!=abs(n))
            x = 1/x;
        n=abs(n);
        double left = 1;
        while(n>1){
            if(n&1){
                left*=x;
            }
            x*=x;
            n/=2;
        }
        return x*left;
    }
};

int main(int argc, char const *argv[])
{
    double x;
    cin>>x;

    int n;
    cin>>n;

    Solution o;
    cout<<o.myPow(x,n)<<endl;
    
    return 0;
}