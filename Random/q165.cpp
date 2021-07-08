#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,n1=0,n2=0;

        int n=version1.size();
        int m=version2.size();

        while(i<n or j<m){

            while(i<n and version1[i]!='.'){
                n1=n1*10+int(version1[i])-48;
                i++;
            }

            while(j<m and version2[j]!='.'){
                n2=n2*10+int(version2[j])-48;
                j++;
            }

            if(n1<n2) return -1;
            if(n2<n1) return 1;

            n1=0;
            n2=0;
            i++;
            j++;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    string a,b;
    cin>>a>>b;
    Solution o;
    cout<<o.compareVersion(a,b)<<endl;
    return 0;
}