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
        if(!root)return nullptr;
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        TreeNode* left=NULL;
        TreeNode*right=NULL,ans=NULL;
        left=lowestCommonAncestor(root->left,p,q);
        right=lowestCommonAncestor(root->right,p,q);
        if(left and right==NULL){
            return left;
        }
        else if(right and left==NULL){
            return right;
        }
        else if(right and left){
            return root;
        }
        return nullptr;
    }
};