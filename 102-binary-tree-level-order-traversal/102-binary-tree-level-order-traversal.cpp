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
     vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
		
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> temp;  // for row
        int size, i;
        TreeNode* curr;
        
        q.push(root);
        
        while (!q.empty()) {
            temp = {};
            size = q.size();
            
            for (i = 0; i < size; i++) {
                
                curr = q.front();
                q.pop();
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                
                temp.push_back(curr->val);
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};