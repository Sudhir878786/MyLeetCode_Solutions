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
    // approach   we have mark each level in index  from 0->n   and if index is even means store from left to right   else right to left
    void func(TreeNode*root,vector<vector<int>>&ans,int l)
    {
        if(!root)return;
        vector<int>cur;
        if(l>=ans.size()){
            ans.push_back(cur);
        }
        ans[l].push_back(root->val);
        func(root->left,ans,l+1);
        func(root->right,ans,l+1);
        
        
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        func(root,ans,0);
        for(int i=1;i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};