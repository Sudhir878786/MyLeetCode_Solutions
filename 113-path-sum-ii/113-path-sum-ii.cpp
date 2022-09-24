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
    void solve(TreeNode* root,vector<vector<int>> &ans,vector<int>&row, int k)
    {
        if(!root)return ;
        row.push_back(root->val);
        if(!root->left and !root->right and k== root->val) ans.push_back(row);
      
            solve(root->left,ans,row,k-root->val);
            solve(root->right,ans,row,k-root->val);
            row.pop_back();
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        vector<vector<int>>ans;
        vector<int>row;
        solve(root,ans,row,k);
        return ans;
        
    }
};