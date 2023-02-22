/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        if(p->val == root->val || q->val==root->val)return root;
        TreeNode*left=NULL;
        TreeNode*right=NULL;
        left=lowestCommonAncestor(root->left,p,q);
        right=lowestCommonAncestor(root->right,p,q);
        
        if(!left and right)return right;
        if(left and !right)return left;
        if(left and right)return root;
        
        return NULL;
        
        
    }
};