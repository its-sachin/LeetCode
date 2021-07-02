#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<int> a;
        for(int i=0;i<s.size();i++){

            switch (int(s[i]))
            {
            case 40:
                a.push(40);
                break;

            case 41:
                if(a.size()!=0 and a.top()==40)
                    a.pop();
                else
                    return false;
                break;

            case 123:
                a.push(123);
                break;

            case 125:
                if(a.size()!=0 and a.top()==123)
                    a.pop();
                else
                    return false;
                break;

            case 91:
                a.push(91);
                break;

            case 93:
                if(a.size()!=0 and a.top()==91)
                    a.pop();
                else
                    return false;
                break;
            
            default:
                return false;
            }

            
        }
        return a.size()==0;
    }
};


int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    
    Solution a;
    cout<<a.isValid(s)<<endl;
    return 0;
}