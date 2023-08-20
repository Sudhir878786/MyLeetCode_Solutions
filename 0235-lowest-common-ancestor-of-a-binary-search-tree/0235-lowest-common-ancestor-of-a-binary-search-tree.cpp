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
        if(!root){
            return NULL;
        }
        if(p->val==root->val || q->val==root->val){
            return root;
        }
        TreeNode*l=NULL,*r=NULL;
        l=lowestCommonAncestor(root->left,p,q);
        r=lowestCommonAncestor(root->right,p,q);
        if(l and r){
            return root;
        }else if(!r and l){
            return l;
        }else if(r and !l){
            return r;
        }
        return NULL;
    }
};