#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:

    double three(int a, int b, int c){
        return a + b + c - max(a, max(b, c))- min(a, min(b, c));
    }

    double single(int nums2[], int m){
        if(m==0)
            return 0;
        if(m&1)
            return nums2[m/2];
        return (double)(nums2[(m/2)-1]+nums2[m/2])/2;
    }

    double four(int a, int b, int c, int d){

        int Max = max( a, max( b, max( c, d ) ) );
        int Min = min( a, min( b, min( c, d ) ) );
        return ( a + b + c + d - Max - Min ) / 2.0;
    }

    double findRec(int nums1[], int n, int nums2[], int m){
    
        if(n==0){
            return single(nums2,m);
        }

        if(n==1){
            if(m==1)
                return (double)(nums1[0]+nums2[0])/2;
            if (m & 1)
                return (double) (nums2[m/2]+ three(nums1[0], nums2[m/2 - 1], nums2[m/2 + 1]) )/2;
            else  return three( nums2[m/2], nums2[m/2 - 1], nums1[0] );
        }

        else if (n == 2){
            if (m == 2)
                return four(nums1[0], nums1[1], nums2[0], nums2[1]);
    
            if (m & 1)
                return three ( nums2[m/2], max(nums1[0], nums2[m/2 - 1]), min(nums1[1], nums2[m/2 + 1]));

            return four( nums2[m/2], nums2[m/2 - 1], max( nums1[0], nums2[m/2 - 2] ), min( nums1[1], nums2[m/2 + 1] ) );
        }
    
        int idxA = (n - 1) / 2;
        int idxB = (m - 1) / 2;

        if (nums1[idxA] <= nums2[idxB] )
            return findRec(nums1 + idxA, n/2 + 1, nums2, m - idxA );
    

        return findRec(nums1, n/2 + 1, nums2 + idxA, m - idxA );

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size())
            swap(nums1,nums2);
        int a[nums1.size()];
        for (int i = 0; i < nums1.size(); i++){
        
            a[i]=nums1[i];
        }

        int b[nums2.size()];
        for (int i = 0; i < nums2.size(); i++){
        
            b[i]=nums2[i];
        }

        return findRec(a,nums1.size(),b,nums2.size());
    }   

    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size()>nums2.size())
            swap(nums1,nums2);

        int n = nums1.size();
        int m = nums2.size();

        if(n==0){
            if(m==0)
                return 0;
            if(m&1)
                return nums2[m/2];
            return (nums2[(m/2)-1]+nums2[m/2])/2.0;
        }

        int l=0;
        int r=n;

        while(l<=r){
            int mid = l+(r-l)/2;
            int k = (n+m+1)/2 - mid;

            if(mid<n and nums2[k-1]>nums1[mid])
                r=mid-1;
            else if(mid>0 and nums1[mid-1]>nums2[k])
                l=mid+1;

            else{
                int left;
                if(mid==0)
                    left = nums2[k-1];
                else if (k==0)
                    left = nums1[mid-1];
                else
                    left = max(nums1[mid-1],nums2[k-1]);

                if((n+m)&1)
                    return left;

                int right;
                if(mid==n)
                    right = nums2[k];
                else if (k==m)
                    right = nums1[mid];
                else
                    right = min(nums1[mid],nums2[k]);
                return (left+right)/2.0;
            }
        }

    }

};

int main(int argc, char const *argv[])
{
    vector<int> a = {3};
    vector<int> b = {1,2,4};

    Solution o;
    cout<<o.findMedianSortedArrays(a,b)<<endl;
    
    return 0;
}

