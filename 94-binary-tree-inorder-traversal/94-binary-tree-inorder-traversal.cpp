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
    vector<int>ans;
    void solve(TreeNode* root)
    {
        vector<int>tem(3,0);
        if(!root){
            return;
        }
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        
       
        return ans;
    }
};