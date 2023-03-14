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
    TreeNode*ans;
    int geth(TreeNode*root)
    {
        if(!root)return 0;
        int a=geth(root->left);
        int b=geth(root->right);
        return max(a,b)+1;
        
    }
    bool solve(TreeNode*root,int h)
    {
        
        if(h==0)return 1;
        if(!root)return 0;
        bool l=solve(root->left,h-1);
        bool r=solve(root->right,h-1);
        if(l and r){
            ans=root;
            // cout<<ans->val<<endl;
        }
        return l or r;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)return NULL;
        
        int h=geth(root);
        // cout<<h<<endl;
        solve(root,h);
        return ans;
    }
};