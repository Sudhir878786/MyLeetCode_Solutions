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
    int ans=0;
    void func(TreeNode*root,bool left, int l)
    {
        if(!root)return ;
        ans=max(ans,l);
        if(left){
            func(root->left,false,l+1);
            func(root->right,true,1);
        }
        else{
            func(root->left,false,1);
            func(root->right,true,l+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root)return 0;
        func(root,false,0);
        func(root,true,0);
        return ans;
    }
};