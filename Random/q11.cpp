#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i=0;
        int j = height.size()-1;

        while(i<j){
            int h = min(height[i],height[j]);
            ans = max(ans,(j-i)*h);
            while(i<height.size() and height[i]<=h)
                i++;

            while(j>=0 and height[j]<=h)
                j--;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {2,1};
    Solution o;
    cout<<o.maxArea(v)<<endl;
    
    return 0;
}
