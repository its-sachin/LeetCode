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

    pair<bool,pair<int,int>> check(TreeNode* A){
        if(A->left){
            if(A->right){

                pair<bool,pair<int,int>> p = check(A->left);
                if(!p.first or A->val<=A->left->val or A->val<=p.second.second)
                    return {false,{-1,-1}};

                pair<bool,pair<int,int>> q = check(A->right);
                if(!q.first or A->val>=A->right->val or A->val>=q.second.first)
                    return {false,{-1,-1}};

                return {true,{p.second.first,q.second.second}};
            }
            else{
                pair<bool,pair<int,int>> p = check(A->left);
                if(!p.first or A->val<=A->left->val or A->val<=p.second.second)
                    return {false,{-1,-1}};

                return {true,{p.second.first,A->val}};
            }   
        }
        else{
            if(A->right){
                pair<bool,pair<int,int>> p = check(A->right);
                if(!p.first or A->val>=A->right->val or A->val>=p.second.first)
                    return {false,{-1,-1}};

                return {true,{A->val,p.second.second}};
            }
            else{
                return {true,{A->val,A->val}};
            }

        }
    }

    bool isValidBST(TreeNode* A) {
        pair<bool,pair<int,int>> p = check(A);
        return p.first;
    }
};



int main(int argc, char const *argv[])
{
    return 0;
}
            