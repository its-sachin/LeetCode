#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for (int i = 0; i < address.size(); i++){
            
            if(address[i]=='.'){
                ans.push_back('[');
                ans.push_back('.');
                ans.push_back(']');
            }
            else{
                ans.push_back(address[i]);
            }
            
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}