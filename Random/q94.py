# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode):

        def rec(root : TreeNode,l):
            if(root!=None):
                rec(root.left,l)
                l.append(root.val)
                rec(root.right,l)

        l = []
        rec(root,l)
        return l