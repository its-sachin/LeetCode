#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            vector<int>& a = nums1;
            nums1 = nums2;
            nums2 = a;
        }

    }
};
