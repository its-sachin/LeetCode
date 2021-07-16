#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* A, TreeNode* B) {
        if(A==NULL) return B;
        if(B==NULL) return A;

        TreeNode* c = new TreeNode(A->val+B->val);
        c->left = mergeTrees(A->left,B->left);
        c->right = mergeTrees(A->right,B->right);
        return c;
        
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}