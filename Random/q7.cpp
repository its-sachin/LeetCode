#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string a = to_string(x);
        string ans = "";
        for (int i=a.size()-1; i>=0; i--){
            ans += a[i];
        }
        long ansI = stol(ans);
        if (x<0){
            ansI = -1*ansI;
        }
        if (ansI<-2147483648 || ansI > 2147483647){
            return 0;
        }
        return ansI;
    }
};