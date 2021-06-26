#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxSoFar = 0;
        int maxI = 0;
        int maxArea = INT32_MIN;

        int i=1;
        for (int x: height){
            if (x>maxSoFar){
                maxArea = max((i-maxI)*maxSoFar,maxArea);
                maxSoFar=x;
                maxI=i;
            }
            else{
                maxArea = max((i-maxI)*x,maxArea);
            }
            i+=1;
        }
        return maxArea;
    }
};