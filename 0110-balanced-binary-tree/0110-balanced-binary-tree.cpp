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
    int solve(TreeNode*root)
    {
        if(!root )return 1;
        int lef=solve(root->left);
        int righ=solve(root->right);
        return (1+max(lef,righ)); 
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return 1;
         int lf=solve(root->left);
        int rh=solve(root->right);
        if(abs(lf-rh)<=1 and isBalanced(root->left) and isBalanced(root->right) )return 1;
        return 0;
        
    }
};