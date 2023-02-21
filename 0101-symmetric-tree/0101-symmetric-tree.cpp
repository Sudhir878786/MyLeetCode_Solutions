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
    bool func(TreeNode*p,TreeNode*q)
    {
        if(p==NULL and q==NULL)return 1;
        if(p==NULL || q==NULL)return 0;
        if(p->val!=q->val)return 0;
        return (func(p->left,q->right) and func(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return 1;
        return func(root->left,root->right);
        
    }
};