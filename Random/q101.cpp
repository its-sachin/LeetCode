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

    bool check(TreeNode* a, TreeNode* b){
        if(!a and !b)
            return true;
        else if (!a or !b)
            return false;

        else if (a->val != b->val)  
            return false;
        
        return check(a->left,b->right)&&check(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {

        if(root)
            return check(root->left,root->right);
        return true;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(2);
    TreeNode* d = new TreeNode(2);
    TreeNode* e = new TreeNode(2);

    a->left=b;
    a->right=c;
    b->left=d;
    c->left=e;

    Solution o;
    cout<<o.isSymmetric(a)<<endl;
    return 0;
}