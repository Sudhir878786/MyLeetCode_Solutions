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
    vector<string>ans;
     void solve(TreeNode *root, string s)
        {
           	// if the current node is not having either a left or a right then we are 
           	// done with one root to leaf path so we push it into the answer
            if (!root->left && !root->right)
            {
                ans.push_back(s);
                return;
            }

           	// we move towards either left of the root or right of the root, whichever
           	// suitable adding the current node's value to the string and moving ahead
           	// this addition to our string goes on until we find our base condition break
            if (root->left) solve(root->left, s + "->" + to_string(root->left->val));
            if (root->right) solve(root->right, s + "->" + to_string(root->right->val));
        }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        // vector<string> ans;
        if (!root) return ans;
       	// we make the value of our root node as a string
        string s = to_string(root->val);
        solve(root, to_string(root->val));
        return ans;
    }
};