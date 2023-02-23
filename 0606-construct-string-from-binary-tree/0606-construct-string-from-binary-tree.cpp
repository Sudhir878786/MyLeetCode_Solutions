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
    string func(TreeNode*root)
    {
         if(!root)return "" ;
        string s="";
        s+=to_string(root->val);
        if(root->left){
            s+="(";
            s+=func(root->left);
            s+=")";
        }
        if(root->right){
            if(!root->left)
            {
                s+="()";
            }
            s+="(";
            s+=func(root->right);
            s+=")";
        }
        return s;
        
    }
    string tree2str(TreeNode* root) {
       
        return func(root);
        
    }
};