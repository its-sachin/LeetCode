#include <iostream>

using namespace std;

class Solution {
public:
    static int myAtoi(string s) {
        int sign = 1;
        int num = 0;
        int i = 0;
        while(i<s.size() && s[i] == ' '){
            i++;
        }
        if (s[i] == '-' || s[i] == '+'){
            if (s[i] == '-'){
                sign*=-1;
            }
            i+=1;
        }

        while(i<s.size() && s[i] >47 && s[i] <58){
            if (sign == 1 && (num > INT32_MAX/10 || (num == INT32_MAX/10 && int(s[i]) >= 55))){
                return INT32_MAX;
            }
            if(sign == -1 && (num > INT32_MAX/10 || (num == INT32_MAX/10 && int(s[i]) >= 56))){
                return INT32_MIN;
            }
            num = 10*num + (int(s[i])-48);
            i+=1;
        }
        
        return num;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    cout<< a.myAtoi("-2147483648")<<endl;
    return 0;
}
