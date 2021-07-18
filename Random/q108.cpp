#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    
public:
    
    TreeNode* rec(vector<int>& nums, int l, int r){
        if(l<=r){
            int mid = l+(r-l)/2;
            TreeNode* k = new TreeNode(nums[mid]);
            TreeNode* left = rec(nums,l,mid-1);
            TreeNode* right = rec(nums,mid+1,r);
            k->left=left;
            k->right=right;
            return k;
        }
        return nullptr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return rec(nums,0,nums.size()-1);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}