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
    
        
    bool hasPathSum(TreeNode* root, int k) {
        if(!root)return false;
        if(root->val==k and root->right==NULL and root->left==NULL)return true;
        return (hasPathSum(root->left,k-root->val) || hasPathSum(root->right,k-root->val));
        
    }
};