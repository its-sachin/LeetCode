#include<bits/stdc++.h>
#include<math.h>  

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int divide(int dividend, int divisor) {

        long long int t=1;
        int sign=1;
        if(signbit(dividend) != signbit(divisor))
            sign=-1;
        
        long long di=abs(dividend);
        long long div=abs(divisor);
        long long ans=0,temp=0;
        
        for(int i=31;i>=0;i--)
        {    
            if(temp+(div<<i)<=di)
            {
                ans=ans+ (t<<i);
                temp=temp+(div<<i); 
                
            }
        
        }
        if(sign==-1)
            ans=ans*(-1);
        if(ans>INT_MAX || ans<INT_MIN)
            return INT_MAX;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    int a;
    cin>>a;
    
    Solution o;
    cout<<o.divide(n,a)<<endl;
    return 0;
}